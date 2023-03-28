set(_NAME Executives)

add_library ( ${_NAME}
"Executive.h"  
"Executive_File.h" "Executive_File.cpp" 
"Executive_Code.h" "Executive_Code.cpp" 
)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${_NAME} PROPERTY CXX_STANDARD 20)
endif()