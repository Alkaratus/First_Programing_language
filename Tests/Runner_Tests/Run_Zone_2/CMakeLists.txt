set(TEST_FILE "Run_Zone_2.cpp")
set(TEST_NAME Run_Zone_2)

add_executable(${TEST_NAME} ${TEST_FILE})

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET ${TEST_NAME} PROPERTY CXX_STANDARD 20)
endif()

target_link_libraries(${TEST_NAME} PRIVATE Validator)
target_link_libraries(${TEST_NAME} PRIVATE Runner)

add_test(${TEST_NAME} ${TEST_NAME})