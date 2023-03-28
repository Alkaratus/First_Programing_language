set(_NAME Inspect_Is_Conditionals)

add_library(${_NAME}
"Inspect_Is_Conditional_Object.h" "Inspect_Is_Conditional_Object.cpp"
"In_Conditional_Object.h" "In_Conditional_Object.cpp"
"Compare_Conditional_Object.h" "Compare_Conditional_Object.cpp" 
"Default_Conditional_Object.h" "Default_Conditional_Object.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${_NAME} PROPERTY CXX_STANDARD 20)
endif()