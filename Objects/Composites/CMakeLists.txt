set(_NAME Composites)


add_library(${_NAME}  
#"Conditional_Object.h" "Conditional_Object.cpp" 
#"Declarations_Object.h" "Declarations_Object.cpp"
#"Inspect_Object.h" "Inspect_Object.cpp"
"Scope_Object.h" "Scope_Object.cpp" 
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${_NAME} PROPERTY CXX_STANDARD 20)
endif()