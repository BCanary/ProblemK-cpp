#pragma once

#include <string>

#include "ITableSerializer.h"

class TableStringSerializer : ITableSerializer<std::string>
{
    public:
        Table read(unsigned int size_x, unsigned int size_y, std::string &readable);
        std::string write(Table &table);
};
