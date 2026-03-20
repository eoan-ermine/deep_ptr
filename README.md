# deep_ptr
Deep pointers for C++14 and above

# Usage ([godbolt](https://godbolt.org/z/77MfnoheE))

```cpp
#include <deep_ptr/deep_ptr.hpp>
#include <iostream>

struct A {
  struct B {
    int p{5};
  } b;
};

int main() {
  A obj;
  deep_ptr<decltype(&A::b), decltype(&A::B::p)> ptr{&A::b, &A::B::p};
  int a = ptr.get(obj);
  std::cout << a << '\n'; // Output: 5
}
```
# CMake integration

## [FetchContent](https://cmake.org/cmake/help/latest/module/FetchContent.html)

```cmake
include(FetchContent)

FetchContent_Declare(
  deep_ptr
  GIT_REPOSITORY https://github.com/eoan-ermine/deep_ptr.git
  GIT_TAG master
  GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(deep_ptr)

target_link_libraries(${PROJECT_NAME} PRIVATE deep_ptr::deep_ptr)
```

## [CPM](https://github.com/cpm-cmake/CPM.cmake)

```cmake
include(cmake/CPM.cmake)

CPMAddPackage("gh:eoan-ermine/deep_ptr#master")

target_link_libraries(${PROJECT_NAME} PRIVATE deep_ptr::deep_ptr)
```
