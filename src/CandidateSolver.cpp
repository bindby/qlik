#include "CandidateSolver.h"

CandidateSolver::CandidateSolver(Sudoku& s, Evaluator& e, AbstractPresenter& p) : AbstractSolver(s,e,p)
{
    memset(originalCandidates, 0, sizeof(originalCandidates));
    memset(currentCandidates, 0, sizeof(currentCandidates));
}

int CandidateSolver::popCandidate(int* i) {
    for(int pos=1;pos<=COLUMNS;pos++) {
        if (*i & 1<<pos) {
            *i ^= 1<<pos;
            return pos;
        }
    }
    return EMPTY;
}

int CandidateSolver::numberCandidates(const int& i) {
    int count = 0;
    for(int pos=1;pos<=COLUMNS;pos++) {
        if (i & 1<<pos) {
            count++;
        }
    }
    return count;
}

int CandidateSolver::lockSingleCandidates() {
    int count = 0;
    for(int pos=0;pos<SIZE;pos++) {
        if (numberCandidates(originalCandidates[pos])==1 && !sudoku.getLock(COL(pos), ROW(pos))) {
            count++;
            sudoku.setValue(COL(pos), ROW(pos), popCandidate(&originalCandidates[pos]));
            sudoku.lockValue(COL(pos), ROW(pos));
        }
    }
    return count;
}

void CandidateSolver::initializeCandidates() {
    for(int pos=0;pos<SIZE;pos++) {
        originalCandidates[pos] = NINEBITS;
        currentCandidates[pos] = NINEBITS;
    }
}

void CandidateSolver::removeCandidates() {
    int rowTakenMasks[ROWS] = {0};
    int columnTakenMasks[COLUMNS] = {0};
    int sectorTakenMasks[SECTORS] = {0};

    bool ok = false;
    for(int pos=0;pos<9;pos++) {
        rowTakenMasks[pos] = evaluator.getRowMask(pos, ok);
        columnTakenMasks[pos] = evaluator.getColumnMask(pos, ok);
        sectorTakenMasks[pos] = evaluator.getSectorMask( (pos*3)%9, (pos/3)*3, ok);
    }

    for(int pos=0;pos<SIZE;pos++) {
        originalCandidates[pos] &= ~sectorTakenMasks[SECTOR(pos)];
        originalCandidates[pos] &= ~rowTakenMasks[ROW(pos)];
        originalCandidates[pos] &= ~columnTakenMasks[COL(pos)];
    }

    //TODO hidden singles, and more
}

void CandidateSolver::findCandidates() {
    int count = 0;
    do {
        removeCandidates();
        count = lockSingleCandidates();
    } while (count>0);
}


void CandidateSolver::onset() {
    //skip already locked positions in this direction
    while(sudoku.getLock(currentColumn, currentRow)) {
        step();
        if ( currentDirection  == Halt) {
            return;
        }
    }

    //try next candidate
    int candidate = popCandidate(&currentCandidates[POS(currentColumn,currentRow)]);
    while(candidate != EMPTY) {
        iterations++;
        sudoku.setValue(currentColumn, currentRow, candidate);
        if ( evaluator.isColumnOk(currentColumn) && evaluator.isRowOk(currentRow) && evaluator.isSectorOk(currentColumn,currentRow) ) {
            currentDirection = Forward;
            return;
        }
        candidate = popCandidate(&currentCandidates[POS(currentColumn,currentRow)]);
    }

    //backtrack
    sudoku.setValue(currentColumn, currentRow, EMPTY);
    currentCandidates[POS(currentColumn,currentRow)] = originalCandidates[POS(currentColumn,currentRow)];
    currentDirection  = Back;
}

bool CandidateSolver::solve(bool checkUnique) {
    initializeCandidates();
    findCandidates();
    return solveWithBacktrack(checkUnique);
}
