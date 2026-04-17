#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "deep_ptr/deep_ptr.hpp"
#include "doctest/doctest.h"

#include <type_traits>

struct A {
  struct B {
    int p{5};
  } b;
};

TEST_CASE("testing the type of deep_ptr::get return value") {
  A obj;
  deep_ptr<decltype(&A::b), decltype(&A::B::p)> ptr{&A::b, &A::B::p};
  CHECK(std::is_same<int &, decltype(ptr.get(obj))>::value);
}