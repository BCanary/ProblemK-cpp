#include "../include/TableStringSerializer.h"
#include "../include/Table.h"
#include "../include/Cell.h"

#include <iostream>
#include <string>
#include <sstream>

std::string TableStringSerializer::write(Table *table)
{
    unsigned int size_x = table->getSize().at(0); 
    unsigned int size_y = table->getSize().at(1); 

    std::string output = "";

    for (unsigned int i = 0; i < size_y; i++)
    {
        for (unsigned int j = 0; j < size_x; j++)
        {
            output += table->getCell(j, i)->read();
            output += " ";
        }
        output += "\n";
    }

    return output; 
}

void TableStringSerializer::read(Table *table, std::string &readable)
{
    std::istringstream iss(readable);
    std::string line;
    
    int position_y = 0;
    int position_x = 0;

    while(std::getline(iss, line))
    {
        std::istringstream line_stream(line);
        std::string cell_data;
        
        position_x = 0;
        while (line_stream >> cell_data)
        {
            Cell *cell = table->getCell(position_x, position_y);
            cell->write(cell_data);
            position_x++;
        }
        position_y++;
    }
}
