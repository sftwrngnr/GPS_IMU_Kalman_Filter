#!/bin/bash
cd lib
mkdir build
cd build
cmake ../
sudo make install
cd ../../src
g++ -I /usr/local/include/eigen3 main.cpp 


