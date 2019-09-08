cmake_minimum_required(VERSION 3.1)

project(calc
    VERSION 1.0
    LANGUAGES CXX)

include_directories(include)

add_library(calc src/calc.cpp include/calc.h)
target_compile_features(calc PUBLIC cxx_std_11)

add_executable(calc-cli src/main.cpp)
target_link_libraries(calc-cli calc)

add_executable(calc-test src/test.cpp)
target_link_libraries(calc-test calc)

enable_testing()
add_test(calc-test calc-test)
