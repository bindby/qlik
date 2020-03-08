#ifndef ABSTRACTSOLVER_H
#define ABSTRACTSOLVER_H

#include "Sudoku.h"
#include "Evaluator.h"
#include "AbstractPresenter.h"

class AbstractSolver
{
protected:
    enum DIRECTION {Back, Forward, Halt};
    Sudoku& sudoku;
    Evaluator& evaluator;
    AbstractPresenter& presenter;
    int currentRow;
    int currentColumn;
    int iterations;
    DIRECTION currentDirection;

    void step();
    bool solveWithBacktrack(bool checkUnique);
    virtual void onset() = 0;

public:
    AbstractSolver(Sudoku& s, Evaluator& e, AbstractPresenter& p);
    virtual bool solve(bool checkUnique = false) = 0;
    int getIterations() { return iterations;};
};

#endif // ABSTRACTSOLVER_H
