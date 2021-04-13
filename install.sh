#!/bin/bash

set -ex

# rm -rf build && mkdir build
pushd build

# conan install  ../.conan/ --build=missing -pr=../.conan/profile
# conan info     ../.conan/ --graph=dependencies.html

# cmake .. 
cmake --build .

popd
exit 0
