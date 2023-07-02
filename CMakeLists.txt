cmake_minimum_required(VERSION 3.25)
project(RubiksCubeSolver)

set(CMAKE_CXX_STANDARD 17)

add_executable(RubiksCubeSolver main.cpp Model/RubiksCube.cpp Model/RubiksCube.h Model/RubiksCube3dArray.cpp DFS_Solver.h BFS_Solver.h )
