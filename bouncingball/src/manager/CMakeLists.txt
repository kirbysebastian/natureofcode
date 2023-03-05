cmake_minimum_required(VERSION 3.16)

set(LOCAL_LIB bouncingball-mgr-lib PARENT_SCOPE)
add_library(bouncingball-mgr-lib STATIC eventmanager.cpp)

