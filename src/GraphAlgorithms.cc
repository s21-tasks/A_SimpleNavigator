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
    // if (std::find(visited.begin(), visited.end(), st.top()) == visited.end()) {
    //   depthSearch(graph, st.top(), visited);
    // }
    st.pop();
  }
}

std::vector<int> GraphAlgorithms::breadthFirstSearch(Graph &graph, int startVertex) {
  std::queue<int> q;
  std::vector<int> visited;
  std::vector<bool> visited_bool(graph.GraphSize(), false);
  q.push(startVertex);
  visited_bool[startVertex] = true;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    if (!visited_bool[v]) {
      visited.push_back(v);
      visited_bool[v] = true;
    }
    for (int i = 0; i < graph.GraphSize(); ++i) {
        if (graph(v,i) && !visited_bool[i])
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
      if (graph(vert_index,i)>0) {
        path_size[i] = std::min(path_size[i], path_size[vert_index]+graph(vert_index,i));
      }
    }
    visited[vert_index] = true;
  } while (vert != INT_MAX);
  return path_size[vertex2];
}

Matrix<int> GraphAlgorithms::getShortestPathsBetweenAllVertices(Graph &graph) {
  Matrix<int> solve(graph.GetMatrix());
  for (int i = 0; i < solve.GetCols(); ++i) {
    for (int j = 0; j < solve.GetCols(); ++j) {
      if (i != j && !solve(i,j))
        solve(i,j) = MAX_GRAPH;
    }
  }

  for (int k = 0; k < solve.GetCols(); ++k) {
    for (int i = 0; i < solve.GetCols(); ++i) {
      for (int j = 0; j < solve.GetCols(); ++j) {
        solve(i,j) = std::min(solve(i,j), solve(i,k) + solve(k,j));
      }
    }
  }
  return solve;
}

TsmResult GraphAlgorithms::solveTravelingSalesmanProblem(const Graph &graph) {
  AntColony<int> colony(graph.GetMatrix());

  return colony.Solve();
}

std::vector<int> GraphAlgorithms::GetLeastSpanningTree(const Graph &graph) {
  const int size = graph.Size();

  std::vector<int> result(size, 0);
  std::vector<bool> visited(size, false);
  visited[0] = true;
  
  for (int k = 1; k < size; ++k) {
    int min = INT_MAX;
    for (int i = 0; i < size; ++i) {
      int cell = graph(result[k - 1], i);
      if (cell < min && cell != 0 && !visited[i]) {
        min = cell;
        result[k] = i;
      }
    }
    visited[result[k]] = true;
  }

  return result;
}




} // s21