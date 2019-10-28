# only for cmake --version >= 3.5.1
cmake_minimum_required(VERSION 3.5.1)

# project name
project(chapter2-cmake)

# creates the variable EXEC and sets it to hello
set(EXEC chapter2)

# set the C++17 standard
#set(CMAKE_CXX_STANDARD 17)

# I../includes
include_directories(includes)

#Manually add source files   #Multiple Sources set(SOURCES src/source1.c src/source2.c src/source3.c)
set(SOURCES src/chapter2.cpp)

# puts all .cpp files inside src to the SOURCES variable
#file(GLOB SOURCES src/*.cpp)
#file(GLOB SOURCES src/*.c)

# compiles the files defined by SOURCES to generante the executable defined by EXEC
add_executable(${EXEC} ${SOURCES})