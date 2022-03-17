cmake_minimum_required(VERSION 3.15)

set(PROJECT "CString")
project(${PROJECT} C CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED on)

set(SOURCES 
    CString.cpp
    TestListStr.cpp
)
set(HEADERS 
    CString.h
    TestListStr.h
)

add_executable(${PROJECT} main.cpp ${SOURCES} ${HEADERS})
