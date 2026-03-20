project(deep_ptr_test)

add_executable(${PROJECT_NAME} ${PROJECT_NAME}.cpp)

target_link_libraries(${PROJECT_NAME} deep_ptr::deep_ptr doctest::doctest)

add_test(NAME ${PROJECT_NAME} COMMAND ${PROJECT_NAME})
