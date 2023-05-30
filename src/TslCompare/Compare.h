#pragma once

#include "Graph.h"
#include "GraphAlgorithms.h"
#include "Utility.h"

namespace s21 {

/**
 * @typedef TimeResult
 * @brief Represents a vector of integers for storing time results.
 *
 * TimeResult is a typedef for std::vector<int64_t> used to store time results.
 * Each element in the vector represents the time taken for a specific operation
 * or computation.
 */
typedef std::vector<int64_t> TimeResult;

/**
 * @struct CompareResult
 * @brief Represents the result of a comparison between algorithms or
 * configurations.
 *
 * CompareResult is a structure that holds the result of a comparison between
 * algorithms or configurations. It contains two main components: the time
 * results and the mean values. The time member is a TimeResult object that
 * stores the time taken for each operation or computation. The mean member is a
 * vector of doubles that represents the mean values calculated from the time
 * results. The size of the mean vector is determined by the parameter N
 * specified during construction.
 * @param N The number of algorithms or configurations being compared.
 */
struct CompareResult {
  TimeResult time;
  std::vector<double> mean;
  CompareResult(int N) : mean(N) {}
};

class Compare {
 public:
  /**
   * @brief Compare the results of different salesman algorithms.
   *
   * This static method performs a time comparison between the results of BnB,
   * Ant Colony, and Genetic algorithms. It measures the execution time of each
   * algorithm on a given graph. The result is returned as a TimeResult.
   *
   * @param G The graph on which the algorithm will be executed.
   * @param N The number of times to run the algorithm and collect time results.
   * @return A TimeResult object storing the time results.
   */
  static TimeResult Time(Graph &G, int N);
  /**
   * @brief Compare the results of different salesman algorithms.
   *
   * This static method performs a full comparison between the results of BnB,
   * Ant Colony, and Genetic algorithms. It measures the execution time of each
   * algorithm on a given graph and collects the mean values of the time
   * results. The result is returned as a CompareResult object containing the
   * time results and mean values.
   *
   * @param G The graph on which the algorithms will be executed.
   * @param N The number of times to run each algorithm and collect time
   * results.
   * @return A CompareResult object containing the time results and mean values.
   */
  static CompareResult Full(Graph &G, int N);
};

}  // namespace s21
