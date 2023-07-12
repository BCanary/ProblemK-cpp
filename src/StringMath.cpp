#include "../include/StringMath.h"
#include <regex>
#include <iostream>
#include <string>

/// <summary>
/// Takes a math expression string and returns result
/// </summary>
int StringMath::calculate(std::string &input)
{
    //std::vector<std::string>;
    std::regex expression_regex("[+\\-/*]");
    std::sregex_iterator expression_iterator(input.begin(), input.end(), expression_regex);
    std::sregex_iterator expression_end;

    std::regex number_regex("\\d+");
    std::sregex_iterator number_iterator(input.begin(), input.end(), number_regex);
    std::sregex_iterator number_end;
    
    int result = std::stoi(number_iterator->str());
    number_iterator++;
    while (expression_iterator != expression_end)
    {
        int number = std::stoi(number_iterator->str());
        
        std::string expression = expression_iterator->str();
        if (expression == "+")
        {
            result += number;
        }
        else if (expression == "-")
        {
            result -= number;
        }
        else if (expression == "*")
        {
            result *= number;
        }
        else if (expression == "/")
        {
            result /= number;
        }
        expression_iterator++;
        number_iterator++;
    }
    return result;
}
