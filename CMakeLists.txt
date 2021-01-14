cmake_minimum_required(VERSION 3.17)
project(cpp_eigen)

set(CMAKE_CXX_STANDARD 14)
set(TARGET ${CMAKE_PROJECT_NAME})
set(SRC_FILES
        src/main.cpp)

find_package (Eigen3 3.3 REQUIRED NO_MODULE)

add_executable(${TARGET} ${SRC_FILES})

# linking
target_link_libraries(${TARGET} Eigen3::Eigen)