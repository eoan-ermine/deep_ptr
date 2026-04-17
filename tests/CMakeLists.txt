CPMAddPackage("gh:doctest/doctest@2.4.12")

include("${doctest_SOURCE_DIR}/scripts/cmake/doctest.cmake")

enable_testing()

add_subdirectory(deep_ptr_test)
