set(_NAME Inspect_Conditionals)

add_subdirectory("Inspect_Is_Conditionals")

add_library(${_NAME}
"Inspect_Conditional_Object.h" "Inspect_Conditional_Object.cpp"
 "Is_Conditional_Object.h" "Is_Conditional_Object.cpp" 
 "As_Conditional_Object.h" "As_Conditional_Object.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${_NAME} PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(${_NAME} Inspect_Is_Conditionals)