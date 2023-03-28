set(_NAME Overall)

add_library(${_NAME}
"File.h" "File.cpp"
"Position.h" "Position.cpp" 
"Compile_message.h" "Compile_message.cpp"
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${_NAME} PROPERTY CXX_STANDARD 20)
endif()