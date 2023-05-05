cmake_minimum_required(VERSION 3.0)

project(graph_algorithms VERSION 1.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
        GraphAlgorithms.cc
        GraphAlgorithms.h
        GeneticAlgorithm/GeneticAlgorithm.cc
        GeneticAlgorithm/GeneticAlgorithm.h
        ../helpers.h
        )

add_library(${PROJECT_NAME} STATIC ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
