#ifndef ABSTRACTPRESENTER_H
#define ABSTRACTPRESENTER_H

#include "globals.h"
#include "Sudoku.h"

class AbstractPresenter
{
protected:
    string title;
public:
    AbstractPresenter();
    AbstractPresenter(string title);
    void setTitle(string s) { title = s;};
    virtual void printError(string s) = 0;
    virtual void printSudoku(const Sudoku& sudoku) = 0;
    virtual void printSudoku(const Sudoku& sudoku, int x, int y, int iterations, bool complete) = 0;
    virtual void waitForKeyPress() = 0;
    virtual void extraInfo(const string& info) = 0;

};

#endif // PRESENTER_H
