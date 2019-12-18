cmake_minimum_required(VERSION 2.8)	 

project(encdec)			# Название проекта

set(SOURCE_EXE main.cpp)		# Установка переменной со списком исходников для исполняемого файла

set(SOURCE_LIB enc.cpp dec.cpp working_with_file.cpp)			# Тоже самое, но для библиотеки

add_library(my_lib STATIC ${SOURCE_LIB})	# Создание статической библиотеки с именем foo

add_executable(encdec ${SOURCE_EXE})	# Создает исполняемый файл с именем main

target_link_libraries(encdec my_lib)
