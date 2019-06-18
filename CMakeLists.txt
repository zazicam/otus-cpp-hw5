cmake_minimum_required(VERSION 3.2)

project(editor VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
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

install(TARGETS editor RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT dima.friends@mail.ru)

include(CPack)

