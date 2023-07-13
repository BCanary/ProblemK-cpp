#include "../include/PositionConverter.h"

#include <vector>
#include <string>
#include <regex>
#include <numeric>
#include <iostream>

std::vector<int> PositionConverter::stringToVector(std::string position)
{
    std::regex regex_row("[A-Za-z]");
    std::sregex_iterator it(position.begin(), position.end(), regex_row);
    std::sregex_iterator end;
    std::smatch regex_row_match = *it;
    
    std::regex regex_column("\\d");
    std::sregex_iterator it2(position.begin(), position.end(), regex_column);
    std::sregex_iterator end2;
    std::smatch regex_column_match = *it2;

    std::string row = regex_row_match.str();
    std::string column = regex_column_match.str();
    
    return std::vector<int> { PositionConverter::_stringToNumber(row), std::stoi(column)-1 };
}

int PositionConverter::_stringToNumber(std::string input)
{
    const char* letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char* find = std::strchr(letters, input[0]);
    
    return find - letters; 
}
