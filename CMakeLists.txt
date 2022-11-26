cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
project(natureofcode VERSION 1.0.0)
message(STATUS "Configuring project ${PROJECT_NAME}:c++${CMAKE_CXX_STANDARD}")

if (RandomWalker)
	add_subdirectory(randomwalker)
	add_executable(${PROJECT_NAME}
		${PROD_SOURCES}
		utils/utilities.hpp
	)
	target_include_directories(${PROJECT_NAME} PUBLIC
		${PROD_NAME}
		utils
	)
endif()

if (BarGraph)
	add_subdirectory(bargraph)
	add_executable(${PROJECT_NAME}
		${PROD_SOURCES}
		utils/utilities.hpp
	)
	target_include_directories(${PROJECT_NAME} PUBLIC
		${PROD_NAME}
		utils
	)
endif()

if (Velocity)
	add_subdirectory(velocity)
	add_executable(${PROJECT_NAME}
		${PROD_SOURCES}
	)
	target_include_directories(${PROJECT_NAME} PUBLIC
		${PROD_NAME}
	)
endif()

target_link_libraries(${PROJECT_NAME}
	sfml-graphics
	sfml-window
	sfml-system
)

target_include_directories(${PROJECT_NAME} PUBLIC
	interface
)
