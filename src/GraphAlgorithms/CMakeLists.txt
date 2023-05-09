cmake_minimum_required(VERSION 3.0)

project(s21_graph_algorithms.a VERSION 1.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
#set(BUILD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/build)
#file(MAKE_DIRECTORY ${BUILD_DIR})
#set(CMAKE_BINARY_DIR ${BUILD_DIR})
#set(SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

#add_subdirectory(${SOURCE_DIR} ${CMAKE_BINARY_DIR})


add_subdirectory(../Graph ${CMAKE_BINARY_DIR}/Graph)

set(SOURCES
        GraphAlgorithms.cc
        GraphAlgorithms.h
        GeneticAlgorithm/GeneticAlgorithm.cc
        GeneticAlgorithm/GeneticAlgorithm.h
        AntColonyAlgorithm/AntColonyTSL.h
        helpers.h
        )

add_library(${PROJECT_NAME} STATIC ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_NAME s21_graph_algorithms
        PREFIX ""
        )
target_link_libraries(${PROJECT_NAME} PUBLIC s21_graph.a)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
