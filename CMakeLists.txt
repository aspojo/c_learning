cmake_minimum_required(VERSION 3.21)
project(c_learning)

set(CMAKE_CXX_STANDARD 14)

add_executable(c_learning main.cpp huffman.cpp huffman.h list/Node.cpp list/Node.h)
