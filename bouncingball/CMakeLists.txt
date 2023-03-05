cmake_minimum_required(VERSION 3.16)

add_subdirectory(src/engine)
add_subdirectory(src/manager)
add_subdirectory(src/objects)

set(PROD_NAME "bouncingball" PARENT_SCOPE)
file(GLOB_RECURSE SRCS "bouncingball.cpp")

set(PROD_SOURCES ${SRCS} PARENT_SCOPE)

# FIX LIBRARY MANAGEMENT!
set(DEPENDENCY_LIBS
	${LOCAL_LIB}
	${ENGINE_LIB}
	${OBJECTS_LIB}
	
	PARENT_SCOPE
)

target_include_directories(${LOCAL_LIB} PUBLIC
	includes
)

target_include_directories(${ENGINE_LIB} PUBLIC
	includes
)

target_include_directories(${OBJECTS_LIB} PUBLIC
	includes
)

