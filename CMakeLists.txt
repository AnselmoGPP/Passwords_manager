CMAKE_MINIMUM_REQUIRED(VERSION 3.0)

PROJECT(pass_manager)

ADD_EXECUTABLE(${PROJECT_NAME}
	src/man_engine.hpp
	src/man_engine.cpp
	src/auxiliar.hpp
	src/main.cpp
)
