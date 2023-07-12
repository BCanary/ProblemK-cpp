#include "../include/Cell.h"
#include "../include/StringMath.h"

#include <string>
#include <iostream>

Cell::Cell()
{
    Cell::_data = "#NULL";
    Cell::_value = "#NULL";
}

void Cell::write(std::string data)
{
    Cell::_data = data;
}

std::string Cell::read()
{
    return Cell::_value;
}

void Cell::calculate()
{
    if (_data[0] == '\'')
    {
        _value = _data.substr(1);
    }
    else if (_data[0] == '=')
    {
        std::string input = _data.substr(1);
        _value = std::to_string( StringMath::calculate(input));
    }
    else {
        _value = _data;
    }
}
