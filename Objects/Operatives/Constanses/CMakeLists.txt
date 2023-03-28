set(_NAME Constanses)

add_library(${_NAME} 
"Constans_Object.h" "Constans_Object.cpp" 
"Char_Object.h" "Char_Object.cpp"
"Int_Object.h" "Int_Object.cpp" 
"Float_Object.cpp" "Float_Object.h" 
"String_Object.h" "String_Object.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${_NAME} PROPERTY CXX_STANDARD 20)
endif()