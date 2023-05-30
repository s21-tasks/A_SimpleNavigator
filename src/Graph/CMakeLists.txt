cmake_minimum_required(VERSION 3.0)

project(s21_graph.a VERSION 1.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(../Submodules/Matrix ${CMAKE_BINARY_DIR}/matrix)
add_subdirectory(../Submodules/Utility ${CMAKE_BINARY_DIR}/utility)

add_library(${PROJECT_NAME} STATIC
        Graph.cc
        Graph.h)

set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_NAME s21_graph
        PREFIX ""
        )

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR})

target_link_libraries(${PROJECT_NAME} PUBLIC matrix)
target_link_libraries(${PROJECT_NAME} PUBLIC utility)
