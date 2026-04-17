#pragma once

#include <tuple>

template <typename... Ts> struct deep_ptr {
  static_assert(sizeof...(Ts) > 0,
                "deep_ptr requires at least one template parameter");

  constexpr deep_ptr(Ts... args) : ptrs{args...} {}

  template <typename U> constexpr decltype(auto) get(U &&object) const {
    return get_impl(std::forward<U>(object),
                    std::make_index_sequence<sizeof...(Ts)>{});
  }

private:
  template <typename U, std::size_t I>
  constexpr decltype(auto) get_impl(U &&object, std::index_sequence<I>) const {
    return std::forward<U>(object).*std::get<I>(ptrs);
  }

  template <typename U, std::size_t I1, std::size_t... IRest>
  constexpr decltype(auto) get_impl(U &&object,
                                    std::index_sequence<I1, IRest...>) const {
    return get_impl(
        get_impl(std::forward<U>(object), std::index_sequence<I1>{}),
        std::index_sequence<IRest...>{});
  }

  std::tuple<Ts...> ptrs;
};
