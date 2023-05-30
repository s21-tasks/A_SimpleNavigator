#pragma once

#include "../Helpers.h"

namespace s21 {

/**
 * @class BnB
 * @brief Implements the Branch and Bound algorithm for solving the Traveling
 * Salesman Problem.
 *
 * The BnB class represents the Branch and Bound algorithm for finding the
 * optimal solution to the Traveling Salesman Problem on a graph represented by
 * a matrix. The algorithm explores the solution space using a branch and bound
 * strategy to find the shortest tour. The class provides a method for running
 * the algorithm and accessing the result.
 * @tparam T The type of the matrix elements.
 */
template <class T>
class BnB {
 public:
  /**
   * @brief Constructor for the BnB class.
   *
   * Constructs a BnB object with the specified graph.
   *
   * @param graph The graph represented as a matrix.
   */
  BnB(const Matrix<T> &graph)
      : graph_(graph), size_(graph.GetCols()), route_(size_ + 1) {}

  /**
   * @brief Solve the Traveling Salesman Problem using the Branch and Bound
   * algorithm.
   *
   * This method runs the Branch and Bound algorithm to find the optimal tour
   * for the Traveling Salesman Problem. It returns the result as a TsmResult
   * object, which contains the best route found by the algorithm.
   *
   * @return The result of the Branch and Bound algorithm as a TsmResult object.
   */
  TsmResult Solve();

 private:
  const Matrix<T> &graph_;
  int size_;
  TsmResult result_;
  std::vector<int> route_;

  void BnBSearch(int current, double distance, std::vector<bool> visited);
  void UpdateResult(double distance);
  double LowerBound(int current, const std::vector<bool> &visited);
  void Initialization();
};

template <class T>
TsmResult BnB<T>::Solve() {
  Initialization();

  BnBSearch(0, 0.0, std::vector<bool>(size_, false));
  return result_;
}

template <class T>
void BnB<T>::Initialization() {
  std::iota(route_.begin(), route_.end(), 0);
  route_.back() = 0;

  result_.distance = std::numeric_limits<double>::infinity();
}

template <class T>
void BnB<T>::BnBSearch(int current, double distance,
                       std::vector<bool> visited) {
  if (distance >= result_.distance) {
    return;
  }

  if (current == size_ - 2) {
    UpdateResult(distance);
    return;
  }

  visited[route_[current]] = true;

  if (distance + LowerBound(current, visited) >= result_.distance) {
    return;
  }

  for (int next = current + 1; next < size_; ++next) {
    if (graph_(route_[current], route_[next]) != 0) {
      std::swap(route_[current + 1], route_[next]);
      BnBSearch(current + 1,
                graph_(route_[current], route_[current + 1]) + distance,
                visited);
      std::swap(route_[current + 1], route_[next]);
    }
  }
}

template <class T>
void BnB<T>::UpdateResult(double distance) {
  int last_1 = graph_(route_[size_ - 1], route_[size_]);
  int last_2 = graph_(route_[size_ - 2], route_[size_ - 1]);

  if (last_1 != 0 && last_2 != 0 &&
      (distance += last_1 + last_2) < result_.distance) {
    result_.distance = distance;
    result_.vertices = route_;
  }
}

template <class T>
double BnB<T>::LowerBound(int current, const std::vector<bool> &visited) {
  double lower_bound = 0.0;

  double smallest = std::numeric_limits<double>::infinity();

  for (int j = 1; j < size_; ++j) {
    if (!visited[j] && graph_(route_[current], j) > 0 &&
        smallest > (double)graph_(route_[current], j)) {
      smallest = (double)graph_(route_[current], j);
    }
  }
  lower_bound += smallest;

  for (int i = 1; i < size_; ++i) {
    if (!visited[i]) {
      smallest = std::numeric_limits<double>::infinity();

      if (graph_(i, 0) > 0 && smallest > (double)graph_(i, 0)) {
        smallest = (double)graph_(i, 0);
      }

      for (int j = 1; j < size_; ++j) {
        if (!visited[j]) {
          if (graph_(i, j) > 0 && smallest > (double)graph_(i, j)) {
            smallest = (double)graph_(i, j);
          }
          if (graph_(j, i) > 0 && smallest > (double)graph_(j, i)) {
            smallest = (double)graph_(j, i);
          }
        }
      }
      lower_bound += smallest;
    }
  }

  return lower_bound;
}

}  // namespace s21