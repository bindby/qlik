#ifndef BRUTESOLVER_H
#define BRUTESOLVER_H

#include "AbstractSolver.h"

class BruteSolver : public AbstractSolver
{
private:
    void onset();

public:
    BruteSolver(Sudoku& s, Evaluator& e, AbstractPresenter& p);
    bool solve(bool checkUnique = false);
};

#endif // BRUTESOLVER_H
