cmake_minimum_required(VERSION 3.3)
project(music)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp musiccreators/MusicCreator.h musiccreators/SoloCreator.cpp musiccreators/SoloCreator.h musiccreators/MultiCreator.cpp musiccreators/MultiCreator.h)
add_executable(music ${SOURCE_FILES})