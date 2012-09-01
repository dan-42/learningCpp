cmake_minimum_required(VERSION 2.6)
project(LEARNING_CPP)

#There are lots of scripts with cmake
#for finding external libraries. 
#see /usr/local/share/cmake-2.6/Modules/Find*.cmake for more examples



set(CMAKE_CXX_FLAGS "-g -Wall")


include_directories(src)

add_subdirectory(src)
