# digital-filters-lib

## PROJECT GOAL
The goal of this project is to develop a C++ library for designing and applying digital filters to discrete signal processing.
The project is carried out as a part of the 'Object-Oriented Programming Languages' course in the 2025/2026 academic year.

## PROJECT STRUCTURE
```text
.
├── CMakeLists.txt
├── Doxyfile
├── example
│   ├── generate-signal.cpp
│   └── main.cpp
├── inc
│   ├── BlackmanWindow.hpp
│   ├── FileHandler.hpp
│   ├── Filter.hpp
│   ├── FIR.hpp
│   ├── HammingWindow.hpp
│   ├── HanningWindow.hpp
│   ├── HighPassButterworth.hpp
│   ├── HighPassFIR.hpp
│   ├── IIR.hpp
│   ├── LowPassButterworth.hpp
│   ├── LowPassFIR.hpp
│   ├── RectangularWindow.hpp
│   └── Window.hpp
├── LICENSE
├── README.md
├── src
│   ├── BlackmanWindow.cpp
│   ├── FileHandler.cpp
│   ├── Filter.cpp
│   ├── FIR.cpp
│   ├── HammingWindow.cpp
│   ├── HanningWindow.cpp
│   ├── HighPassButterworth.cpp
│   ├── HighPassFIR.cpp
│   ├── IIR.cpp
│   ├── LowPassButterworth.cpp
│   ├── LowPassFIR.cpp
│   ├── RectangularWindow.cpp
│   └── Window.cpp
└── unit-tests
    ├── filehandler-test.cpp
    ├── FIRfilter-test.cpp
    ├── IIRfilter-test.cpp
    └── window-test.cpp
```

## BUILD & RUN (LINUX)
### Requirements
- CMake ⩾ 3.10
- C++ Compiler with C++ 17 support

### Build
From the project root directory:
```bash
mkdir build
cd build
cmake ..
make
```

### Run tests
From the `build` directory:
```bash
./window-test
```
Available unit-tests: `FIRfilter-test`, `IIRfilter-test`, `filehandler-test` and `window-test`.

### Run example
From the `build` directory:
```bash
./generate-signal
./main
```
