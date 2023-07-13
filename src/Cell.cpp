#include "../include/Cell.h"
#include "../include/StringMath.h"
#include "../include/PositionConverter.h"
#include "../include/Table.h"

#include <string>
#include <iostream>
#include <regex>
#include <vector>

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

void Cell::calculate(Table *table)
{
    if (_data[0] == '\'')
    {
        _value = _data.substr(1);
    }
    if (_data[0] == '#')
    {
        _value = _data;
    }
    else if (_data[0] == '=')
    {
        std::string input = _data.substr(1);
        std::string math_expression = ""; 
        
        std::regex cell_regex("[A-Za-z]\\d");
        std::sregex_iterator it(_data.begin(), _data.end(), cell_regex);
        std::sregex_iterator end;

        std::regex expression_regex("[+\\-/*]");
        std::sregex_iterator expression_iterator(input.begin(), input.end(), expression_regex);
        std::sregex_iterator expression_end;
        
        std::vector<std::vector<int>> *chain = new std::vector<std::vector<int>>;
        if (expression_iterator == expression_end)
        {
            std::vector<int> position = PositionConverter::stringToVector(it->str());
            Cell *cell = table->getCell(position[0], position[1], chain);
            _value = cell->read(); 
        }
        else 
        { 
            std::cout << math_expression;
            _value = std::to_string(StringMath::calculate(input));
        }
        delete chain;
    }
    else {
        _value = _data;
    }
}
