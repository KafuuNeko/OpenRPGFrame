cmake_minimum_required(VERSION 3.9)

project(md5)

add_library(md5 md5.cpp)
target_include_directories(md5 PUBLIC include)