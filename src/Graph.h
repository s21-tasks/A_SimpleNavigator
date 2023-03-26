//
// Created by Иван Захаров on 23.03.2023.
//

#ifndef SIMPLENAVIGATOR_GRAPH_H
#define SIMPLENAVIGATOR_GRAPH_H

#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <iosfwd>
#include <sstream>
#include "maykitbo_matrix/src/matrix.h"


namespace s21 {

  class Graph {
    bool directed_;
    bool weighted_;
    std::map<std::string, int> vertices_;
    Matrix<int> matrix_;



  public:
    int GraphSize();
    int &operator()(int row, int col);
    void PrintMatrix();


    void FromFileDot(const std::string& filepath);
    void LoadGraphFromFile(const std::string& filename);
    void exportGraphToDot(const std::string filename);

  private:
    static std::vector<std::string> SplitStr(std::string const &str, const char delim);
  };

} // s21

#endif //SIMPLENAVIGATOR_GRAPH_H
