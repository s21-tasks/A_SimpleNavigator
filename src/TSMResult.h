#pragma once

#include <vector>

namespace s21 {

struct TsmResult {
    std::vector<int> vertices;
    double distance = 0;

    TsmResult(double d, const std::vector<int> &v) : distance(d) , vertices(v) {}

    void operator=(const TsmResult &other) {
        vertices = other.vertices;
        distance = other.distance;
    }
};

} // namespace s21