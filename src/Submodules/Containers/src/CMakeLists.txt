cmake_minimum_required(VERSION 3.0)

project(containers.a VERSION 1.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
        s21_array.hpp
        s21_containers.hpp
        s21_list.hpp
        s21_queue.hpp
        s21_sort.hpp
        s21_stack.hpp
        s21_vector.hpp
        Dummy.cc
        )

add_library(${PROJECT_NAME} STATIC ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES
        OUTPUT_NAME containers
        PREFIX ""
        )

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
