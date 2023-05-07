#include "ConsoleInterface/ConsoleInterface.h"
#include "Graph.h"
#include "GraphAlgorithms.h"

#include "sstr.h"


using namespace s21;
using alg = GraphAlgorithms;


int main() {
    Graph G;
    ConsoleInterface ci;
    SStr::PrintStyle::container_delimiter = " -> ";
    auto home_menu = ci.AddMenu({"loading the original graph from a file",
            "create random graph",
            "print graph to terminal",
            "save matrix",
            "graph traversal in breadth",
            "graph traversal in depth",
            "searching for the shortest path between any two vertices",
            "searching for the shortest paths between all pairs of vertices in the graph",
            "searching for the minimal spanning tree in the graph",
            "solving the salesman problem"});

    home_menu->Connect(0,
        ci.AddInput<std::string>("the path to the file",
            [&] (std::string &path) { G.LoadGraphFromFile(path); }, home_menu));

    home_menu->Connect(1,
        ci.AddInput<bool, int, int, int>(
            "max value in graph (int); probability of zero (int %); size of graph (int); directed (1) or undirected (0).",
                                    [&] (bool directed, int size, float zero_probability, int max_weight) {
            G.CreateRandom((bool)directed, size, (float)zero_probability / 100.0, max_weight);
        }, home_menu));

    home_menu->Connect(2, home_menu, [&] { SStr::Print(G.GetMatrix()); });

    home_menu->Connect(3, ci.AddInput<std::string>("the path to the file",
            [&] (std::string &path) { G.GraphToFile(path); }, home_menu));
    
    home_menu->Connect(4, ci.AddInput<int>("start vertex",
            [&] (int start) { SStr::Print(alg::breadthFirstSearch(G, start)); },
        home_menu));
    
    home_menu->Connect(5, ci.AddInput<int>("start vertex",
            [&] (int start) { SStr::Print(alg::depthFirstSearch(G, start)); },
        home_menu));

    home_menu->Connect(6, ci.AddInput<int, int>("start vertex; end vertex",
            [&] (int start, int end) { SStr::Print(alg::getShortestPathBetweenVertices(G, start, end)); },
        home_menu));
    
    home_menu->Connect(7, home_menu, [&] { SStr::Print(alg::getShortestPathsBetweenAllVertices(G)); });

    auto salesman_manu = ci.AddMenu({
        "Ant colony"
    });

    home_menu->Connect(9, salesman_manu);

    salesman_manu->Connect(0, home_menu, [&] {
        auto tsm_result = alg::solveTravelingSalesmanProblem(G);
        SStr::Print<' '>(tsm_result.distance, tsm_result.vertices);
    });

    ci.Start();

    return 0;

}
