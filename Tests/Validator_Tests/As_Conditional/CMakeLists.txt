set(TEST_FILE "As_Conditional.cpp")
set(TEST_NAME As_Conditional)

add_executable(${TEST_NAME} ${TEST_FILE})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${TEST_NAME} PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(${TEST_NAME} Validator)

add_test(${TEST_NAME} ${TEST_NAME})