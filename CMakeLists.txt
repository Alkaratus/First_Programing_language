# CMakeList.txt: plik projektu CMake najwyższego poziomu, wykonaj konfigurację globalną
# i uwzględnij podprojekty w tym miejscu.
#
cmake_minimum_required (VERSION 3.8)

project (TKOMProject)

set(CMAKE_CXX_STANDARD 17)

# Uwzględnij podprojekty.
add_subdirectory("Source")
add_subdirectory ("Lexer")
add_subdirectory("Objects")
add_subdirectory("Parser")
add_subdirectory ("Overall")
add_subdirectory ("Main")
add_subdirectory("Token")
add_subdirectory("Validator")
add_subdirectory("Visitor")
add_subdirectory("Executives")
add_subdirectory("Runner")
add_subdirectory("Final_Functions")

enable_testing()
add_subdirectory("Tests")

