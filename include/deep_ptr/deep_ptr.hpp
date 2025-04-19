#include <tuple>

template <typename... Ts> struct deep_ptr {
  constexpr deep_ptr(Ts... args) : ptrs{args...} {}

  template <typename U> constexpr auto get(U &&object) {
    return get_impl(object, std::make_index_sequence<sizeof...(Ts)>{});
  }

private:
  template <typename U, std::size_t I>
  constexpr auto get_impl(U &&object, std::index_sequence<I>) {
    return (std::forward<U>(object)).*(std::get<I>(ptrs));
  }

  template <typename U, std::size_t I1, std::size_t... IRest>
  constexpr auto get_impl(U &&object, std::index_sequence<I1, IRest...>) {
    return get_impl(
        get_impl<U>(std::forward<U>(object), std::index_sequence<I1>{}),
        std::index_sequence<IRest...>{});
  }

  std::tuple<Ts...> ptrs;
};
