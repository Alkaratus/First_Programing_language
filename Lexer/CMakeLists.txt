set(_NAME Lexer)

add_library (${_NAME} 
"Lexer.h"
"Source_Lexer.h" "Source_Lexer.cpp" 
"Token_Collection.h" "Token_Collection.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${_NAME} PROPERTY CXX_STANDARD 20)
endif()


target_link_libraries(${_NAME} Token)
target_link_libraries(${_NAME} _Source)
