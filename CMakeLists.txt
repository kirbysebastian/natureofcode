cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
project(natureofcode VERSION 1.0.0)
message(STATUS "Configuring project ${PROJECT_NAME} using c++${CMAKE_CXX_STANDARD}")

if (RandomWalker)
	add_subdirectory(randomwalker)
elseif (BarGraph)
	add_subdirectory(bargraph)
elseif (Velocity)
	add_subdirectory(velocity)
elseif (ObjectOnMouseClick)
	add_subdirectory(objectonclick)
elseif (Friction)
	add_subdirectory(friction)
elseif (ParticleCollission)
	add_subdirectory(particlecollission)
elseif (BouncingBall)
	add_subdirectory(bouncingball)
else()
	set(PROD_SOURCES main.cpp)
endif()

add_executable(${PROJECT_NAME}
	${PROD_SOURCES}
	common/utils.hpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
	${PROD_NAME}
	common
	interface
)

target_link_libraries(${PROJECT_NAME}
	sfml-graphics
	sfml-window
	sfml-system
	${DEPENDENCY_LIBS}
)

