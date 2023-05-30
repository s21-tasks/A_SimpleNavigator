#pragma once

#include "../../Graph/Graph.h"
#include "../GraphAlgorithms.h"
#include "../Helpers.h"

namespace s21 {

/**
 * @class GeneticAlgorithm
 * @brief Implements the Genetic Algorithm for solving the Traveling Salesman
 * Problem. The GeneticAlgorithm class represents the Genetic Algorithm for
 * finding an approximate solution to the Traveling Salesman Problem on a given
 * graph. The algorithm evolves a population of routes through selection,
 * crossover, and mutation operations to improve the quality of the solutions.
 * The class provides methods for executing the algorithm and accessing the
 * result.
 * @tparam T The type of the graph elements.
 */
template <class T>
class GeneticAlgorithm {
  const int POPULATION_SIZE = 100;
  const int NUM_ITERATIONS = 1500;
  const double MUTATION_RATE = 0.05;

  Graph graph;
  Matrix<int> population;
  int maxi_size;

 public:
  /**
   * @brief Deleted default constructor.
   *
   * The default constructor is deleted to prevent creating an instance without
   * a graph.
   */
  GeneticAlgorithm() = delete;

  /**
   * @brief Constructor for the GeneticAlgorithm class.
   *
   * Constructs a GeneticAlgorithm object with the specified graph.
   *
   * @param graph The graph to solve the Traveling Salesman Problem.
   */
  explicit GeneticAlgorithm(const Graph &graph_);

  /**
   * @brief Execute the Genetic Algorithm to solve the Traveling Salesman
   * Problem.
   *
   * This method runs the Genetic Algorithm to find an approximate solution to
   * the Traveling Salesman Problem. It evolves a population of routes through
   * selection, crossover, and mutation operations to improve the quality of the
   * solutions. The result is returned as a TsmResult object, which contains the
   * best route found by the algorithm.
   *
   * @return The result of the Genetic Algorithm as a TsmResult object.
   */
  TsmResult Execute();

 private:
  void GeneratePopulation();

  T RouteLength(int number);

  int SelectBestRoute();

  std::vector<int> Crossover(int parent1, int parent2);

  static void Mutate(Matrix<int> &matrix, int number);
};

template <class T>
GeneticAlgorithm<T>::GeneticAlgorithm(const Graph &graph_)
    : graph(graph_), maxi_size(0) {
  for (int i = 0; i < graph.Size(); ++i) {
    for (int j = 0; j < graph.Size(); ++j) {
      maxi_size += graph(i, j);
    }
  }
  for (int i = 0; i < graph.Size(); ++i) {
    for (int j = 0; j < graph.Size(); ++j) {
      if (!graph(i, j)) graph(i, j) = maxi_size;
    }
  }
}

template <class T>
void GeneticAlgorithm<T>::GeneratePopulation() {
  population = Matrix<int>(POPULATION_SIZE, graph.Size());
  std::vector<int> temp_vector(population.GetCols());
  for (int j = 0; j < population.GetCols(); ++j) {
    temp_vector[j] = j;
  }
  for (int i = 0; i < population.GetRows(); ++i) {
    std::shuffle(temp_vector.begin(), temp_vector.end(), std::random_device());
    for (int j = 0; j < population.GetCols(); ++j) {
      population(i, j) = temp_vector[j];
    }
  }
}

template <class T>
T GeneticAlgorithm<T>::RouteLength(int number) {
  T length = 0;
  for (int i = 0; i < population.GetCols() - 1; ++i) {
    length += graph(population(number, i), population(number, i + 1));
  }
  length += graph(population(number, population.GetCols() - 1),
                  (population(number, 0)));
  return length;
}

template <class T>
int GeneticAlgorithm<T>::SelectBestRoute() {
  int bestRoute = 0;

  T bestLength = RouteLength(0);
  for (int i = 1; i < POPULATION_SIZE; ++i) {
    T length = RouteLength(i);
    if (length < bestLength) {
      bestRoute = i;
      bestLength = length;
    }
  }
  return bestRoute;
}

template <class T>
std::vector<int> GeneticAlgorithm<T>::Crossover(int parent1, int parent2) {
  int n = (int)population.GetCols();
  int start = rand() % n;
  int end = rand() % n;
  if (end < start) std::swap(start, end);

  std::vector<int> child(n);
  for (int i = start; i <= end; i++) {
    child[i] = population(parent1, i);
  }
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (j == start) {
      j = end + 1;
    }
    if (find(child.begin(), child.end(), population(parent2, i)) ==
        child.end()) {
      child[j] = population(parent2, i);
      j++;
    }
  }
  return child;
}

template <class T>
void GeneticAlgorithm<T>::Mutate(Matrix<int> &matrix, int number) {
  int n = matrix.GetCols();
  int i = rand() % n;
  int j = rand() % n;
  std::swap(matrix(number, i), matrix(number, j));
}

template <class T>
TsmResult GeneticAlgorithm<T>::Execute() {
  GeneratePopulation();

  for (int iteration = 0; iteration < NUM_ITERATIONS; iteration++) {
    int best_route = SelectBestRoute();

    Matrix<int> new_population(POPULATION_SIZE, population.GetCols());
    for (int j = 0; j < new_population.GetCols(); ++j) {
      new_population(0, j) = population(best_route, j);
    }

    for (int i = 1; i < POPULATION_SIZE; ++i) {
      int parent1Index = Random::Int(0, POPULATION_SIZE - 1);
      int parent2Index = Random::Int(0, POPULATION_SIZE - 1);

      std::vector<int> child = Crossover(parent1Index, parent2Index);

      for (int j = 0; j < child.size(); ++j) {
        new_population(i, j) = child[j];
      }
      if (rand() < MUTATION_RATE * RAND_MAX) {
        Mutate(new_population, i);
      }
    }
    population = std::move(new_population);
  }
  int sol_index = SelectBestRoute();

  TsmResult ans;
  ans.vertices = std::vector<int>(population.GetCols());
  for (int i = 0; i < population.GetCols(); ++i) {
    ans.vertices[i] = population(sol_index, i);
  }
  ans.vertices.push_back(ans.vertices[0]);
  ans.distance = RouteLength(sol_index);
  if (ans.distance > maxi_size) {
    ans.distance = std::numeric_limits<float>::infinity();
    ans.vertices = std::vector<int>();
  }

  return ans;
}

}  // namespace s21