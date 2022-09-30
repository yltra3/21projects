cmake_minimum_required(VERSION 3.23)
project(untitled)

set(CMAKE_CXX_STANDARD 11)

add_library(untitled ex00/megaphone.cpp ex01/main.cpp ex01/phonebook.h ex01/phonebook.cpp ex01/scrappy.cpp ex01/scrappy.h)
