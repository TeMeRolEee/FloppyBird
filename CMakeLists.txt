cmake_minimum_required(VERSION 3.10)
project(birb)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
set(CMAKE_AUTOMOC ON)

find_package(Qt5Core HINTS ~/Qt/5.11.1/gcc_64/)
find_package(Qt5Widgets HINTS ~/Qt/5.11.1/gcc_64/)


add_executable(birb main.cpp Bird.cpp Pipe.cpp Pipe.h Game.cpp Game.h)

configure_file(FloppyBack.png FloppyBack.png COPYONLY)
configure_file(backgroundv2.jpg backgroundv2.jpg COPYONLY)
configure_file(floppy.png floppy.png COPYONLY)

# linking
target_link_libraries(birb Qt5::Core)
target_link_libraries(birb Qt5::Widgets)


