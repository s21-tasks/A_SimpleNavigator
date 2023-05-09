cmake_minimum_required(VERSION 3.22)
project(simpleNavigator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory(GraphAlgorithms ${CMAKE_BINARY_DIR}/GraphAlgorithms)
add_subdirectory(submodules/cpp_libs/matrix)
add_subdirectory(submodules/cpp_libs/utility)
add_subdirectory(submodules/cpp_libs/ConsoleInterface)

add_executable( ${PROJECT_NAME}
        main.cc
        Interface/Interface.cc
        Interface/Interface.h
        TslCompare/Compare.h
        TslCompare/Compare.cc
        )

# link_directories(${CMAKE_BINARY_DIR}/submodules/cpp_libs/utility)

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/TslCompare)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/Interface)

target_link_libraries(${PROJECT_NAME} PRIVATE s21_graph_algorithms.a)
target_link_libraries(${PROJECT_NAME} PRIVATE matrix)
target_link_libraries(${PROJECT_NAME} PRIVATE utility)
target_link_libraries(${PROJECT_NAME} PRIVATE console_interface)
