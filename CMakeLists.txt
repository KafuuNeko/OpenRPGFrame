cmake_minimum_required(VERSION 3.9)
project(OpenRPGFrame)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "-O2")

add_subdirectory(third_party)

add_executable(OpenRPGFrame src/main.cc src/db/database.cc)
target_include_directories(OpenRPGFrame PUBLIC src)
target_link_libraries(OpenRPGFrame PRIVATE lepton md5 cppcrc sqlite_orm)
