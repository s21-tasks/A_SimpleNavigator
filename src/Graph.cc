//
// Created by Иван Захаров on 23.03.2023.
//

#include "Graph.h"

using std::string, std::vector;

namespace s21 {

vector<string> Graph::SplitStr(std::string const &str, const char delim = ' ') {
  vector <std::string> out;
  std::stringstream s(str);
  string s2;

  while (std:: getline(s, s2, delim))
  {
    if (s2.size()>0)
      out.push_back(s2); // store the string in s2
  }
  return out;
}


  void Graph::FromFileDot(const string& filepath) {
  std::ifstream in(filepath, std::ios::in);
  string line;
  std::map<string,string> temp;
  int temp_count = 0;

  getline(in, line);
  auto spl = SplitStr(line);
  if (spl[0] =="digraph") {
    directed_ = 1;
  } else if (spl[0] =="graph") {
    directed_ = 0;
  } else {
    throw std::invalid_argument("invalid file!");
  }

//  TODO сделать проверку строки

  while (getline(in, line)) {
    vector<string> w = SplitStr(line);
    if (w.size() == 1) {
//      TODO сделать добавление строк тут
      continue;
    }
    for (int i = 0; i < w.size(); i+=2) {
      if (w[i][w[i].size()-1] == ';') {
        w[i].pop_back();
      }
      if (vertices_.find(w[i])==vertices_.end())
        vertices_[w[i]] = vertices_.size();

    }
  }
  in.close();
  in.open(filepath);

  matrix_ = Matrix<int>(vertices_.size(), vertices_.size());
  getline(in, line);
  while (getline(in, line)) {
    vector<string> w = SplitStr(line);
    if (w.size() == 1) {
//      TODO сделать добавление строк тут
      continue;
    }
    for (int i = 0; i < w.size()-2; i+=2) {
      if (w[i+2][w[i+2].size()-1] == ';')
        w[i+2].pop_back();

      matrix_(vertices_[w[i]], vertices_[w[i+2]]) = 1;
      matrix_(vertices_[w[i+2]], vertices_[w[i]]) = 1;
    }
  }
}

void Graph::LoadGraphFromFile(const std::string& filename) {
  std::ifstream in(filename, std::ios::in);
  string line;
  getline(in, line);
  int size = std::atoi(line.c_str());
  matrix_ = Matrix<int>(size, size);
  int i = 0;
  while (getline(in, line)) {
    vector<string> w = SplitStr(line);
    for (int j = 0; j < w.size(); ++j) {
      matrix_(i,j) = std::atoi(w[j].c_str());
    }
    ++i;
  }
}

void Graph::exportGraphToDot(const std::string filename) {
  return;
}

int Graph::GraphSize() {
  return matrix_.GetCols();
}

int& Graph::operator()(int row, int col) {
  return matrix_(row,col);
}











} // s21