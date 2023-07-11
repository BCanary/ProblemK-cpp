#pragma once
#include <string>

class Cell {
    private:
        std::string _data; // A data stored in a cell
        std::string _value; // Value is a data stored after calculations, so it is a cache
    public:
        void write(std::string data);
        void calculate();
        std::string read();
};
