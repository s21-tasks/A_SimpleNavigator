#include "AlgoritmsTests.h"

using namespace s21;

INSTANTIATE_TEST_SUITE_P(
    AlgorithmsGTTests, AlgorithmsGT,
    testing::Combine(testing::Values(true, false),  // directed
                     testing::Values(20, 5, 100),   // size
                     testing::Values(0.0f),         // zero probability
                     testing::Values(10, 100)       // max weight
                     ));

TEST_P(AlgorithmsGT, Test1) {
  VectorTest(GraphAlgorithms::GetLeastSpanningTree(graph_));

  int first = Random::Int(0, std::get<1>(GetParam()) - 1);

  VectorTest(GraphAlgorithms::breadthFirstSearch(graph_, first));
  VectorTest(GraphAlgorithms::depthFirstSearch(graph_, first));

  int second = Random::Int(0, std::get<1>(GetParam()) - 1);
  while (second == first) {
    second = Random::Int(0, std::get<1>(GetParam()) - 1);
  }
  int spbv =
      GraphAlgorithms::getShortestPathBetweenVertices(graph_, first, second);
  ASSERT_TRUE(spbv < std::get<1>(GetParam()) * std::get<3>(GetParam()) &&
              spbv >= 0);

  auto spbav = GraphAlgorithms::getShortestPathsBetweenAllVertices(graph_);
  ASSERT_EQ(spbav.GetCols(), graph_.Size());
  ASSERT_EQ(spbav.GetRows(), graph_.Size());
  for (int k = 0; k < graph_.Size(); ++k) {
    ASSERT_EQ(spbav(k, k), 0);
  }
}

TEST_F(FileAlgGT, TestC1) {
  file_name_ = "c1.txt";
  bfs_result_.emplace_back(0,
                           std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
  dfs_result_.emplace_back(0,
                           std::vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
  lst_result_ = {0, 8, 7, 2, 4, 3, 5, 9, 10, 1, 6};
  spbv_result_.emplace_back(std::make_pair(1, 5), 40);
  spbav_result_ = "results/c1_spbav.txt";
  Test();
}

TEST_F(FileAlgGT, TestCU1) {
  file_name_ = "cu1.txt";
  Load();
  ASSERT_ANY_THROW(GraphAlgorithms::GetLeastSpanningTree(graph_));
  ASSERT_EQ(GraphAlgorithms::solveTravelingSalesmanProblem(graph_).distance,
            INFINITY);
}

TEST(Errors, BFS) {
  Graph G(true, 100, 0.5, 10);
  ASSERT_ANY_THROW(GraphAlgorithms::breadthFirstSearch(G, -1));
  ASSERT_ANY_THROW(GraphAlgorithms::breadthFirstSearch(G, 150));
  ASSERT_ANY_THROW(GraphAlgorithms::breadthFirstSearch(Graph(), 0));
}

TEST(Errors, DFS) {
  Graph G(true, 100, 0.5, 10);
  ASSERT_ANY_THROW(GraphAlgorithms::depthFirstSearch(G, -1));
  ASSERT_ANY_THROW(GraphAlgorithms::depthFirstSearch(G, 150));
  ASSERT_ANY_THROW(GraphAlgorithms::depthFirstSearch(Graph(), 0));
}

TEST(Errors, Salesman) {
  ASSERT_ANY_THROW(GraphAlgorithms::GeneticSolveSalesmanProblem(Graph()));
  ASSERT_ANY_THROW(GraphAlgorithms::solveTravelingSalesmanProblem(Graph()));
  ASSERT_ANY_THROW(GraphAlgorithms::BnBSolveSalesmanProblem(Graph()));
}

TEST(Errors, LST) {
  ASSERT_ANY_THROW(GraphAlgorithms::GetLeastSpanningTree(Graph()));
}

TEST(Errors, SPBV) {
  ASSERT_ANY_THROW(
      GraphAlgorithms::getShortestPathBetweenVertices(Graph(), 0, 0));
  Graph G(true, 100, 0.5, 10);
  ASSERT_ANY_THROW(GraphAlgorithms::getShortestPathBetweenVertices(G, -1, 5));
  ASSERT_ANY_THROW(GraphAlgorithms::getShortestPathBetweenVertices(G, 150, 5));
  ASSERT_ANY_THROW(GraphAlgorithms::getShortestPathBetweenVertices(G, 50, 150));
  ASSERT_ANY_THROW(GraphAlgorithms::getShortestPathBetweenVertices(G, 30, -5));
}

TEST(Errors, SPBAV) {
  ASSERT_ANY_THROW(
      GraphAlgorithms::getShortestPathsBetweenAllVertices(Graph()));
}
