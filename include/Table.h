#pragma once

#include <vector>

#include "Cell.h"

class Table {
    private:
        unsigned int _size_x;
        unsigned int _size_y;
        std::vector<std::vector<Cell *>> _table; 
    public:
        std::vector<unsigned int> getSize();
        Table(unsigned int size_x, unsigned int size_y);   
        ~Table();
        void calculate();
        Cell *getCell(int position_x, int position_y);
};
