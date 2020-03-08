#ifndef NCURSESPRESENTER_H
#define NCURSESPRESENTER_H

#include "AbstractPresenter.h"
#include <ncurses.h>

class NcursesPresenter : public AbstractPresenter
{
public:
    NcursesPresenter();
    NcursesPresenter(string title);
    ~NcursesPresenter();
    void printError(string s);
    void printSudoku(const Sudoku& sudoku);
    void printSudoku(const Sudoku& sudoku, int x, int y, int iterations, bool complete);
    void waitForKeyPress();
    void extraInfo(const string& info);

};

#endif // NCURSESPRESENTER_H
