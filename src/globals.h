#ifndef GLOBALS_H
#define GLOBALS_H

#include <iostream>
#include <unistd.h>
using namespace std;

#define COLUMNS 9
#define ROWS 9
#define SECTORS 9
#define SIZE 9*9
#define EMPTY 0
#define COL(x) x%COLUMNS
#define ROW(x) x/COLUMNS
#define SECTOR(x) ((x%9)/3)+3*((x/9)/3)
#define POS(x,y) x+y*COLUMNS

#endif // GLOBALS_H
