# CMakeList.txt: plik projektu CMake najwy¿szego poziomu, wykonaj konfiguracjê globaln¹
# i uwzglêdnij podprojekty w tym miejscu.
#
cmake_minimum_required (VERSION 3.8)


# Uwzglêdnij podprojekty.
add_subdirectory("char")
add_subdirectory("escape_char")
add_subdirectory("invalid_escape_char")
add_subdirectory("invalid_char")
add_subdirectory("string")
add_subdirectory("not_ended_string")
add_subdirectory("zero")
add_subdirectory("integer")
add_subdirectory("double")
add_subdirectory("invalid_double")
add_subdirectory("keyword")
add_subdirectory("name")
add_subdirectory("single_operator")
add_subdirectory("double_operator")
add_subdirectory("invalid_operator")
add_subdirectory("line_comment")
add_subdirectory("scope_comment")
add_subdirectory("invalid_scope_comment")
add_subdirectory("invalid_scope_comment2")
add_subdirectory("slash")
add_subdirectory("unknown_sign")