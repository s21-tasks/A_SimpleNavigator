#include "GraphAlgorithms.h"

namespace s21 {

std::vector<int> GraphAlgorithms::depthFirstSearch(const Graph &graph,
                                                   const int startVertex) {
  if (graph.Size() == 0) {
    throw std::invalid_argument("Empty graph");
  }
  if (startVertex < 0 || startVertex >= graph.Size()) {
    throw std::invalid_argument("Incorrect start vertex: " +
                                std::to_string(startVertex));
  }
  std::vector<int> visited;
  depthSearch(graph, startVertex, visited);
  return visited;
}

void GraphAlgorithms::depthSearch(const Graph &graph, const int vertex,
                                  std::vector<int> &visited) {
  std::stack<int> st;
  visited.push_back(vertex);
  for (int i = graph.Size() - 1; i >= 0; --i) {
    if (graph(vertex, i)) st.push(i);
  }
  while (!st.empty()) {
    if (std::find(visited.begin(), visited.end(), st.top()) == visited.end()) {
      depthSearch(graph, st.top(), visited);
    }
    st.pop();
  }
}

std::vector<int> GraphAlgorithms::breadthFirstSearch(const Graph &graph,
                                                     const int startVertex) {
  if (startVertex < 0 || startVertex >= graph.Size()) {
    throw std::invalid_argument("Incorrect start vertex: " +
                                std::to_string(startVertex));
  }
  std::queue<int> q;
  std::vector<int> visited{startVertex};
  std::vector<bool> visited_bool(graph.Size(), false);
  q.push(startVertex);
  visited_bool[startVertex] = true;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    if (!visited_bool[v]) {
      visited.push_back(v);
      visited_bool[v] = true;
    }
    for (int i = 0; i < graph.Size(); ++i) {
      if (graph(v, i) && !visited_bool[i]) q.push(i);
    }
  }
  return visited;
}

int GraphAlgorithms::getShortestPathBetweenVertices(const Graph &graph,
                                                    const int vertex1,
                                                    const int vertex2) {
  if (vertex1 < 0 || vertex1 >= graph.Size()) {
    throw std::invalid_argument("Incorrect vertex 1: " +
                                std::to_string(vertex1));
  }
  if (vertex2 < 0 || vertex2 >= graph.Size()) {
    throw std::invalid_argument("Incorrect vertex 2: " +
                                std::to_string(vertex2));
  }
  std::vector<int> path_size(graph.Size(), INT_MAX);
  std::vector<bool> visited(graph.Size(), false);
  path_size[vertex1] = 0;
  int vert = INT_MAX;
  int vert_index = vertex1;
  do {
    vert = INT_MAX;
    for (int i = 0; i < graph.Size(); ++i) {
      if (!visited[i] && path_size[i] < vert) {
        vert = path_size[i];
        vert_index = i;
      }
    }
    for (int i = 0; i < graph.Size(); ++i) {
      if (graph(vert_index, i) > 0) {
        path_size[i] = std::min(path_size[i],
                                path_size[vert_index] + graph(vert_index, i));
      }
    }
    visited[vert_index] = true;
  } while (vert != INT_MAX);
  return path_size[vertex2];
}

Matrix<int> GraphAlgorithms::getShortestPathsBetweenAllVertices(
    const Graph &graph) {
  if (graph.Size() == 0) {
    throw std::invalid_argument("Empty graph");
  }
  Matrix<int> solve(graph.GetMatrix());
  for (int i = 0; i < solve.GetCols(); ++i) {
    for (int j = 0; j < solve.GetCols(); ++j) {
      if (i != j && !solve(i, j)) solve(i, j) = MAX_GRAPH;
    }
  }

  for (int k = 0; k < solve.GetCols(); ++k) {
    for (int i = 0; i < solve.GetCols(); ++i) {
      for (int j = 0; j < solve.GetCols(); ++j) {
        solve(i, j) = std::min(solve(i, j), solve(i, k) + solve(k, j));
      }
    }
  }
  return solve;
}

TsmResult GraphAlgorithms::GeneticSolveSalesmanProblem(const Graph &graph) {
  if (graph.Size() == 0) {
    throw std::invalid_argument("Empty graph");
  }

  GeneticAlgorithm<int> sol(graph);
  return sol.Execute();
}

TsmResult GraphAlgorithms::solveTravelingSalesmanProblem(const Graph &graph) {
  if (graph.Size() == 0) {
    throw std::invalid_argument("Empty graph");
  }

  AntColony<int> colony(graph.GetMatrix());
  return colony.Solve();
}

TsmResult GraphAlgorithms::BnBSolveSalesmanProblem(const Graph &graph) {
  if (graph.Size() == 0) {
    throw std::invalid_argument("Empty graph");
  }

  BnB<int> bnb(graph.GetMatrix());
  return bnb.Solve();
}

std::vector<int> GraphAlgorithms::GetLeastSpanningTree(const Graph &graph) {
  if (graph.Size() == 0) {
    throw std::invalid_argument("Empty graph");
  }
  const int size = graph.Size();

  std::vector<int> result(size, 0);
  std::vector<bool> visited(size, false);
  visited[0] = true;

  for (int k = 1; k < size; ++k) {
    int min = INT_MAX;
    for (int i = 0; i < size; ++i) {
      for (int g = 0; g < k; ++g) {
        int cell = graph(result[g], i);
        if (cell < min && cell != 0 && !visited[i]) {
          min = cell;
          result[k] = i;
        }
      }
    }
    visited[result[k]] = true;
  }
  for (auto v : visited) {
    if (!v) {
      throw std::invalid_argument(
          "GetLeastSpanningTree can not find sapnung tree");
    }
  }

  return result;
}

}  // namespace s21