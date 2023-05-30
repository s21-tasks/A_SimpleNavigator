#pragma once

#include <chrono>
#include <functional>
#include <vector>

namespace s21 {

namespace Time {

typedef decltype((std::chrono::high_resolution_clock::now)()) T;

// T Now() {
//     return std::chrono::high_resolution_clock::now();
// }

typedef std::chrono::hours h;
typedef std::chrono::minutes min;
typedef std::chrono::seconds sec;
typedef std::chrono::milliseconds ms;
typedef std::chrono::microseconds mcs;
typedef std::chrono::nanoseconds ns;

template <class Unit = ms>
// int64_t Duration(T first, T second = Now()) {
int64_t Duration(T first,
                 T second = std::chrono::high_resolution_clock::now()) {
  return std::chrono::duration_cast<Unit>(second - first).count();
}

template <class Unit = ms>
int64_t Test(std::function<void(void)> test_func, int N = 1) {
  // T time_point = Now();
  T time_point = std::chrono::high_resolution_clock::now();
  for (int k = 0; k < N; ++k) {
    test_func();
  }
  return Duration(time_point) / (int64_t)N;
}

// template<typename... Args, typename =
// std::enable_if_t<std::conjunction_v<std::is_same<Args,
// std::function<void(void)>>...>>>
template <class... Args, class Unit = ms>
std::vector<int64_t> Compare(int N, Args... functions) {
  std::vector<int64_t> result(sizeof...(Args));
  int i = 0;
  ((result[i++] = Test<Unit>(functions, N)), ...);
  return result;
}

}  // namespace Time

}  // namespace s21
