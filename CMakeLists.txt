cmake_minimum_required(VERSION 3.16)
project(Coursera)

set(CMAKE_CXX_STANDARD 20)

add_executable(Coursera main.cpp date.cpp database.cpp node.cpp
        condition_parser.cpp token.cpp condition_parser_test.cpp)