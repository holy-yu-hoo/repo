cmake_minimum_required(VERSION 3.28)
project(project C)


find_package(Python REQUIRED COMPONENTS Development)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/module)

add_library(hello MODULE main.c)
set_target_properties(hello PROPERTIES
		PREFIX ""
		SUFFIX ".so"
		OUTPUT_NAME "hello"
)


target_include_directories(hello PRIVATE ${Python_INCLUDE_DIRS})
target_link_libraries(hello PRIVATE ${Python_LIBRARIES})

