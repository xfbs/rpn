cmake_minimum_required(VERSION 3.1)

project(parse
    VERSION 1.0
    LANGUAGES CXX)

include_directories(include)

add_library(parse src/parse.cpp include/parse.h)
target_compile_features(parse PUBLIC cxx_std_11)

add_executable(parse-cli src/main.cpp)
target_link_libraries(parse-cli parse)

add_executable(parse-test src/test.cpp)
target_link_libraries(parse-test parse)

enable_testing()
add_test(parse-test parse-test)
