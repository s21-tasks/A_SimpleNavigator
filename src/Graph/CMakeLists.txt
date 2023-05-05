cmake_minimum_required(VERSION 3.0)

project(graph 1.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Список исходных файлов библиотеки
set(SOURCES
        Graph.cc
        Graph.h
        )


add_library(graph STATIC ${SOURCES})

target_include_directories(graph PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})