#!/bin/bash
set -e
set -x

SCRIPT_DIR="$(cd "$(dirname "$0")" && pwd)"
REPO_DIR=$SCRIPT_DIR/../../
cd $REPO_DIR

# If parameter 1 is not supplied, it defaults to Release
BUILD_CONFIGURATION=${1:-Release}

mkdir -p build
cd build
cmake .. -DCMAKE_BUILD_TYPE=${BUILD_CONFIGURATION} -DWARNINGS=Off -DBUILD_JAVA=Off -DBUILD_PYTHON=Off -DBUILD_TESTS=Off
NUM_PROCESSORS=$(cat nprocs.txt)
make vw-bin -j ${NUM_PROCESSORS}