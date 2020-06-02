# CMakeList.txt: проект CMake для coutry; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("coutry")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (coutry "coutry.cpp" "coutry.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
