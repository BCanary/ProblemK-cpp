#pragma once

#include <vector>

#include "Cell.h"

class Table {
    private:
        unsigned int _size_x;
        unsigned int _size_y;
        std::vector<std::vector<Cell>> table;
    public:
        Table(unsigned int size_x, unsigned int size_y);   
        void calculate();
};
