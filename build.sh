#!/bin/bash

if [ "$1" == "debug" ]; then
   cmake -D CMAKE_C_COMPILER=gcc-10 -D CMAKE_CXX_COMPILER=g++-10 -DCMAKE_BUILD_TYPE=Debug -S src -B build
   cmake --build build
   valgrind build/roolipeli
   exit;
fi

cmake -D CMAKE_C_COMPILER=gcc-10 -D CMAKE_CXX_COMPILER=g++-10 -S src -B build
cmake --build build
build/roolipeli
