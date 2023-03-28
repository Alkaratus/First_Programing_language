set(_NAME Objects)

add_subdirectory("Composites")
add_subdirectory("Dependent")
add_subdirectory("Inspect_Conditionals")
add_subdirectory("Operatives")
add_subdirectory("Scopeds")
add_subdirectory("Sets")

add_library(${_NAME} 
"Complilation_Object.h" "Complilation_Object.cpp"
"Variable_Object.h" "Variable_Object.cpp" 
"Include_Object.h" "Include_Object.cpp" 
"Conditional_Object.h" "Conditional_Object.cpp" 
"Inspect_Object.h" "Inspect_Object.cpp" 
"Return_Object.h" "Return_Object.cpp" 
"Declarations_Object.h" "Declarations_Object.cpp"
 "Composites/Scope_Object.h" "Composites/Scope_Object.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${_NAME} PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(${_NAME} Composites)
target_link_libraries(${_NAME} Dependent)
target_link_libraries(${_NAME} Inspect_Conditionals)
target_link_libraries(${_NAME} Operatives)
target_link_libraries(${_NAME} Sets)
target_link_libraries(${_NAME} Scopeds)
target_link_libraries(${_NAME} Token)
target_link_libraries(${_NAME} Visitor)