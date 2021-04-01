cmake_minimum_required(VERSION 3.17)
project(MyString)

set(CMAKE_CXX_STANDARD 14)

add_executable(MyString main.cpp MyString.cpp MyString.h MyStringData.cpp MyStringData.h ExceptionMyStringAt.cpp ExceptionMyStringAt.h)