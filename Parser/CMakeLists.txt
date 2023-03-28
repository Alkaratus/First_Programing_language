set(_NAME Parser)

add_library(${_NAME} 
"Objects_Tree.h" "Objects_Tree.cpp" 
"Parser.h" "Parser.cpp" 
"Real_Parser.h" "Real_Parser.cpp" 
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${_NAME} PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(${_NAME} PRIVATE Lexer)
target_link_libraries(${_NAME} PRIVATE Objects)