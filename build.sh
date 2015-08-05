#!/bin/bash
rm CMakeCache.txt
rm src/CMakeCache.txt
rm -rf CMakeFiles
cmake -DCMAKE_BUILD_TYPE=$1 .
make 
