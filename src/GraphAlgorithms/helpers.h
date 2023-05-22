#pragma once

#include <vector>

namespace s21 {

  struct TsmResult {
    std::vector<int> vertices;
    double distance = 0;

    TsmResult() = default;
    TsmResult(double d, const std::vector<int> &v) : distance(d) , vertices(v) {}

    TsmResult& operator=(const TsmResult &other) {
      vertices = other.vertices;
      distance = other.distance;
      return *this;
    }
    bool operator<(const TsmResult &other) const {
      return distance < other.distance;
    }
  };

} // namespace s21