
cmake_minimum_required(VERSION 3.16)

set(PROD_NAME "objectonmouseclick" PARENT_SCOPE)
file(GLOB_RECURSE SRCS "*.cpp")
set(PROD_SOURCES ${SRCS} PARENT_SCOPE)
