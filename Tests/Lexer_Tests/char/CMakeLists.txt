set(TEST_FILE "create_char.cpp")
set(TEST_NAME create_char)

add_executable(${TEST_NAME} ${TEST_FILE})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${TEST_NAME} PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(${TEST_NAME} Lexer)

add_test(${TEST_NAME} ${TEST_NAME})