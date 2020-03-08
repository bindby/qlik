#ifndef CANDIDATESOLVER_H
#define CANDIDATESOLVER_H

#include "AbstractSolver.h"

#define NINEBITS 0x3FE

class CandidateSolver : public AbstractSolver
{
private:
    int originalCandidates[SIZE];
    int currentCandidates[SIZE];

    void initializeCandidates();
    void findCandidates();
    int lockSingleCandidates();
    void removeCandidates();
    int popCandidate(int* i);
    int numberCandidates(const int& i);
    void onset();

public:
    CandidateSolver(Sudoku& s, Evaluator& e, AbstractPresenter& p);
    bool solve(bool checkUnique = false);
};

#endif // CANDIDATESOLVER_H
