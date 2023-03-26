//
// Created by Иван Захаров on 25.03.2023.
//

#include "GraphAlgorithms.h"

namespace s21 {


std::vector<int> GraphAlgorithms::depthFirstSearch(s21::Graph &graph, int startVertex) {
  std::stack<int> st;
  std::vector<int> visited;
//  visited_matrix = Matrix<int>(graph.GraphSize(),graph.GraphSize());

//  depthSearch(graph, startVertex);
  for (int i = 0; i < graph.GraphSize(); ++i) {
    if (graph(startVertex,i) && std::find(visited.begin(), visited.end(),i) == visited.end())
      st.push(i);
  }

//  std::cout << startVertex << std::endl;

  while (!st.empty()) {
    if (std::find(visited.begin(), visited.end(),st.top()) == visited.end()) {
      auto temp = depthFirstSearch(graph, st.top());
      std::move(temp.begin(), temp.end(), std::back_inserter(visited));
    }
    st.pop();
  }
  return visited;
}

void GraphAlgorithms::depthSearch(Graph &graph, int vertex) {
  visited.push_back(startVertex);

  for (int i = 0; i < graph.GraphSize(); ++i) {
    if (graph(startVertex,i) && std::find(visited.begin(), visited.end(),i) == visited.end())
      st.push(i);
  }

}


} // s21