set(_NAME Token)

add_library (${_NAME} 
"Token.h" "Token.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${_NAME} PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(${_NAME} Overall)
