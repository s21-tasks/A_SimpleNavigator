#pragma once

#include "Graph.h"
#include <algorithm>
#include "GeneticAlgorithm/GeneticAlgorithm.h"
#include "AntColonyAlgorithm/AntColonyTSL.h"
#include "helpers.h"

namespace s21 {

  class GraphAlgorithms {

  public:
    static std::vector<int> depthFirstSearch(const Graph &graph, const int startVertex);
    static std::vector<int> breadthFirstSearch(const Graph &graph, const int startVertex);

    static int getShortestPathBetweenVertices(const Graph &graph,const int vertex1,const int vertex2);
    static Matrix<int> getShortestPathsBetweenAllVertices(const Graph &graph);
    static std::vector<int> GetLeastSpanningTree(const Graph &graph);
    static TsmResult solveTravelingSalesmanProblem(const Graph &graph);
    static TsmResult GeneticSolveSalesmanProblem(const Graph &graph);


  private:
    static void depthSearch(const Graph &graph, const int vertex, std::vector<int>& visited);


  };



} // s21