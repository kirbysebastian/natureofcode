
cmake_minimum_required(VERSION 3.16)

set(ENGINE_LIB bouncingball-engine-lib PARENT_SCOPE)
add_library(bouncingball-engine-lib STATIC engine.cpp)
