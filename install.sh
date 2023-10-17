#!/bin/bash

cd SDL
mkdir build
cd build
../configure
make -j6
sudo make install -j6
