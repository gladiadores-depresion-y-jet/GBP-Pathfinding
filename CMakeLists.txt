cmake_minimum_required(VERSION 3.14)
project(PathFinding)

set(CMAKE_CXX_STANDARD 14)

add_executable(PathFinding Main/main.cpp Structures/Node.h Structures/List.h Logic/Cell.cpp Logic/Cell.h Logic/Matrix.cpp Logic/Matrix.h)