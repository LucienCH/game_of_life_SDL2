#!/bin/bash

git submodule init
git submodule update
cd SDL
mkdir build
cd build
../configure
make -j6
sudo make install -j6
