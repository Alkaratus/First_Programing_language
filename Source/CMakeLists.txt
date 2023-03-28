set(_NAME _Source)

add_library ( ${_NAME}
"Source.h" "Source.cpp" 
"Source_File.h" "Source_File.cpp" 
"Source_String.h" "Source_String.cpp" 
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${_NAME} PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(${_NAME} Overall)