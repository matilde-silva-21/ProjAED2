cmake_minimum_required(VERSION 3.20)
project(ProjAED2)

set(CMAKE_CXX_STANDARD 14)

add_executable(ProjAED2 src/main.cpp src/graph.cpp src/disjointSets.h src/minHeap.h src/FileHandler.cpp src/FileHandler.h src/Line.cpp src/Line.h src/Stop.cpp src/Stop.h src/bst.h src/Initialize.cpp src/Initialize.h src/Menu.cpp)

