cmake_minimum_required(VERSION 3.24)
project(simpleNavigator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


#add_subdirectory(Graph ${CMAKE_BINARY_DIR}/Graph)
add_subdirectory(GraphAlgorithms ${CMAKE_BINARY_DIR}/GraphAlgorithms)
add_subdirectory(submodules/cpp_libs/matrix)
add_subdirectory(submodules/cpp_libs/utility)
add_subdirectory(submodules/cpp_libs/ConsoleInterface)

#find_package(GTest)

add_executable( ${PROJECT_NAME}
        main.cc
        Interface/Interface.cc
        Interface/Interface.h
        TslCompare/Compare.h
        TslCompare/Compare.cc
        )

target_link_libraries(${PROJECT_NAME} PRIVATE s21_graph_algorithms.a matrix utility console_interface)
