#!/bin/bash
cd lib
mkdir doc
mkdir bias
mkdir lapack
mkdir unsupported
mkdir demos
mkdir build
cd build
cmake ../
sudo make install
rm -rf ./*
cd ../../src
g++ -I /usr/local/include/eigen3 main.cpp -o main
./main


