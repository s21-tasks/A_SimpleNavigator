cmake_minimum_required(VERSION 3.22)
project(simpleNavigator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest)

add_executable( simpleNavigator
        main.cc
        Graph.cc
        Graph.h
        GraphAlgorithms.cc
        GraphAlgorithms.h
        Interface.h
        Interface.cc
        TSMResult.h
        TslCompare/Compare.h
        TslCompare/Compare.cc
        lib/matrix.h
        lib/random.h
        lib/sstr.h
        lib/time.h
        lib/ConsoleInterface/ConsoleInterface.cc
        lib/ConsoleInterface/ConsoleInterface.h
        lib/ConsoleInterface/Style.h
        )
