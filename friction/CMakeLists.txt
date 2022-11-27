cmake_minimum_required(VERSION 3.16)

set(PROD_NAME "friction" PARENT_SCOPE)
file(GLOB_RECURSE SRCS "*.cpp")
set(PROD_SOURCES ${SRCS} PARENT_SCOPE)
