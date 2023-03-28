set(_NAME Dependent)

add_library(${_NAME} 
"Type_Object.h" "Type_Object.cpp"
"Operator_Object.h" "Operator_Object.cpp" 
"Variable_Essence.h" "Variable_Essence.cpp"
 "Function_Argument.h" "Function_Argument.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${_NAME} PROPERTY CXX_STANDARD 20)
endif()
