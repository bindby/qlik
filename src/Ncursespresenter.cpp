#include "Ncursespresenter.h"

NcursesPresenter::NcursesPresenter()
{
    initscr();
    erase();
}

NcursesPresenter::NcursesPresenter(string title) : AbstractPresenter(title)
{
    initscr();
    erase();
}

NcursesPresenter::~NcursesPresenter()
{
    endwin();
}

void NcursesPresenter::printSudoku(const Sudoku& sudoku)
{
    mvprintw(0,0, title.c_str());

    for (int y=0;y<9;y++) {
        for (int x=0;x<9;x++) {
            char stl = sudoku.getLock(x,y) ?'(':' ';
            char etl = sudoku.getLock(x,y) ?')':' ';
            mvprintw(y+2,x*4,"%c%d%c|",stl, sudoku.getValue(x,y), etl);
        }
    }
    refresh();
}

void NcursesPresenter::printSudoku(const Sudoku& sudoku, int x, int y, int iterations, bool complete)
{
    printSudoku(sudoku);
    mvprintw(12,0, "X:%d Y:%d Iterations:%d, Complete:%d                  ",x, y, iterations, complete);
    refresh();
}

void NcursesPresenter::printError(string s) {
    erase();
    mvprintw(0,0, s.c_str());
    refresh();
}

void NcursesPresenter::extraInfo(const string& info) {
    mvprintw(13,0, info.c_str());
    refresh();
}

void NcursesPresenter::waitForKeyPress() {
    mvprintw(16,0, "Press any key to continue.");
    refresh();
    noecho();
    cbreak();
    getch();
}
