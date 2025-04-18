# deep_ptr
Deep pointer for C++14 and above

# Usage

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