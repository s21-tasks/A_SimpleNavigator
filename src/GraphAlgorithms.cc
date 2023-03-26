//
// Created by Иван Захаров on 25.03.2023.
//

#include "GraphAlgorithms.h"

namespace s21 {


std::vector<int> GraphAlgorithms::depthFirstSearch(s21::Graph &graph, int startVertex) {
  std::vector<int> visited;
  depthSearch(graph, startVertex, visited);
  return visited;
}

void GraphAlgorithms::depthSearch(Graph &graph, int vertex, std::vector<int>& visited) {
  std::stack<int> st;
  visited.push_back(vertex);
  for (int i = graph.GraphSize()-1; i >=0 ; --i) {
    if (graph(vertex,i))
      st.push(i);
  }
  while (!st.empty()) {
    if (std::find(visited.begin(), visited.end(),st.top()) == visited.end()) {
      depthSearch(graph, st.top(), visited);
    }
    st.pop();
  }
}

std::vector<int> GraphAlgorithms::breadthFirstSearch(Graph &graph, int startVertex) {

}


} // s21