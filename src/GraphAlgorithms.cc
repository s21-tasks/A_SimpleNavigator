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
  std::queue<int> q;
  std::vector<int> visited;
  q.push(startVertex);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    if (std::find(visited.begin(), visited.end(),v) == visited.end())
      visited.push_back(v);
    for (int i = 0; i < graph.GraphSize(); ++i) {
        if (graph(v,i) && std::find(visited.begin(), visited.end(),i) == visited.end())
          q.push(i);
    }
  }
  return visited;
}

int GraphAlgorithms::getShortestPathBetweenVertices(Graph &graph, int vertex1, int vertex2) {
  std::vector<int> path_size(graph.GraphSize(), INT_MAX);
  std::vector<bool> visited(graph.GraphSize(), false);
  path_size[vertex1] = 0;
  int vert = INT_MAX;
  int vert_index = vertex1;
  do {
    vert = INT_MAX;
    for (int i = 0; i < graph.GraphSize(); ++i) {
      if (!visited[i] && path_size[i] < vert) {
        vert = path_size[i];
        vert_index = i;
      }
    }
    for (int i = 0; i < graph.GraphSize(); ++i) {
      if (graph(vert_index,i)>0 && path_size[i] > path_size[vert_index]+graph(vert_index,i)) {
        path_size[i] = path_size[vert_index]+graph(vert_index,i);
      }
    }
    visited[vert_index] = true;
  } while (vert != INT_MAX);
  return path_size[vertex2];
}



} // s21