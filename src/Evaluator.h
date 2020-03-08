#ifndef EVALUATOR_H
#define EVALUATOR_H

#include "Sudoku.h"

class Evaluator
{
private:
    Sudoku& sudoku;

public:
    enum DIFFICULTY {Easy, Medium, Hard, Samurai};

    Evaluator(Sudoku& sudoku);
    bool isRowOk(int row);
    bool isColumnOk(int column);
    bool isSectorOk(int column, int row);
    int getRowMask(int row, bool& errorFlag);
    int getColumnMask(int column, bool& errorFlag);
    int getSectorMask(int column, int row, bool& errorFlag);
    bool isSolved();
    DIFFICULTY getDifficulty();
};

#endif // EVALUATOR_H
