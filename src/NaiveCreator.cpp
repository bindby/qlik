#include "NaiveCreator.h"

NaiveCreator::NaiveCreator(Sudoku& sud, Evaluator& e, AbstractPresenter& p, AbstractSolver& sol) : AbstractCreator(sud,e,p,sol)
{

}

void NaiveCreator::create(Evaluator::DIFFICULTY difficulty) {
    string pattern;
    switch(difficulty) {
    case Evaluator::Medium:
        pattern = PATTERN_MEDIUM;
        break;
    case Evaluator::Hard:
        pattern = PATTERN_HARD;
        break;
    case Evaluator::Samurai:
        pattern = PATTERN_SAMURAI;
        break;
    case Evaluator::Easy:
    default:
        pattern = PATTERN_EASY;
        break;
    }

    do { // loop for uniqueness constraint
        sudoku.reset();
        presenter.printSudoku(sudoku, 0, 0, 0, false);

        array<int,9> base {1,2,3,4,5,6,7,8,9};
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();

        //generate full solvable board
        shuffle (base.begin(), base.end(), default_random_engine(seed));
        for(int i=0;i<9;i++) {
            sudoku.setValue(i,0,base[i]);
            sudoku.lockValue(i,0);
        }
        solver.solve(false);

        lockSudoku(pattern);

    } while (!solver.solve(true));

    lockSudoku(pattern);
    presenter.printSudoku(sudoku, 0, 0, 0, true);
}
