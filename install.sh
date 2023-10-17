#!/bin/bash

git submodule init
cd SDL
mkdir build
cd build
../configure
make -j6
sudo make install -j6
