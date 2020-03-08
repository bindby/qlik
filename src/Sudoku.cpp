#include "Sudoku.h"

Sudoku::Sudoku() {
    reset();
}

void Sudoku::reset() {
    memset(table, 0, sizeof(table));
    memset(lock_mask, false, sizeof (lock_mask));
}


bool Sudoku::fromString(string s) {
    Sudoku sudoku;
    if (s.length()<SIZE) {
        return false;
    }
    for(size_t pos=0;pos<SIZE;pos++) {
        int value = (s[pos] == '.') ? 0 : s[pos]-'0';
        if (value<0 || value>9) {
            return false;
        }
        table[COL(pos)][ROW(pos)] = value;
        lock_mask[COL(pos)][ROW(pos)] = (value != 0);
    }
    return true;
}

bool Sudoku::fromFile(string path) {
    ifstream inFile;
    inFile.open(path);
    if (!inFile) {
        return false;
    }

    string content = "";
    string line;
    while (inFile >> line) {
        content += line;
    }
    inFile.close();
    content.erase(remove(content.begin(), content.end(), '\n'), content.end());
    return fromString(content);
}
