#include "../include/Table.h"
#include "../include/TableStringSerializer.h"
#include "Tests.h"

#include <string>
#include <iostream>
#include <sstream>

void Tests::testTable()
{
    std::string size = "2 3";
    std::string input = "=B1 'Two 3\n=B2 =A1 6";
    std::cout << "INPUT" << std::endl << size << std::endl << input << std::endl;

    unsigned int size_x, size_y;

    std::istringstream iss(size);
    iss >> size_y >> size_x;

    TableStringSerializer tss = TableStringSerializer();
    Table table = Table(size_x, size_y);
    
    tss.read(&table, input);
    table.calculate();
    
    std::cout << "READ";
    std::cout << "RESULT" << std::endl;
    std::string back_result = tss.write(&table);
    std::cout << back_result;
}
