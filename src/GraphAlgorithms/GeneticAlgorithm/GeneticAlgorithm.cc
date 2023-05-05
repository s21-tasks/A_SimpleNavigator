#include "GeneticAlgorithm.h"

using namespace s21;

GeneticAlgorithm::GeneticAlgorithm(Graph &graph_) : graph(graph_){}

using graph_type = double;


void GeneticAlgorithm::GeneratePopulation() {
  population = Matrix<int>(POPULATION_SIZE, graph.GraphSize());
  std::vector<int> temp_vector(population.GetCols());
  for (int j = 0; j < population.GetCols(); ++j) {
    temp_vector[j] = j;
  }
  for (int i = 0; i < population.GetRows(); ++i) {
    std::shuffle(temp_vector.begin(),temp_vector.end(), std::random_device());
    for (int j = 0; j < population.GetCols(); ++j) {
      population(i,j) = temp_vector[j];
    }
  }
}

graph_type GeneticAlgorithm::RouteLength(int number) {
  graph_type length = 0;
  for (int i = 0; i < population.GetCols() - 1; ++i) {
    length += graph(population(number,i),population(number,i+1));
  }
  length += graph(population(number,population.GetCols()-1),(population(number,0)));
  return length;
}

int GeneticAlgorithm::SelectBestRoute() {
  int bestRoute = 0;

  graph_type bestLength = RouteLength(0);
  for (int i = 1; i < POPULATION_SIZE; ++i) {

    graph_type length = RouteLength(i);
    if (length < bestLength) {
      bestRoute = i;
      bestLength = length;
    }
  }
  return bestRoute;
}

std::vector<int> GeneticAlgorithm::Crossover(int parent1, int parent2){
  int n = (int) population.GetCols();
  int start = rand() % n;
  int end = rand() % n;
  if (end < start)
    std::swap(start, end);


  std::vector<int> child(n);
  for (int i = start; i <= end; i++) {
    child[i] = population(parent1,i);
  }
  int j = 0;
  for (int i = 0; i < n; i++) {
    if (j == start) {
      j = end + 1;
    }
    if (find(child.begin(), child.end(), population(parent2,i)) == child.end()) {
      child[j] = population(parent2,i);
      j++;
    }
  }
  return child;
}

void GeneticAlgorithm::Mutate(Matrix<int> &matrix,int number) {
  int n = matrix.GetCols();
  int i = rand() % n;
  int j = rand() % n;
  std::swap(matrix(number,i), matrix(number,j));
}

TsmResult GeneticAlgorithm::Execute() {
  GeneratePopulation();

  for (int iteration = 0; iteration < NUM_ITERATIONS; iteration++) {
    int best_route = SelectBestRoute();

    Matrix<int> new_population(POPULATION_SIZE, population.GetCols());
    for (int j = 0; j < new_population.GetCols(); ++j) {
      new_population(0,j) = population(best_route, j);
    }

    for (int i = 1; i < POPULATION_SIZE; ++i) {

      int parent1Index = rand() % POPULATION_SIZE;
      int parent2Index = rand() % POPULATION_SIZE;

      std::vector<int> child = Crossover(parent1Index, parent2Index);

      for (int j = 0; j < child.size(); ++j) {
        new_population(i,j) = child[j];
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









