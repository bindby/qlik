#include "Evaluator.h"

Evaluator::Evaluator(Sudoku& s) : sudoku(s)
{
}

//TODO very rough estimation, should include some analysis more than counting clues
Evaluator::DIFFICULTY Evaluator::getDifficulty() {
    int count = 0;
    for(int pos=0;pos<SIZE;pos++) {
        if (sudoku.getLock(COL(pos), ROW(pos))) {
            count++;
        }
    }

    if (count<25) {
        return Samurai;
    } else if (count<28) {
        return Hard;
    } else if (count<30) {
        return Medium;
    } else {
        return Easy;
    }
}


int Evaluator::getRowMask(int row, bool& errorFlag) {
    errorFlag = false;
    int row_mask = 0;
    for(int x=0;x<9;x++){
        if (sudoku.getValue(x,row) != 0 && row_mask & 1<<sudoku.getValue(x,row)) {
            errorFlag = true;
            return row_mask;
        } else {
            row_mask |= 1<<sudoku.getValue(x,row);
        }
    }
    return row_mask;
}

int Evaluator::getColumnMask(int column, bool& errorFlag) {
    errorFlag = false;
    int column_mask = 0;
    for(int y=0;y<9;y++){
        if (sudoku.getValue(column,y) != 0 && column_mask & 1<<sudoku.getValue(column,y)) {
            errorFlag = true;
            return column_mask;
        } else {
            column_mask |= 1<<sudoku.getValue(column,y);
        }
    }
    return column_mask;
}

int Evaluator::getSectorMask(int column, int row, bool& errorFlag) {
    errorFlag = false;
    int sector_mask = 0;
    int x_ofs = 3*(column/3);
    int y_ofs = 3*(row/3);
    for(int y=0+y_ofs;y<3+y_ofs;y++){
        for(int x=0+x_ofs;x<3+x_ofs;x++){
            if (sudoku.getValue(x,y) != 0 && sector_mask & 1<<sudoku.getValue(x,y)) {
                errorFlag = true;
                return sector_mask;
            } else {
                sector_mask |= 1<<sudoku.getValue(x,y);
            }
        }
    }
    return sector_mask;
}

bool Evaluator::isSectorOk(int row, int column) {
    bool error = false;
    getSectorMask(column, row, error);
    return !error;
}

bool Evaluator::isRowOk(int row) {
    bool error = false;
    getRowMask(row, error);
    return !error;
}

bool Evaluator::isColumnOk(int column) {
    bool error = false;
    getColumnMask(column, error);
    return !error;
}

bool Evaluator::isSolved() {
    for (int i=0;i<9;i++) {
        if (!isRowOk(i) || !isColumnOk(i) || !isSectorOk((3*i)%9, i/3)){
            return false;
        }
    }

    for (int row=0;row<9;row++) {
        for (int column=0;column<9;column++) {
            if (sudoku.getValue(column,row) == 0) {
                return false;
            }
        }
    }
    return true;
}
