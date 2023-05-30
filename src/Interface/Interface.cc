#include "Interface.h"

namespace s21 {

void RandomGraph::Func() {
  Style::InputRequest({"directed (1) or undirected (0)", "size of graph (int)",
                       "probability of zero (int %)",
                       "max value in graph (int)"});
  bool directed = Read<bool>();
  int size = Read<int>();
  int pz = Read<int>();
  int max = Read<int>();
  if (Allowed()) {
    ((Interface *)ci_)
        ->GetGraph()
        .CreateRandom(directed, size, (float)pz / 100.0, max);
  }
}

void TwoVertices::Func() {
  Style::InputRequest({"start vertex", "end vertex"});
  int start = Read<int>();
  int end = Read<int>();
  if (Allowed()) {
    std::cout << GraphAlgorithms::getShortestPathBetweenVertices(
                     ((Interface *)ci_)->GetGraph(), start, end)
              << "\n";
  }
}

Interface::Interface() {
  SStr::PrintStyle::container_delimiter = " -> ";
  auto home_menu = AddMenu(
      {"loading the original graph from a file", "create random graph",
       "print graph to terminal", "save matrix", "graph traversal in breadth",
       "graph traversal in depth",
       "searching for the shortest path between any two vertices",
       "searching for the shortest paths between all pairs of vertices in the "
       "graph",
       "searching for the minimal spanning tree in the graph",
       "solving the salesman problem",
       "Comparison of methods for solving the traveling salesman problem"});

  home_menu->Connect(
      0, AddInput(new OneValueInput<std::string>(
             this, home_menu,
             [&](std::string &path) {
               try {
                 graph_.LoadGraphFromFile(path);
               } catch (...) {
                 graph_.LoadGraphFromFile("../materials/test_files/" + path);
               }
             },
             "the path to the file")));

  home_menu->Connect(1, AddInput(new RandomGraph(this, home_menu)));
  home_menu->Connect(2, home_menu, [&] { SStr::Print(graph_.GetMatrix()); });

  home_menu->Connect(
      3,
      AddInput(new OneValueInput<std::string>(
          this, home_menu, [&](std::string &path) { graph_.GraphToFile(path); },
          "the path to the file")));

  home_menu->Connect(
      4, AddInput(new OneValueInput<int>(
             this, home_menu,
             [&](int &start) {
               SStr::Print(GraphAlgorithms::breadthFirstSearch(graph_, start));
             },
             "start vertex")));

  home_menu->Connect(
      5, AddInput(new OneValueInput<int>(
             this, home_menu,
             [&](int &start) {
               SStr::Print(GraphAlgorithms::depthFirstSearch(graph_, start));
             },
             "start vertex")));

  home_menu->Connect(6, AddInput(new TwoVertices(this, home_menu)));

  home_menu->Connect(7, home_menu, [&] {
    SStr::Print(GraphAlgorithms::getShortestPathsBetweenAllVertices(graph_));
  });

  home_menu->Connect(8, home_menu, [&] {
    SStr::Print(GraphAlgorithms::GetLeastSpanningTree(graph_));
  });

  auto salesman_manu = AddMenu({"Ant colony", "Genetic", "Branch and Bounds"});

  home_menu->Connect(9, salesman_manu);

  salesman_manu->Connect(0, home_menu, [&] {
    auto tsm_result = GraphAlgorithms::solveTravelingSalesmanProblem(graph_);
    SStr::Print<' '>(tsm_result.distance, tsm_result.vertices);
  });

  salesman_manu->Connect(1, home_menu, [&] {
    auto tsm_result = GraphAlgorithms::GeneticSolveSalesmanProblem(graph_);
    SStr::Print<' '>(tsm_result.distance, tsm_result.vertices);
  });

  salesman_manu->Connect(2, home_menu, [&] {
    auto tsm_result = GraphAlgorithms::BnBSolveSalesmanProblem(graph_);
    SStr::Print<' '>(tsm_result.distance, tsm_result.vertices);
  });

  home_menu->Connect(
      10, AddInput(new OneValueInput<int>(
              this, home_menu,
              [&](int &N) {
                auto result = Compare::Time(graph_, N);
                std::cout << "Ant colony: " << result[0] << " ms\n";
                std::cout << "Genetic: " << result[1] << " ms\n";
                std::cout << "Branch and Bound: " << result[2] << " ms\n";
              },
              "number of iterations")));
}

}  // namespace s21
