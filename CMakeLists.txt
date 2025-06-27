cmake_minimum_required(VERSION 3.28)
project(hello C)

# Жёсткая привязка к Python 3.13
find_package(Python REQUIRED COMPONENTS Development)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/module)
# Настройки для .pyd
add_library(hello MODULE main.c)
set_target_properties(hello PROPERTIES
		PREFIX ""
		SUFFIX ".so"
		OUTPUT_NAME "hello"
)

# Подключение Python
target_include_directories(hello PRIVATE ${Python_INCLUDE_DIRS})
target_link_libraries(hello PRIVATE ${Python_LIBRARIES})

