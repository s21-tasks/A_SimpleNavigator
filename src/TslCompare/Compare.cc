#include "Compare.h"

namespace s21 {

TimeResult Compare::Time(Graph &G, int N) {
  return Time::Compare(
      N, [&] { GraphAlgorithms::solveTravelingSalesmanProblem(G); },
      [&] { GraphAlgorithms::GeneticSolveSalesmanProblem(G); },
      [&] { GraphAlgorithms::BnBSolveSalesmanProblem(G); });
}

CompareResult Compare::Full(Graph &G, int N) {
  CompareResult result(3);
  result.time = std::move(Time::Compare(
      N,
      [&] {
        result.mean[0] +=
            GraphAlgorithms::solveTravelingSalesmanProblem(G).distance /
            (double)N;
      },
      [&] {
        result.mean[1] +=
            GraphAlgorithms::GeneticSolveSalesmanProblem(G).distance /
            (double)N;  // 2 algorithm in 0 place
      },
      [&] {
        result.mean[2] +=
            GraphAlgorithms::BnBSolveSalesmanProblem(G).distance / (double)N;
      }));
  return result;
}

}  // namespace s21

using namespace s21;
