cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(DigitalFiltersLib VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCE_FILES
	src/BlackmanWindow.cpp
	src/FileHandler.cpp
	src/FIR.cpp
	src/HammingWindow.cpp
	src/HanningWindow.cpp
	src/HighPassFIR.cpp
	src/RectangularWindow.cpp
	src/Window.cpp)

set(WINDOW_TEST
	unit-tests/window-test.cpp)

set(FILEHANDLER_TEST
	unit-tests/filehandler-test.cpp)

set(FILTER_TEST
	unit-tests/filter-test.cpp)

# add the digital-filters Library
add_library(digital-filters ${SOURCE_FILES})
target_include_directories(digital-filters PUBLIC inc)

# add the executable
add_executable(window-test ${WINDOW_TEST})
target_link_libraries(window-test PRIVATE digital-filters)

add_executable(filehandler-test ${FILEHANDLER_TEST})
target_link_libraries(filehandler-test PRIVATE digital-filters)

add_executable(filter-test ${FILTER_TEST})
target_link_libraries(filter-test PRIVATE digital-filters)
