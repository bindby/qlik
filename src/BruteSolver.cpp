#include "BruteSolver.h"

BruteSolver::BruteSolver(Sudoku& s, Evaluator& e, AbstractPresenter& p) : AbstractSolver(s,e,p)
{
}

void BruteSolver::onset() {
    //skip already locked positions in this direction
    while(sudoku.getLock(currentColumn, currentRow)) {
        step();
        if ( currentDirection  == Halt) {
            return;
        }
    }

    //try increase
    for(int i=sudoku.getValue(currentColumn, currentRow);i<9;i++) {
        iterations++;
        sudoku.incValue(currentColumn, currentRow);
        if ( evaluator.isColumnOk(currentColumn) && evaluator.isRowOk(currentRow) && evaluator.isSectorOk(currentColumn,currentRow) ) {
            currentDirection = Forward;
            return;
        }
    }

    //backtrack
    sudoku.setValue(currentColumn, currentRow, 0);
    currentDirection  = Back;
}

bool BruteSolver::solve(bool checkUnique) {
    return solveWithBacktrack(checkUnique);
}
