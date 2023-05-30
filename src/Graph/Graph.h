#pragma once

#include <cctype>
#include <climits>
#include <fstream>
#include <initializer_list>
#include <iosfwd>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>

#include "Matrix.h"
#include "Utility.h"

#define MAX_GRAPH INT_MAX / 2 - 1

namespace s21 {

/**
 * @class Graph
 * @brief Represents a graph data structure.
 *
 * The Graph class provides functionality to create, manipulate, and export
 * graphs. It supports both directed and undirected graphs, and provides methods
 * to load graphs from files, export graphs to DOT format, and perform various
 * operations on graphs.
 */
class Graph {
 private:
  bool directed_;
  std::vector<std::string> vertices_;
  Matrix<int> matrix_;
  std::string name_ = "s21_graph";

 public:
  /**
   * @brief Default constructor.
   * Constructs an empty graph.
   */
  Graph() = default;

  /**
   * @brief Random graph constructor.
   * @param directed Flag indicating whether the graph is directed.
   * @param size The size (number of vertices) of the graph.
   * @param zero_probability The probability of an edge having weight zero.
   * @param max_weight The maximum weight of an edge.
   */
  Graph(bool directed, int size, float zero_probability, int max_weight);

  /**
   * @brief Constructor to load a graph from a file.
   * @param file_path The path to the file containing the graph data.
   */
  Graph(const std::string& file_path);

  /**
   * @brief Get the size of the graph.
   * @return The size (number of vertices) of the graph.
   */
  int Size() const;

  /**
   * @brief Access the element at the specified position in the adjacency
   * matrix.
   * @param row The row index of the element.
   * @param col The column index of the element.
   * @return A reference to the element at the specified position in the
   * adjacency matrix.
   */
  int& operator()(int row, int col);

  /**
   * @brief Access the element at the specified position in the adjacency matrix
   * (const version).
   * @param row The row index of the element.
   * @param col The column index of the element.
   * @return A const reference to the element at the specified position in the
   * adjacency matrix.
   */
  const int& operator()(int row, int col) const;

  /**
   * @brief Print the adjacency matrix of the graph.
   */
  void PrintMatrix();

  /**
   * @brief Get a reference to the adjacency matrix of the graph.
   * @return A reference to the adjacency matrix of the graph.
   */
  Matrix<int>& GetMatrix();

  /**
   * @brief Get a const reference to the adjacency matrix of the graph.
   * @return A const reference to the adjacency matrix of the graph.
   */
  const Matrix<int>& GetMatrix() const;

  /**
   * @brief Set the name of the graph.
   * @param name The name of the graph.
   */
  void SetName(const std::string name);

  /**
  @brief Check if the graph is directed.
  @return A boolean value indicating whether the graph is directed (true) or
  undirected (false).
  */
  bool Directed() const;

  /**
  @brief Load a graph from a file.
  * This function loads the graph properties and adjacency matrix from a file
  and updates the graph accordingly.
  @param filename The path to the file containing the graph data.
  */
  void LoadGraphFromFile(const std::string& filename);

  /**
  @brief Export the graph to DOT format.
  * This function exports the graph to a DOT file format, which is commonly used
  for graph visualization.
  @param filename The path to the file where the DOT representation of the graph
  will be saved.
  */
  void ExportGraphToDot(const std::string& filename);

  /**
  @brief Export the graph to a file in txt format.
  * This function exports the graph properties and adjacency matrix to a file in
  a specific format.
  @param filename The path to the file where the graph data will be saved.
  */
  void ExportGraphToFile(const std::string& filename);

  /**
  @brief Export the graph to a file in DOT or txt format.
  * If the specified file has an extension ".dot" this function is is equivalent
  to ExportGraphToFile(const std::string& filename).
  * Else this function is is equivalent to ExportGraphToDot(const std::string&
  filename).
  @param filename The path to the file where the graph data will be saved.
  */
  void GraphToFile(const std::string& filename);

  /**
  @brief Create a random graph.
  @param directed Flag indicating whether the graph should be directed.
  @param size The size (number of vertices) of the graph.
  @param zero_probability The probability of an edge having weight zero.
  @param max_weight The maximum weight of an edge.
  */
  void CreateRandom(bool directed, int size, float zero_probability,
                    int max_weight);

 private:
  static std::vector<std::string> SplitStr(std::string const& str,
                                           const char delim);

  void RandomDirected(int size, float zero_probability, int max_weight);

  void RandomUndirected(int size, float zero_probability, int max_weight);

  std::string CellName(int n);

  bool IsDirected() const;
};
}  // namespace s21