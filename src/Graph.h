#ifndef SIMPLENAVIGATOR_GRAPH_H
#define SIMPLENAVIGATOR_GRAPH_H

#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <queue>
#include <iosfwd>
#include <sstream>
#include "matrix.h"
#include <climits>
#include <stack>
#include <cctype>

#include <initializer_list>

#include "random.h"

#define MAX_GRAPH INT_MAX/2-1

namespace s21 {

  class Graph {
    bool directed_;
    bool weighted_;
    std::map<std::string, int> vertices_;
    Matrix<int> matrix_;



  public:

    template<class ...Args>
    Graph(std::initializer_list<std::pair<std::string, int>> const &map_arg, bool di, bool weighted, Args ...args) :
      vertices_(map_arg.begin(), map_arg.end()),
      matrix_(map_arg.size(), map_arg.size(), args...),
      directed_(di),weighted_(weighted) {}
    
    Graph(bool directed, int size, float zero_probability, int max_weight);

    int GraphSize();
    int &operator()(int row, int col);
    void PrintMatrix();
    Matrix<int>& GetMatrix();


    void FromFileDot(const std::string& filepath);
    void LoadGraphFromFile(const std::string& filename);
    void exportGraphToDot(const std::string &filename, const std::string &graphname);
    void GraphToFile(const std::string& filename);

  private:
    static std::vector<std::string> SplitStr(std::string const &str, const char delim);

    void RandomDirected(int size, float zero_probability, int max_weight);
    void RandomUndirected(int size, float zero_probability, int max_weight);

    std::string Graph::CellName(int n);
  };

} // s21

#endif //SIMPLENAVIGATOR_GRAPH_H
