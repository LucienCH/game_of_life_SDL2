#!/bin/bash

git submodule init
git submodule update
cd SDL
mkdir build
cd build
<<<<<<< HEAD
../configure --disable-video-mir
make -j6
sudo make install -j6

cd ../../
mkdir bin
mkdir obj
chmod -R 770 bin/
chmod -R 770 obj/
chown -R $USER:users bin/
chown -R $USER:users obj/
export DISPLAY=localhost:0
=======
../configure
make -j4
sudo make install -j4
>>>>>>> origin/olivia
