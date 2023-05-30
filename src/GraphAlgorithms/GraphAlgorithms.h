#pragma once

#include <algorithm>

#include "../submodules/Containers/src/s21_containers.hpp"
#include "AntColonyAlgorithm/AntColonyAlgorithm.h"
#include "BnBAlgorithm/BnBAlgorithm.h"
#include "GeneticAlgorithm/GeneticAlgorithm.h"
#include "Graph.h"
#include "Helpers.h"
// #include "containers.hpp"

namespace s21 {
/**
 * @class GraphAlgorithms
 * @brief Provides various graph algorithms.
 * The GraphAlgorithms class contains static methods for performing common graph
 * algorithms such as depth-first search, breadth-first search, finding shortest
 * paths, computing the least spanning tree, and solving the traveling salesman
 * problem. These algorithms operate on instances of the Graph class.
 */
class GraphAlgorithms {
 public:
  /**
   * @brief Perform a depth-first search on the graph.
   * This method performs a depth-first search traversal on the specified graph
   * starting from the given startVertex. It returns a vector containing the
   * vertices visited in the order they were encountered during the traversal.
   * @param graph The graph to perform the depth-first search on.
   * @param startVertex The vertex from which to start the traversal.
   * @return A vector containing the vertices visited during the depth-first
   * search.
   */
  static std::vector<int> depthFirstSearch(const Graph& graph,
                                           const int startVertex);

  /**
   * @brief Perform a breadth-first search on the graph.
   * This method performs a breadth-first search traversal on the specified
   * graph starting from the given startVertex. It returns a vector containing
   * the vertices visited in the order they were encountered during the
   * traversal.
   * @param graph The graph to perform the breadth-first search on.
   * @param startVertex The vertex from which to start the traversal.
   * @return A vector containing the vertices visited during the breadth-first
   * search.
   */
  static std::vector<int> breadthFirstSearch(const Graph& graph,
                                             const int startVertex);

  /**
   * @brief Get the shortest path between two vertices in the graph.
   * This method computes the shortest path between the specified vertex1 and
   * vertex2 in the graph. It returns the length of the shortest path between
   * the two vertices.
   * @param graph The graph to compute the shortest path on.
   * @param vertex1 The source vertex.
   * @param vertex2 The destination vertex.
   * @return The length of the shortest path between vertex1 and vertex2.
   */
  static int getShortestPathBetweenVertices(const Graph& graph,
                                            const int vertex1,
                                            const int vertex2);

  /**
   * @brief Get the shortest paths between all pairs of vertices in the graph.
   * This method computes the shortest paths between all pairs of vertices in
   * the graph. It returns a matrix containing the lengths of the shortest paths
   * between all vertices.
   * @param graph The graph to compute the shortest paths on.
   * @return A matrix containing the lengths of the shortest paths between all
   * vertices.
   */
  static Matrix<int> getShortestPathsBetweenAllVertices(const Graph& graph);

  /**
   * @brief Compute the least spanning tree of the graph.
   * This method computes the least spanning tree of the specified graph using
   * Prim's algorithm. It returns a vector containing the edges of the least
   * spanning tree in the order they were added.
   * @param graph The graph to compute the least spanning tree on.
   * @return A vector containing the edges of the least spanning tree.
   */
  static std::vector<int> GetLeastSpanningTree(const Graph& graph);

  /**
   * @brief Solve the Traveling Salesman Problem (TSP) using a Anc Colony
   * algorithm. This method solves the Traveling Salesman Problem (TSP) for the
   * given graph using a Ant Colony algorithm. The TSP aims to find the shortest
   * possible route that visits every vertex in the graph exactly once and
   * returns to the starting vertex. This method returns a TsmResult object that
   * contains the shortest path and its length.
   * @param graph The graph representing the TSP.
   * @return A TsmResult object containing the shortest path and its length.
   */
  static TsmResult solveTravelingSalesmanProblem(const Graph& graph);

  /**
   * @brief Solve the Traveling Salesman Problem (TSP) using a Genetic
   * algorithm. This method solves the Traveling Salesman Problem (TSP) for the
   * given graph using a Genetic algorithm. The TSP aims to find the shortest
   * possible route that visits every vertex in the graph exactly once and
   * returns to the starting vertex. This method returns a TsmResult object that
   * contains the shortest path and its length.
   * @param graph The graph representing the TSP.
   * @return A TsmResult object containing the shortest path and its length.
   */
  static TsmResult GeneticSolveSalesmanProblem(const Graph& graph);

  /**
   * @brief Solve the Traveling Salesman Problem (TSP) using a Branch and Bounds
   * algorithm. This method solves the Traveling Salesman Problem (TSP) for the
   * given graph using a Branch and Bounds algorithm. The TSP aims to find the
   * shortest possible route that visits every vertex in the graph exactly once
   * and returns to the starting vertex. This method returns a TsmResult object
   * that contains the shortest path and its length.
   * @param graph The graph representing the TSP.
   * @return A TsmResult object containing the shortest path and its length.
   */
  static TsmResult BnBSolveSalesmanProblem(const Graph& graph);

 private:
  static void depthSearch(const Graph& graph, const int vertex,
                          std::vector<int>& visited);
};

}  // namespace s21