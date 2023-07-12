#include <iostream>
#include <string>

#include "include/Table.h"
#include "tests/Tests.h"

int main() 
{
    std::string input = "21+3-4/32*6";
    //StringMath::calculate(input);

    //Table table = Table(10, 15);
    Tests::testTable(); 
    return 0;
}
