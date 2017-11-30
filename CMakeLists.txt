cmake_minimum_required(VERSION 3.7)
project(hw7)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES testMyString.cpp MyString.cpp MyString.h)
#set(SOURCE_FILES main.cpp MyString.cpp MyString.h)


add_executable(hw7 ${SOURCE_FILES})
