#pragma once

#include <list>
#include <unordered_set>

#include "../Test.h"
#include "GraphAlgorithms.h"

namespace s21 {

class AlgorithmsGT : public GT {
 protected:
  void VectorTest(const std::vector<int> vector) {
    ASSERT_EQ(vector.size(), graph_.Size());
    ASSERT_EQ(std::unordered_set<int>(vector.begin(), vector.end()).size(),
              graph_.Size());
  }

 public:
  AlgorithmsGT() : GT() {}
};

class FileAlgGT : public FileGT {
 protected:
  std::list<std::pair<int, std::vector<int>>> bfs_result_;
  std::list<std::pair<int, std::vector<int>>> dfs_result_;
  std::vector<int> lst_result_;
  std::list<std::pair<std::pair<int, int>, int>> spbv_result_;
  std::string spbav_result_;

  void Tester() override {
    BFS();
    DFS();
    LST();
    SPBV();
    SPBAV();
  }

 private:
  void BFS() {
    for (const auto &i : bfs_result_) {
      ASSERT_EQ(i.second, GraphAlgorithms::breadthFirstSearch(graph_, i.first));
    }
  }
  void DFS() {
    for (const auto &i : dfs_result_) {
      ASSERT_EQ(i.second, GraphAlgorithms::depthFirstSearch(graph_, i.first));
    }
  }
  void LST() {
    ASSERT_EQ(lst_result_, GraphAlgorithms::GetLeastSpanningTree(graph_));
  }
  void SPBV() {
    for (const auto &i : spbv_result_) {
      ASSERT_EQ(i.second, GraphAlgorithms::getShortestPathBetweenVertices(
                              graph_, i.first.first, i.first.second));
    }
  }
  void SPBAV() {
    ASSERT_EQ(Graph(GT::FilePath(spbav_result_)).GetMatrix(),
              GraphAlgorithms::getShortestPathsBetweenAllVertices(graph_));
  }
};

}  // namespace s21
