#ifndef SIMPLENAVIGATOR_GRAPHALGORITHMS_H
#define SIMPLENAVIGATOR_GRAPHALGORITHMS_H

#include "../Graph/Graph.h"
//#include <algorithm>
#include "GeneticAlgorithm/GeneticAlgorithm.h"
#include "../helpers.h"

namespace s21 {



  class GraphAlgorithms {

  public:
    std::vector<int> depthFirstSearch(Graph &graph, int startVertex);
    std::vector<int> breadthFirstSearch(Graph &graph, int startVertex);

    int getShortestPathBetweenVertices(Graph &graph, int vertex1, int vertex2);
    Matrix<int> getShortestPathsBetweenAllVertices(Graph &graph);
//    TsmResult solveTravelingSalesmanProblem(Graph &graph);
    TsmResult GeneticSolveSalesmanProblem(Graph &graph);


  private:
    void depthSearch(Graph &graph, int vertex, std::vector<int>& visited);
  };



} // s21

#endif //SIMPLENAVIGATOR_GRAPHALGORITHMS_H
