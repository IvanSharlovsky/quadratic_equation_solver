cmake_minimum_required(VERSION 3.0.0)
project(quadratic_equation_solver VERSION 0.1.0 LANGUAGES C)    # 'LANGUAGES C' указываем язык C, чтобы CMake не искал компилятор языка C++

get_directory_property(IS_SUBPROJECT PARENT_DIRECTORY)          # Проверить, включён ли наш проект в другой проект в качестве подпроекта

include(CTest)
enable_testing()

set(SOURCE_EXE quadratic_equation_solver.c)		                # Установка переменной со списком исходников для исполняемого файла
set(SOURCE_LIB clear_buffer.c)		                        # Тоже самое, но для библиотеки

add_library(clear_buffer STATIC ${SOURCE_LIB})                  # Создание статической библиотеки с именем clear_buffer
add_executable(quadratic_equation_solver quadratic_equation_solver.c) # Создает исполняемый файл с именем quadratic_equation_solver

target_link_libraries(quadratic_equation_solver clear_buffer)	# Линковка программы с библиотекой

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)