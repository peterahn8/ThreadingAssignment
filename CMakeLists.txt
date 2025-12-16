cmake_minimum_required(VERSION 4.0)
project(ThreadingAssignment)

set(CMAKE_CXX_STANDARD 20)

add_executable(ThreadingAssignment main.cpp
        Thread.h
        Thread.cpp
        TestThread.cpp
        GlobalState.h)
