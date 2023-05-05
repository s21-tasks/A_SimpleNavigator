cmake_minimum_required(VERSION 3.24)
project(simpleNavigator VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory(Graph)
add_subdirectory(GraphAlgorithms)
add_subdirectory(submodules/cpp_libs/matrix)


#find_package(GTest)

add_executable( ${PROJECT_NAME}
        main.cc
        )

target_link_libraries(${PROJECT_NAME} PRIVATE graph graph_algorithms matrix)
