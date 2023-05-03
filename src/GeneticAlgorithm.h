//
// Created by Иван Захаров on 02.05.2023.
//

#ifndef SIMPLENAVIGATOR_GENETICALGORITHM_H
#define SIMPLENAVIGATOR_GENETICALGORITHM_H

#include "GraphAlgorithms.h"
#include "Graph.h"
#include "helpers.h"


namespace s21 {

  class GeneticAlgorithm {

    using graph_type = double;

    const int POPULATION_SIZE = 100;
    const int NUM_ITERATIONS = 1500;
    const double MUTATION_RATE = 0.05;

    Graph &graph;
    Matrix<int> population;

  public:
    GeneticAlgorithm() = delete;
    GeneticAlgorithm(Graph &graph_);

    TsmResult Execute();
    void GeneratePopulation();
    graph_type RouteLength (int number);
    int SelectBestRoute();
    std::vector<int> Crossover(int parent1, int parent2);
    static void Mutate(Matrix<int> &matrix,int number);




  };
}
#endif //SIMPLENAVIGATOR_GENETICALGORITHM_H
