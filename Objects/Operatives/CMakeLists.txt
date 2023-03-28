set(_NAME Operatives)

add_subdirectory("Constanses")

add_library(${_NAME} 
"Operative_Object.cpp" "Operative_Object.h" 
"Function_Call_Object.h" "Function_Call_Object.cpp" 
"Variable_Call_Object.h" "Variable_Call_Object.cpp" 
"Operation_Object.h" "Operation_Object.cpp" 
"In_Set_Object.h" "In_Set_Object.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${_NAME} PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(${_NAME} Constanses)