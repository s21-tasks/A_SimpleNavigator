#include "Interface.h"

namespace s21 {

Interface::Interface() {
    SStr::PrintStyle::container_delimiter = " -> ";
    auto home_menu = AddMenu({"loading the original graph from a file",
        "create random graph",
        "print graph to terminal",
        "save matrix",
        "graph traversal in breadth",
        "graph traversal in depth",
        "searching for the shortest path between any two vertices",
        "searching for the shortest paths between all pairs of vertices in the graph",
        "searching for the minimal spanning tree in the graph",
        "solving the salesman problem",
        "Comparison of methods for solving the traveling salesman problem"});

    home_menu->Connect(0,
        AddInput<std::string>("the path to the file",
            [&] (std::string &path) { graph_.LoadGraphFromFile(path); }, home_menu));

    home_menu->Connect(1,
        AddInput<bool, int, int, int>(
            "max value in graph (int); probability of zero (int %); size of graph (int); directed (1) or undirected (0).",
                                    [&] (bool directed, int size, float zero_probability, int max_weight) {
            graph_.CreateRandom((bool)directed, size, (float)zero_probability / 100.0, max_weight);
        }, home_menu));

    home_menu->Connect(2, home_menu, [&] { SStr::Print(graph_.GetMatrix()); });

    home_menu->Connect(3, AddInput<std::string>("the path to the file",
            [&] (std::string &path) { graph_.GraphToFile(path); }, home_menu));

    home_menu->Connect(4, AddInput<int>("start vertex",
            [&] (int start) { SStr::Print(GraphAlgorithms::breadthFirstSearch(graph_, start)); },
        home_menu));

    home_menu->Connect(5, AddInput<int>("start vertex",
            [&] (int start) { SStr::Print(GraphAlgorithms::depthFirstSearch(graph_, start)); },
        home_menu));

    home_menu->Connect(6, AddInput<int, int>("start vertex; end vertex",
            [&] (int start, int end) { SStr::Print(GraphAlgorithms::getShortestPathBetweenVertices(graph_, start, end)); },
        home_menu));

    home_menu->Connect(7, home_menu, [&] { SStr::Print(GraphAlgorithms::getShortestPathsBetweenAllVertices(graph_)); });

    home_menu->Connect(8, home_menu, [&] { SStr::Print(GraphAlgorithms::GetLeastSpanningTree(graph_)); });

    auto salesman_manu = AddMenu({
            "Ant colony"
        });

    home_menu->Connect(9, salesman_manu);

    salesman_manu->Connect(0, home_menu, [&] {
            auto tsm_result = GraphAlgorithms::solveTravelingSalesmanProblem(graph_);
            SStr::Print<' '>(tsm_result.distance, tsm_result.vertices);
        });

    home_menu->Connect(10, AddInput<int>("number of iterations", [&] (int N) {
            auto result = Compare::Time(graph_, N);
            std::cout << "Ant colony: " << result[0] << " ms\n";
            std::cout << "Genetic: " << result[1] << " ms\n";
            std::cout << "Branch and Bound: " << result[2] << " ms\n";
        },
        home_menu));
}

} // namespace s21
