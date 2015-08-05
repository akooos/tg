#!/bin/bash
./build.sh Debug
echo "Executing ./bin/debug/tg $*"
./bin/debug/tg $*
