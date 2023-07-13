#include "../include/Table.h"
#include "../include/Cell.h"

#include <vector>
#include <iostream>

Table::Table(unsigned int size_x, unsigned int size_y)
{
    Table::_size_x = size_x;
    Table::_size_y = size_y;

    _table = std::vector<std::vector<Cell *>>(size_y, std::vector<Cell *>(size_x));
    for (int i = 0; i < size_y; i++)
    {
        for (int j = 0; j < size_x; j++)
        {
           _table[i][j] = new Cell(); 
        }
    }
}

Table::~Table()
{

}

Cell* Table::getCell(int position_x, int position_y, std::vector<std::vector<int>> *chain)
{
    // Check if there is already that Cell in array
    auto this_position = std::vector<int> {position_x, position_y};

    if (chain != nullptr)
    {
        bool in_chain = false;
        for (auto i: *chain)
        {
            if (i == this_position)
            {
                in_chain = true;
                for (std::vector<int> j: *chain)
                {
                    Cell *cell = Table::getCell(j[0], j[1], nullptr);
                    cell->write("#CYCLE");
                    cell->calculate(this);
                }
            }
        }
        if (!in_chain)
        {
            chain->push_back(this_position);
        }
        else {
            return nullptr;
        }
    }
    
    return _table[position_y][position_x]; 
}

std::vector<unsigned int> Table::getSize()
{
    std::vector<unsigned int> sizes = {_size_x, _size_y};
    return sizes;
}

void Table::calculate() 
{
    for (auto col: _table)
    {
        for (Cell* row: col) 
        {
            row->calculate(this);
        }
    }
}
