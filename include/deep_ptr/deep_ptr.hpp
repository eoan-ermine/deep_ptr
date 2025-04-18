#include <tuple>

template <typename... Ts> struct deep_ptr {
  constexpr deep_ptr(Ts... args) : ptrs{args...} {}

  template <typename U, std::size_t I>
  auto get_impl(U &&object, std::index_sequence<I>) {
    return (std::forward<U>(object)).*(std::get<I>(ptrs));
  }

  template <typename U, std::size_t I1, std::size_t... IRest>
  auto get_impl(U &&object, std::index_sequence<I1, IRest...>) {
    return get_impl(
        get_impl<U>(std::forward<U>(object), std::index_sequence<I1>{}),
        std::index_sequence<IRest...>{});
  }

  template <typename U> auto get(U &object) {
    return get_impl(object, std::make_index_sequence<sizeof...(Ts)>{});
  }

  std::tuple<Ts...> ptrs;
};
