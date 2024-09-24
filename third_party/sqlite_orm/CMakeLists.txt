cmake_minimum_required(VERSION 3.9)

project(sqlite_orm)

add_library(sqlite_orm sqlite3.c)
target_include_directories(sqlite_orm PUBLIC include)