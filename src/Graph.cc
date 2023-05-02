#include "Graph.h"

using std::string, std::vector;

namespace s21 {

Graph::Graph(bool directed, int size, float zero_probability, int max_weight) :
    directed_(directed), matrix_(size) {
  directed_ ? RandomDirected(size, zero_probability, max_weight) :
              RandomUndirected(size, zero_probability, max_weight);
}

std::string Graph::CellName(int n) {
  std::string name = "";
  do {
      name = char('A' + (n % 26)) + name;
      n /= 26;
  } while (n > 0);
  return name;
}

void Graph::RandomDirected(int size, float zero_probability, int max_weight) {
  for (int k = 0; k < size; ++k) {
    vertices_.emplace(CellName(k), k);
    for (int g = 0; g < size; ++g) {
      if (k != g && !Random::Bool(zero_probability)) {
        matrix_(k, g) = Random::Int(1, max_weight);
      }
    }
  }
}

void Graph::RandomUndirected(int size, float zero_probability, int max_weight) {
  for (int k = 0; k < size; ++k) {
    vertices_.emplace(CellName(k), k);
    for (int g = k+1; g < size; ++g) {
      if (!Random::Bool(zero_probability)) {
        matrix_(k, g) = matrix_(g, k) = Random::Int(1, max_weight);
      }
    }
  }
}


void Graph::LoadGraphFromFile(const std::string& filename) {
  std::ifstream file(filename, std::ios::in);
  int size = 0;
  file >> size;
  if (size == 0) {
    throw std::invalid_argument("invalid file!");
  }
  matrix_ = Matrix<int>(size, size, -1);
  for (int k = 0; k < size; ++k) {
    for (int g = 0; g < size; ++g) {
      file >> matrix_(k, g);
      if (matrix_(k, g) < 0) {
        throw std::invalid_argument("invalid file!");
      }
    }
    if (file.peek() != '\n' && file.peek() != EOF) {
      throw std::invalid_argument("invalid file!");
    }
  }
}

void Graph::GraphToFile(const std::string& filename) {
  std::ofstream file(filename);
  const int size = matrix_.GetCols();
  file << size << "\n";
  for (int k = 0; k < size; ++k) {
    for (int g = 0; g < size; ++g) {
      file << matrix_[k][g] << (g == size-1 ? '\n' : '\t');
    }
  }
}

void Graph::exportGraphToDot(const std::string &filename) {
  return;
}

int Graph::GraphSize() {
  return matrix_.GetCols();
}

int& Graph::operator()(int row, int col) {
  return matrix_(row,col);
}

void Graph::PrintMatrix() {
  matrix_.Print();
}

Matrix<int>& Graph::GetMatrix() {
  return matrix_;
}









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



} // s21