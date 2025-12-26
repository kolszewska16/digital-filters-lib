cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(DigitalFiltersLib VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCE_FILES
	src/Window.cpp
	src/RectangularWindow.cpp
	src/HammingWindow.cpp
	src/HanningWindow.cpp
	src/BlackmanWindow.cpp)

set(WINDOW_TEST
	unit-tests/window-test.cpp)

# add the digital-filters Library
add_library(digital-filters ${SOURCE_FILES})
target_include_directories(digital-filters PUBLIC inc)

# add the executable
add_executable(window-test ${WINDOW_TEST})
target_link_libraries(window-test PRIVATE digital-filters)

