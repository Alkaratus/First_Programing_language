set(_NAME Sets)

add_library(${_NAME}
"Set_Object.h" "Set_Object.cpp"
"Colection_Object.h" "Colection_Object.cpp" 
"Zone_Object.h" "Zone_Object.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${_NAME} PROPERTY CXX_STANDARD 20)
endif()