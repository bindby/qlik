#ifndef SUDOKU_H
#define SUDOKU_H

#include <string.h> //memset
#include <fstream>
#include "globals.h"
#include <algorithm>

class Sudoku {
private:
    int original_table[COLUMNS][ROWS];
    int table[COLUMNS][ROWS];
    bool lock_mask[COLUMNS][ROWS];

public:
    Sudoku();
    int getLock(int column, int row) const { ;return lock_mask[column][row]; }
    int getValue(int column, int row) const { ;return table[column][row]; }
    void setValue(int column, int row, int value) { table[column][row] = value; }
    void incValue(int column, int row) { (table[column][row])++; }
    void lockValue(int column, int row) { lock_mask[column][row] = true; }
    void unlockValue(int column, int row) { lock_mask[column][row] = false; }
    void reset();
    bool fromString(string s);
    bool fromFile(string path);
};

#endif // SUDOKU_H
