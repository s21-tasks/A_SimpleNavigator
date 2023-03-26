cmake_minimum_required(VERSION 3.24)
project(simpleNavigator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest)

add_executable( simpleNavigator
        Graph.cc
        Graph.h
        maykitbo_matrix/src/matrix.h
        main.cc
        GraphAlgorithms.h
        GraphAlgorithms.cc
        )

