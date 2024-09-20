cmake_minimum_required(VERSION 3.9)
project(lepton)

add_library(lepton 
    src/CompiledExpression.cpp
    src/ExpressionProgram.cpp
    src/ExpressionTreeNode.cpp
    src/Operation.cpp
    src/ParsedExpression.cpp
    src/Parser.cpp
)
target_include_directories(lepton PUBLIC include)
