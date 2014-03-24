# CMake script for pp6Calculator

cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(pp6Calculator)

include(CheckCXXCompilerFlag)
if(CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    check_cxx_compiler_flag(-std=c++11 HAS_GNUSTYLE_CPP11)
    if(HAS_GNUSTYLE_CPP11)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
    endif()

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Werror -Wall -Wshadow -Wpointer-arith -Wcast-qual -Wno-vla-extension -O3")
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    if(HAS_GNUSTYLE_CPP11)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
    else()
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
    endif()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Werror -Wall -Wshadow -Wpointer-arith -Wno-vla -Wcast-qual -O3")
endif()

include_directories(src, src/pp6Days, src/pp6Utils)

execute_process(COMMAND ${CMAKE_COMMAND} -E make_directory bin)

add_executable( bin/pp6Calculator
                src/pp6Calculator.h
                src/pp6Calculator.cpp
                src/pp6Utils/FileReader.cpp
                src/pp6Days/dayOneFuncs.h
                src/pp6Days/dayOneFuncs.cpp
                src/pp6Days/dayTwoFuncs.h
                src/pp6Days/dayTwoFuncs.cpp
                src/pp6Utils/Vector4.hpp
                src/pp6Utils/Vector4.cpp
                src/pp6Utils/Vector3.hpp
                src/pp6Utils/Particle.hpp
                src/pp6Days/dayThreeFuncs.h
                src/pp6Days/dayThreeFuncs.cpp )

