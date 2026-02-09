#!/bin/bash
set -ex
# g++ -ldl -fPIC -shared -o injector.so injector.cc
clang++ -ldl -fPIC -shared -o injector.so injector.cc
julia --version
LD_PRELOAD=./injector.so julia main.jl
