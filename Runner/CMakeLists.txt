set(_NAME Runner)

add_library ( ${_NAME}
"Splited_Line.h" "Splited_Line.cpp"
"Runner.h" "Runner.cpp"
"Library_Functions.h" "Library_Functions.cpp"
"Operations.h" "Operations.cpp"
 "As_converters.h" "As_converters.cpp"  
 "Executor.h" "Executor.cpp" 
 "Structured_Operations.h" "Structured_Operations.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${_NAME} PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(${_NAME} Executives)