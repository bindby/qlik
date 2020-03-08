#ifndef ABSTRACTCREATOR_H
#define ABSTRACTCREATOR_H

#include "AbstractSolver.h"
#include "Evaluator.h"
#include "AbstractPresenter.h"
#include <array>
#include <chrono>
#include <algorithm>
#include <random>
#include "AbstractSolver.h"

#define PATTERN_EASY    "110000011100111001000000000011101110000101000011101110000000000100111001110000011"
#define PATTERN_MEDIUM  "100010001100111001001000100010010010000101000010010010001000100100111001100010001"
#define PATTERN_HARD    "011100100100010001000000000000110010110000011010011000000000000100010001001001110"
#define PATTERN_SAMURAI "100000101001100100000100010010101000100000001000101010010001000001001100101000001"

class AbstractCreator
{
protected:
    Sudoku& sudoku;
    Evaluator& evaluator;
    AbstractPresenter& presenter;
    AbstractSolver& solver;

    void lockSudoku(const string& pattern);

public:
    AbstractCreator(Sudoku& sud, Evaluator& e, AbstractPresenter& p, AbstractSolver& sol);
    virtual void create(Evaluator::DIFFICULTY difficulty)=0;
};

#endif // ABSTRACTCREATOR_H
