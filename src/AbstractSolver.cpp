#include "AbstractSolver.h"

AbstractSolver::AbstractSolver(Sudoku& s, Evaluator& e, AbstractPresenter& p) : sudoku(s), evaluator(e), presenter(p)
{
    currentRow = 0;
    currentColumn = 0;
    iterations = 0;
}

void AbstractSolver::step() {
    int currentPos = POS(currentColumn, currentRow);
    currentDirection == Forward ? currentPos++ : currentPos--;
    currentColumn = COL(currentPos);
    currentRow = ROW(currentPos);
    if ( currentPos < 0 || currentPos > SIZE-1) {
        currentDirection = Halt;
    }
}

bool AbstractSolver::solveWithBacktrack(bool checkUnique) {
    currentRow = 0;
    currentColumn = 0;
    iterations = 0;
    bool solved = false;

    presenter.printSudoku(sudoku, currentColumn, currentRow, iterations, evaluator.isSolved());

    currentDirection = Forward;
    while(currentDirection!=Halt) {

        if ( iterations %1000 ==0) {
            presenter.printSudoku(sudoku, currentColumn, currentRow, iterations, false);
        }

        onset();
        if (currentDirection != Halt) {
            step();
        }
    }
    presenter.printSudoku(sudoku, currentColumn, currentRow, iterations, evaluator.isSolved());

    solved = evaluator.isSolved();
    bool unique = true;

    if (checkUnique) {
        //try to find secondary solution
        currentDirection = Back;
        currentRow = 8;
        currentColumn = 8;

        //step over locked positions in end to find first modifyable
        while(sudoku.getLock(currentColumn, currentRow) && currentDirection != Halt) {
            step();
        }
        if (currentDirection != Halt) {
            sudoku.setValue(currentColumn, currentRow, 0);
            currentDirection = Back;
            step();

            while(currentDirection!=Halt) {
                onset();
                if (currentDirection != Halt) {
                    step();
                }
            }
            unique = !evaluator.isSolved();
        }
    }

    return solved && unique;
}
