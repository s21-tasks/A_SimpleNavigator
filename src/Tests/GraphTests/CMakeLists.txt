cmake_minimum_required(VERSION 3.0)
project(GraphTests VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_subdirectory(../../Graph ${CMAKE_BINARY_DIR}/Graph)

add_executable(${PROJECT_NAME}
        GraphTests.cc
        )

target_link_libraries(${PROJECT_NAME} PUBLIC gtest gtest_main)
target_link_libraries(${PROJECT_NAME} PUBLIC s21_graph.a)
