#include "SeedCreator.h"

SeedCreator::SeedCreator(Sudoku& sud, Evaluator& e, AbstractPresenter& p, AbstractSolver& sol) : AbstractCreator(sud,e,p,sol)
{

}

void SeedCreator::create(Evaluator::DIFFICULTY difficulty) {
    string pattern;
    switch(difficulty) {
    case Evaluator::Medium:
        pattern = EASY_SEED;
        break;
    case Evaluator::Hard:
        pattern = MEDIUM_SEED;
        break;
    case Evaluator::Samurai:
        pattern = HARD_SEED;
        break;
    case Evaluator::Easy:
    default:
        pattern = SAMURAI_SEED;
        break;
    }

    do { // loop for uniqueness constraint
        array<int,10> base = {0,1,2,3,4,5,6,7,8,9};
        unsigned seed = chrono::system_clock::now().time_since_epoch().count();
        shuffle (base.begin(), base.end(), default_random_engine(seed));

        //apply token randomization
        for(char& c:pattern) {
            if (c!='.') {
                c = base[c-'0']+'0';
            }
        }

        sudoku.fromString(pattern);
    } while (!solver.solve(true));

    sudoku.fromString(pattern);
    presenter.printSudoku(sudoku, 0, 0, 0, true);
}
