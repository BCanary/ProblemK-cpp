#pragma once

#include <string>

#include "ITableSerializer.h"

class TableStringSerializer : ITableSerializer<std::string>
{
    public:
        void read(Table *table, std::string &readable);
        std::string write(Table *table);
};
