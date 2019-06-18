cmake_minimum_required(VERSION 3.2)

project(editor VERSION 0.0.0)
include_directories(${PROJECT_BINARY_DIR})

add_executable(editor
	main.cpp
	shape.hpp
	tools.hpp
	framework.hpp
)

set_target_properties(editor PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
    COMPILE_OPTIONS "-Wpedantic;-Wall;-Wextra"
	COMPILE_OPTIONS "-lpthread"
)

