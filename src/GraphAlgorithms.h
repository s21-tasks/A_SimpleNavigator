#ifndef SIMPLENAVIGATOR_GRAPHALGORITHMS_H
#define SIMPLENAVIGATOR_GRAPHALGORITHMS_H

#include "Graph.h"
#include "AntColonyTSL/AntColonyTSL.h"

#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <limits>

namespace s21 {


  class GraphAlgorithms {

  public:
    static std::vector<int> depthFirstSearch(Graph &graph, int startVertex);
    static std::vector<int> breadthFirstSearch(Graph &graph, int startVertex);

    static int getShortestPathBetweenVertices(Graph &graph, int vertex1, int vertex2);
    static Matrix<int> getShortestPathsBetweenAllVertices(Graph &graph);
    static TsmResult solveTravelingSalesmanProblem(const Graph &graph);

    static std::vector<int> GetLeastSpanningTree(const Graph &graph);


  private:
    static void depthSearch(Graph &graph, int vertex, std::vector<int>& visited);
  };

} // s21

#endif //SIMPLENAVIGATOR_GRAPHALGORITHMS_H
