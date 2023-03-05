cmake_minimum_required(VERSION 3.16)

set(OBJECTS_LIB bouncingball-objects-lib PARENT_SCOPE)
add_library(bouncingball-objects-lib STATIC ball.cpp)
