cmake_minimum_required(VERSION 3.16)

project(deep_ptr VERSION 1.0.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 14)

# Define the library target
add_library(deep_ptr INTERFACE)
add_library(deep_ptr::deep_ptr ALIAS deep_ptr)
target_include_directories(deep_ptr INTERFACE 
    $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    "${PROJECT_BINARY_DIR}/deep_ptrConfigVersion.cmake"
    VERSION 1.0.0
    COMPATIBILITY AnyNewerVersion
)

install(TARGETS deep_ptr
    EXPORT deep_ptrTargets
    LIBRARY DESTINATION lib COMPONENT Runtime
    ARCHIVE DESTINATION lib COMPONENT Development
    RUNTIME DESTINATION bin COMPONENT Runtime
    PUBLIC_HEADER DESTINATION include COMPONENT Development
    BUNDLE DESTINATION bin COMPONENT Runtime
)

include(CMakePackageConfigHelpers)
configure_package_config_file(
    "${PROJECT_SOURCE_DIR}/cmake/deep_ptrConfig.cmake.in"
    "${PROJECT_BINARY_DIR}/deep_ptrConfig.cmake"
    INSTALL_DESTINATION lib/cmake/deep_ptr
)

install(EXPORT deep_ptrTargets DESTINATION lib/cmake/deep_ptr)
install(FILES "${PROJECT_BINARY_DIR}/deep_ptrConfigVersion.cmake"
              "${PROJECT_BINARY_DIR}/deep_ptrConfig.cmake"
        DESTINATION lib/cmake/deep_ptr)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ DESTINATION include)
