//
// Created by Иван Захаров on 25.03.2023.
//

#ifndef SIMPLENAVIGATOR_GRAPHALGORITHMS_H
#define SIMPLENAVIGATOR_GRAPHALGORITHMS_H

#include "Graph.h"

namespace s21 {

  struct TsmResult {
    int* vertices;    // массив с искомым маршрутом (с порядком обхода вершин). Вместо int* можно использовать std::vector<int>
    double distance;  // длина этого маршрута
  };


  class GraphAlgorithms {

//    Matrix<int> visited_matrix;
//    std::stack<int> st;


  public:
    std::vector<int> depthFirstSearch(Graph &graph, int startVertex);
    std::vector<int> breadthFirstSearch(Graph &graph, int startVertex);

    int getShortestPathBetweenVertices(Graph &graph, int vertex1, int vertex2);
    Matrix<int> getShortestPathsBetweenAllVertices(Graph &graph);
//    TsmResult solveTravelingSalesmanProblem(Graph &graph);


  private:
    void depthSearch(Graph &graph, int vertex, std::vector<int>& visited);
  };



} // s21

#endif //SIMPLENAVIGATOR_GRAPHALGORITHMS_H
