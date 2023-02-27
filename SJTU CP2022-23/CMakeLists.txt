cmake_minimum_required(VERSION 3.14)
project(ProjectIsing CXX)
set(CMAKE_CXX_STANDARD 14)

### Main target 
file( GLOB SRCS *.cpp *.hpp )
add_executable(IsingSimulation ${SRCS})
target_compile_options(IsingSimulation PRIVATE -Wall -Wextra)

### Unit test
enable_testing()
file( GLOB SRCS_Catch2 UnitTests/catch2/*.hpp UnitTests/catch2/*.cpp)
add_executable(test_IsingSimulation UnitTests/IsingSystem_test.cpp IsingSystem.hpp IsingSystem.cpp UnitTests/Lattice_test.cpp Lattice.hpp Lattice.cpp ${SRCS_Catch2})
target_compile_options(test_IsingSimulation PRIVATE -Wall -Wextra)
add_test(test_IsingSimulation test_IsingSimulation)

### Load Catch2 from remote (commented out)
#include(FetchContent)
#FetchContent_Declare(catch2
#GIT_REPOSITORY https://github.com/catchorg/Catch2.git
#GIT_TAG v3.1.0
#)
#FetchContent_MakeAvailable(Catch2)
#target_link_libraries(test_IsingSimulation Catch2::Catch2WithMain)

