#!/bin/bash

cmake -D CMAKE_C_COMPILER=gcc-10 -D CMAKE_CXX_COMPILER=g++-10 -S src -B build
cmake --build build
build/smart_ptr
cat ptr.log*
rm ptr.log*
