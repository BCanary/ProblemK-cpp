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
        virtual void read(Table *table, T &readable) = 0;
        virtual T write(Table *table) = 0;
};
