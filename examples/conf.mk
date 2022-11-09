CXX         = g++-11
CXXFLAGS    = -O3 -march=native -fPIC -std=c++11 -Wno-pointer-arith
CXXFLAGS_DEBUG = -O0 -g -rdynamic -fPIC -std=c++11

CC          = gcc-11
CFLAGS      = -O3 -march=native -fPIC

ARCH        = /usr/bin/ar
ARCHFLAGS   = cr
RANLIB      = /usr/bin/ranlib
