
cmake_minimum_required(VERSION 3.15)

#the project is called asteroids
project(WayToHeaven)

#the project contains an executable named testSFML that uses the following cpp files
add_executable(WayToHeaven src/player.cpp src/trunk.cpp src/WayToHeaven.cpp src/player.hpp src/trunk.hpp)


#some variables ($SFML_LIBRARIES and SFML_INCLUDE_DIRECTORIES) that are
#used below
find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)


#tells Cmake that the asteroids executable needs to be linked with SFML
target_link_libraries(WayToHeaven sfml-graphics sfml-audio)

#passes an option to clang when compiling to use recent c++ stuff
target_compile_options(WayToHeaven PUBLIC -std=c++17)
