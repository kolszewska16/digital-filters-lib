cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(DigitalFiltersLib VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCE_FILES
	src/BlackmanWindow.cpp
	src/FileHandler.cpp
	src/Filter.cpp
	src/FIR.cpp
	src/HammingWindow.cpp
	src/HanningWindow.cpp
	src/HighPassButterworth.cpp
	src/HighPassFIR.cpp
	src/IIR.cpp
	src/LowPassButterworth.cpp
	src/LowPassFIR.cpp
	src/RectangularWindow.cpp
	src/Window.cpp)

set(WINDOW_TEST
	unit-tests/window-test.cpp)

set(FILEHANDLER_TEST
	unit-tests/filehandler-test.cpp)

set(FIR_FILTER_TEST
	unit-tests/FIRfilter-test.cpp)

set(IIR_FILTER_TEST
	unit-tests/IIRfilter-test.cpp)

set(SIGNAL_GENERATION
	example/generate-signal.cpp)

set(MAIN
	example/main.cpp)

# add the digital-filters Library
add_library(digital-filters ${SOURCE_FILES})
target_include_directories(digital-filters PUBLIC inc)

# add the executable
add_executable(window-test ${WINDOW_TEST})
target_link_libraries(window-test PRIVATE digital-filters)

add_executable(filehandler-test ${FILEHANDLER_TEST})
target_link_libraries(filehandler-test PRIVATE digital-filters)

add_executable(FIRfilter-test ${FIR_FILTER_TEST})
target_link_libraries(FIRfilter-test PRIVATE digital-filters)

add_executable(IIRfilter-test ${IIR_FILTER_TEST})
target_link_libraries(IIRfilter-test PRIVATE digital-filters)

add_executable(generate-signal ${SIGNAL_GENERATION})
target_link_libraries(generate-signal PRIVATE digital-filters)

add_executable(main ${MAIN})
target_link_libraries(main PRIVATE digital-filters)
