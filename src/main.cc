#include "Graph/Graph.h"
#include "GraphAlgorithms/GraphAlgorithms.h"
//#include "MainMenu.h"
using namespace s21;


void print(std::vector<int> &vector)
{
  for (auto i: vector) {
    std::cout << i << ' ';
  }
  std::cout << std::endl;
}

int foo(int val) {
  return val*2;
}

float RandomNumber() {
  float ans = float(rand()) / float(RAND_MAX);
  srand(ans * RAND_MAX);
  return ans;
}

int main() {
  Graph graph("graph.txt");
  GraphAlgorithms ga;
  auto sol = ga.GeneticSolveSalesmanProblem(graph);
  std::cout << sol.distance << std::endl;
  return 0;

}
