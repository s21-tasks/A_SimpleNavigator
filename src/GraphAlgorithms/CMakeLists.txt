cmake_minimum_required(VERSION 3.0)

project(s21_graph_algorithms.a VERSION 1.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(../Graph ${CMAKE_BINARY_DIR}/Graph)
add_subdirectory(../Submodules/Containers/src ${CMAKE_BINARY_DIR}/containers)

set(SOURCES
        GraphAlgorithms.cc
        GraphAlgorithms.h
        GeneticAlgorithm/GeneticAlgorithm.h
        AntColonyAlgorithm/AntColonyAlgorithm.h
        BnBAlgorithm/BnBAlgorithm.h
        Helpers.h
        )

add_library(${PROJECT_NAME} STATIC ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_NAME s21_graph_algorithms
        PREFIX ""
        )

target_link_libraries(${PROJECT_NAME} PUBLIC s21_graph.a)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${PROJECT_NAME} PUBLIC containers.a)
