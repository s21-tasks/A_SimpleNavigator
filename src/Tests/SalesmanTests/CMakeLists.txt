cmake_minimum_required(VERSION 3.0)
project(SalesmanTests VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_subdirectory(../../GraphAlgorithms ${CMAKE_BINARY_DIR}/GraphAlgorithms)

add_executable(${PROJECT_NAME}
        SalesmanTests.cc
        ../../TslCompare/Compare.cc
        )

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/../../TslCompare)

target_link_libraries(${PROJECT_NAME} PUBLIC gtest gtest_main)
target_link_libraries(${PROJECT_NAME} PUBLIC s21_graph_algorithms.a)
