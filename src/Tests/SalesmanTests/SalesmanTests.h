#pragma once

#include <list>

#include "../Test.h"
#include "Compare.h"
#include "GraphAlgorithms.h"

namespace s21 {

class AlgorithmsGT : public GT {
 protected:
  void Test() {
    std::vector<TsmResult> results{
        GraphAlgorithms::BnBSolveSalesmanProblem(graph_),
        GraphAlgorithms::GeneticSolveSalesmanProblem(graph_),
        GraphAlgorithms::solveTravelingSalesmanProblem(graph_)};

    for (int k = 0; k < results.size(); ++k) {
      double d = results[k].distance;
      const auto &vertices = results[k].vertices;
      if (d != std::numeric_limits<double>::infinity()) {
        ASSERT_EQ(vertices.size(), graph_.Size() + 1);
        ASSERT_TRUE(d > 0 && d < std::get<3>(GetParam()) * graph_.Size());
        if (k != results.size() - 1) {
          ASSERT_NEAR(d, results[k + 1].distance, d / 10);
        } else {
          ASSERT_NEAR(d, results[0].distance, d / 10);
        }

        double check = 0;
        for (int g = 0; g <= graph_.Size() - 1; ++g) {
          int weight = graph_(vertices[g], vertices[g + 1]);
          check += weight;
          ASSERT_TRUE(weight != 0);
        }
        ASSERT_NEAR(d, check, d / 1e3);
      }
    }
  }

 public:
  AlgorithmsGT() : GT() {}
};

class FileSalesmanGT : public FileGT {
 protected:
  int salesman_loop_count_ = 1;
  double salesman_distance_ = -1.0;

  void Tester() override {
    auto compare_result = Compare::Full(graph_, salesman_loop_count_);

    if (salesman_distance_ < 0) {
      salesman_distance_ = *std::min_element(compare_result.mean.begin(),
                                             compare_result.mean.end());
    }

    ASSERT_NEAR(compare_result.mean[0], salesman_distance_,
                salesman_distance_ / 10);
    ASSERT_NEAR(compare_result.mean[1], salesman_distance_,
                salesman_distance_ / 10);
    ASSERT_NEAR(compare_result.mean[2], salesman_distance_,
                salesman_distance_ / 10);

    std::cout << "\n\t\tgraph size = " << graph_.Size();
    std::cout << "\nAnt colony:\n\tTime: " << compare_result.time[0]
              << " ms\n\tMean: " << compare_result.mean[0];
    std::cout << "\nGenetic:\n\tTime: " << compare_result.time[1]
              << " ms\n\tMean: " << compare_result.mean[1];
    std::cout << "\nBranch and Bounds:\n\tTime: " << compare_result.time[2]
              << " ms\n\tMean: " << compare_result.mean[2];
    std::cout << "\n\n";
  }
};

}  // namespace s21
