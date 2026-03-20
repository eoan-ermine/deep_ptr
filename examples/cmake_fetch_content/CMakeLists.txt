cmake_minimum_required(VERSION 3.16)

project(cmake_fetch_content)

include(FetchContent)

FetchContent_Declare(
  deep_ptr
  GIT_REPOSITORY https://github.com/eoan-ermine/deep_ptr.git
  GIT_TAG master
  GIT_SHALLOW TRUE
)

if (NOT TARGET deep_ptr::deep_ptr)
	FetchContent_MakeAvailable(deep_ptr)
endif()

add_executable(cmake_fetch_content main.cpp)

target_link_libraries(cmake_fetch_content PRIVATE deep_ptr::deep_ptr)
