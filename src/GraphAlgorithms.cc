

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

float RandomNumber() {
  float ans = float(rand()) / float(RAND_MAX);
  srand(ans * RAND_MAX);
  return ans;
}

int SumVector(std::vector<int>& v) {
  int ans = 0;
  for (nt i = 0; i < v.size(); ++i) {
    ans += v[i];
  }
  return ans;
}

void FeromonsEvaporation(std::vector<float>& f) {
  const q = 0.64;
  for (int i = 0; i < f.size(); ++i) {
    f[i] *= 0.64;
  }
}

TsmResult GraphAlgorithms::solveTravelingSalesmanProblem(Graph &graph) {
  srand(time(NULL));
  TsmResult answer;
  Matrix<float> feromons(graph.GraphSize(), graph.GraphSize(), 0.2);
  std::vector<std::vector<int>> roads;
  std::vector<float> chance(graph.GraphSize());
  std::vector<int> visited;
  std::vector<int> roads_size;

  const float alpha = 1;
  const float beta = 1;
  float all_chance = 0;
  int start_point = 0;
  int all_path = 0;
  for (int k = 0; k < 100; ++k) {
    visited.clear();
    chance.clear();
    while (visited.size() != graph.GraphSize()) {
      visited.push_back(start_point);
      for (int i = 0; i < graph.GraphSize(); ++i) {
        if (graph(start_point, i) > 0) {
          chance[i] = std::pow(feromons(start_point, i), alpha) * std::pow(graph(start_point, i), beta);
          all_chance += chance[i];
        }
      }
      float path_choice = RandomNumber();
      for (int i = 0; i < graph.GraphSize(); ++i) {
        path_choice -= chance[i] / all_chance;
        if (path_choice <= 0) {
          start_point = i;
        }
      }
    }
    roads.push_back(visited);
    roads_size.push_back(SumVector(visited));

  }

  FeromonsEvaporation(feromons);
  






  return answer;
}




} // s21