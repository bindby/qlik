#ifndef SEEDCREATOR_H
#define SEEDCREATOR_H

#include "AbstractCreator.h"

#define EASY_SEED "51.....838..416..5..........985.461....9.1....642.357..........6..157..478.....96"
#define MEDIUM_SEED "7...9...32..468..1..8...6...4..2..9....3.4....8..1..3...9...7..5..142..68...5...2"
#define HARD_SEED ".523..6..6...4...3............63..1.47.....35.2..58............1...9...6..5..172."
#define SAMURAI_SEED "5.....1.7..43..5.....2...8..9.4.2...4.......6...1.3.5..8...4.....2..67..3.9.....1"

class SeedCreator : AbstractCreator
{
public:
public:
    SeedCreator(Sudoku& sud, Evaluator& e, AbstractPresenter& p, AbstractSolver& sol);
    void create(Evaluator::DIFFICULTY difficulty);
};

#endif // SEEDCREATOR_H
