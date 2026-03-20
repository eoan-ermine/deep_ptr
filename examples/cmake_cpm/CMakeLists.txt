cmake_minimum_required(VERSION 3.16)

project(cmake_cpm)

include(cmake/CPM.cmake)

if (NOT TARGET deep_ptr::deep_ptr)
	CPMAddPackage("gh:eoan-ermine/deep_ptr#master")
endif()

add_executable(cmake_cpm main.cpp)

target_link_libraries(cmake_cpm PRIVATE deep_ptr::deep_ptr)
