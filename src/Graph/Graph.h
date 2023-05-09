#pragma once

#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <queue>
#include <iosfwd>
#include <sstream>
#include <climits>
#include <stack>
#include <cctype>

#include <initializer_list>

#include "matrix.h"
#include "utility.h"

#define MAX_GRAPH INT_MAX/2-1

namespace s21 {

  class Graph {
    bool directed_;
    std::vector<std::string> vertices_;
    Matrix<int> matrix_;
    std::string name_ = "s21_graph";


  public:

    Graph() = default;

    Graph(bool directed, int size, float zero_probability, int max_weight);
    Graph(const std::string &file_path);

    int GraphSize();

    int Size() const;

    int &operator()(int row, int col);

    const int &operator()(int row, int col) const;

    void PrintMatrix();

    Matrix<int> &GetMatrix();

    const Matrix<int> &GetMatrix() const;

    void SetName(const std::string name);

    bool Directed() const;


    void LoadGraphFromFile(const std::string &filename);

    void ExportGraphToDot(const std::string &filename);

    void ExportGraphToFile(const std::string &filename);

    void GraphToFile(const std::string &filename);

    void CreateRandom(bool directed, int size, float zero_probability, int max_weight);

  private:
    static std::vector<std::string> SplitStr(std::string const &str, const char delim);

    void RandomDirected(int size, float zero_probability, int max_weight);

    void RandomUndirected(int size, float zero_probability, int max_weight);

    std::string CellName(int n);

    bool IsDirected() const;
  };
}