#include "AbstractCreator.h"

AbstractCreator::AbstractCreator(Sudoku& sud, Evaluator& e, AbstractPresenter& p, AbstractSolver& sol) : sudoku(sud), evaluator(e), presenter(p), solver(sol)
{

}

void AbstractCreator::lockSudoku(const string& pattern) {
    for(size_t pos=0;pos<pattern.length();pos++) {
        if (pattern[pos]=='1') {
            sudoku.lockValue(pos%COLUMNS,pos/ROWS);
        } else {
            sudoku.unlockValue(pos%COLUMNS,pos/ROWS);
            sudoku.setValue(pos%COLUMNS,pos/ROWS,0);
        }
    }
}
