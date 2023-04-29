#!/bin/bash
rm -rf pspbuild
mkdir pspbuild && cd pspbuild
psp-cmake .. -DBUILD_SHARED_LIBS=OFF -DASSIMP_BUILD_TESTS=OFF -DASSIMP_NO_EXPORT=ON -DASSIMP_BUILD_ZLIB=ON
find ./ -name '*.make' | xargs sed -i 's/\-fPIC//'
make -j4 VERBOSE=1 install

