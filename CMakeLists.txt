# to use make, I do something like
#mkdir build
#cd build
#cmake .. #by default it creates a makefile for you
#make #calls the make command which looks in Makefile to see what to do
#./asteroids  #run the resulting file


#use a recent version of CMake
cmake_minimum_required(VERSION 3.15)

#the project is called asteroids
project(myGame)

#the project contains an executable named testSFML that uses the following cpp files
add_executable(myGame
    src/player.cpp
    src/trunk.cpp
    src/WayToHeaven.cpp 
    src/player.hpp 
    src/trunk.hpp
)

#create a folder named "cmake" at the top of your project and put the
#findSFML.cmake file in it.  This line tells Cmake to look there for
#find____.cmake files
#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")

#this says find the graphics, window, and system libraries
#it uses the FindSFML.cmake file to do so and sets
#some variables ($SFML_LIBRARIES and SFML_INCLUDE_DIRECTORIES) that are
#used below
find_package(SFML 2.5 COMPONENTS graphics REQUIRED)

#tells Cmake that the asteroids executable needs to be linked with SFML
target_link_libraries(myGame sfml-graphics)

#passes an option to clang when compiling to use recent c++ stuff
target_compile_options(myGame PUBLIC -std=c++17)

# Install game data
install(DIRECTORY img
		DESTINATION .)