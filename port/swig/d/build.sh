#!/bin/sh
#gcc -shared -fPIC -g3 -I../../../include/ -lassimp -olibassimp_wrap.so assimp_wrap.cxx
gcc -shared -g3 -I../../../include/ -lassimp -olibassimp_wrap.so assimp_wrap.cxx
