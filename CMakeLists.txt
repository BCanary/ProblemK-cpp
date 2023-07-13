cmake_minimum_required(VERSION 3.0)

project(ProblemK)

add_executable(ProblemK 
    main.cpp

    src/Table.cpp 
    src/Cell.cpp 
    src/StringMath.cpp
    src/TableStringSerializer.cpp
    src/PositionConverter.cpp

    tests/Tests.cpp
    )
