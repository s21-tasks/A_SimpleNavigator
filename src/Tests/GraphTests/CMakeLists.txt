cmake_minimum_required(VERSION 3.0)
project(GraphTests VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lgtest -std=c++17")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest)
#find_package(GTest REQUIRED)
include(GoogleTest)
enable_testing()

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

#add_subdirectory(../../submodules/cpp_libs/matrix ${CMAKE_BINARY_DIR}/submodules/cpp_libs/matrix)
#add_subdirectory(../../submodules/cpp_libs/utility ${CMAKE_BINARY_DIR}/submodules/cpp_libs/utility)

add_subdirectory(../../Graph ${CMAKE_BINARY_DIR}/Graph)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
include_directories(.)

include("GoogleTest")


add_executable(${PROJECT_NAME}
        GraphTests.cc
        )

target_link_libraries(${PROJECT_NAME} PUBLIC gtest gtest_main)
target_link_libraries(${PROJECT_NAME} PUBLIC s21_graph.a)
target_link_libraries(${PROJECT_NAME} GTest::gtest_main GraphTests)
