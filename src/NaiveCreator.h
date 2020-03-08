#ifndef NAIVECREATOR_H
#define NAIVECREATOR_H

#include "AbstractCreator.h"

class NaiveCreator : AbstractCreator
{
public:
    NaiveCreator(Sudoku& sud, Evaluator& e, AbstractPresenter& p, AbstractSolver& sol);
    void create(Evaluator::DIFFICULTY difficulty);
};

#endif // NAIVECREATOR_H
