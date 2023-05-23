#pragma once


#include "../GraphAlgorithms.h"
#include "../../Graph/Graph.h"
#include "../helpers.h"


namespace s21 {
  template<class T>
  class GeneticAlgorithm {

    const int POPULATION_SIZE = 100;
    const int NUM_ITERATIONS = 1500;
    const double MUTATION_RATE = 0.05;

    const Graph &graph;
    Matrix<int> population;

  public:
    GeneticAlgorithm() = delete;

    explicit GeneticAlgorithm(const Graph &graph_);

    TsmResult Execute();

  private:
    void GeneratePopulation();

    T RouteLength(int number);

    int SelectBestRoute();

    std::vector<int> Crossover(int parent1, int parent2);

    static void Mutate(Matrix<int> &matrix, int number);

  };


  template<class T>
  GeneticAlgorithm<T>::GeneticAlgorithm(const Graph &graph_) : graph(graph_) {}

  template<class T>
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

  template<class T>
  T GeneticAlgorithm<T>::RouteLength(int number) {
    T length = 0;
    for (int i = 0; i < population.GetCols() - 1; ++i) {
      length += graph(population(number, i), population(number, i + 1));
    }
    length += graph(population(number, population.GetCols() - 1), (population(number, 0)));
    return length;
  }

  template<class T>
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

  template<class T>
  std::vector<int> GeneticAlgorithm<T>::Crossover(int parent1, int parent2) {
    int n = (int) population.GetCols();
    int start = rand() % n;
    int end = rand() % n;
    if (end < start)
      std::swap(start, end);


    std::vector<int> child(n);
    for (int i = start; i <= end; i++) {
      child[i] = population(parent1, i);
    }
    int j = 0;
    for (int i = 0; i < n; i++) {
      if (j == start) {
        j = end + 1;
      }
      if (find(child.begin(), child.end(), population(parent2, i)) == child.end()) {
        child[j] = population(parent2, i);
        j++;
      }
    }
    return child;
  }

  template<class T>
  void GeneticAlgorithm<T>::Mutate(Matrix<int> &matrix, int number) {
    int n = matrix.GetCols();
    int i = rand() % n;
    int j = rand() % n;
    std::swap(matrix(number, i), matrix(number, j));
  }


  template<class T>
  TsmResult GeneticAlgorithm<T>::Execute() {
    GeneratePopulation();

    for (int iteration = 0; iteration < NUM_ITERATIONS; iteration++) {
      int best_route = SelectBestRoute();

      Matrix<int> new_population(POPULATION_SIZE, population.GetCols());
      for (int j = 0; j < new_population.GetCols(); ++j) {
        new_population(0, j) = population(best_route, j);
      }

      for (int i = 1; i < POPULATION_SIZE; ++i) {

        int parent1Index = Random::Int(1, POPULATION_SIZE);
        int parent2Index = Random::Int(1, POPULATION_SIZE);

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
    ans.distance = RouteLength(sol_index);
    return ans;
  }


}