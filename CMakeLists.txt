cmake_minimum_required(VERSION 3.3)
project(music)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/MusicCreator.h src/MultiCreator.cpp src/MultiCreator.h src/SingleFrequency.cpp src/SingleFrequency.h src/MusicCreator.cpp src/Helper.cpp src/Helper.h src/TimedPlayer.cpp src/TimedPlayer.h src/InteractiveCreator.cpp src/InteractiveCreator.h src/KeyboardReader.cpp src/KeyboardReader.h)
add_executable(music ${SOURCE_FILES})