#! /bin/bash

set -eu
cmake -B build-switch -S . -DCMAKE_TOOLCHAIN_FILE=../cmake/toolchains/DevkitA64Libnx.cmake
cd build-switch
cd _deps/wizengine-src
./switch-install.sh
cd ../..
make
cd ..

sudo cp build-switch/*.a $DEVKITPRO/portlibs/switch/lib/
sudo cp -r include/* $DEVKITPRO/portlibs/switch/include/