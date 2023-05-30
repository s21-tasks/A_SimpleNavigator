#pragma once

#include "../Test.h"

namespace s21 {

class GraphGT : public GT {
 public:
  GraphGT() : GT() {}

  void Tester() {
    int max = 0;
    for (int k = 0; k < graph_.Size(); ++k) {
      for (int g = 0; g < graph_.Size(); ++g) {
        if (k == g) {
          ASSERT_EQ(graph_(k, g), 0);
        }
        if (!std::get<0>(GetParam())) {
          ASSERT_EQ(graph_(k, g), graph_(g, k));
        }
        if (graph_(k, g) > max) {
          max = graph_(k, g);
        }
        ASSERT_GE(graph_(k, g), 0);
        if (std::get<2>(GetParam()) == 0.0 && k != g) {
          ASSERT_TRUE(graph_(k, g) != 0.0);
        } else if (std::get<2>(GetParam()) == 1.0) {
          ASSERT_FLOAT_EQ(graph_(k, g), 0.0);
        }
      }
    }
    ASSERT_LE(max, std::get<3>(GetParam()));
  }
};

}  // namespace s21
