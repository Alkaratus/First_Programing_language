set(TEST_FILE "In_Set.cpp")
set(TEST_NAME In_Set)

add_executable(${TEST_NAME} ${TEST_FILE})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${TEST_NAME} PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(${TEST_NAME} Validator)

add_test(${TEST_NAME} ${TEST_NAME})