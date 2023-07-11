#pragma once
#include "Table.h"

template< typename T >
/// <summary>
///    This interface represents an table serializer that can
///    write or read data
/// </summary>
class ITableSerializer
{
    public:
        virtual Table read(unsigned int size_x, unsigned int size_y, T &readable) = 0;
        virtual T write(Table &table) = 0;
};
