#pragma once

#include <string>

class Table;

class Cell {
    private:
        std::string _value; // Value is a data stored after calculations, so it is a cache
    public:
        std::string _data; // A data stored in a cell
        Cell();
        void write(std::string data);
        void calculate(Table *table);
        std::string read();
};
