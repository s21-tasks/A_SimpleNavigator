#include "Graph.h"

using std::string, std::vector;

namespace s21 {

Graph::Graph(bool directed, int size, float zero_probability, int max_weight) {
  CreateRandom(directed, size, zero_probability, max_weight);
}

Graph::Graph(const std::string& file_path) { LoadGraphFromFile(file_path); }

void Graph::CreateRandom(bool directed, int size, float zero_probability,
                         int max_weight) {
  if (size <= 1)
    throw std::invalid_argument("Incorrect graph size: " +
                                std::to_string(size));
  if (zero_probability < 0.0 || zero_probability > 1.0)
    throw std::invalid_argument("Incorrect graph zero_probability: " +
                                std::to_string(zero_probability));
  if (max_weight <= 0)
    throw std::invalid_argument("Incorrect graph max weight: " +
                                std::to_string(max_weight));

  vertices_.resize(size);
  matrix_ = Matrix<int>(size);
  directed_ = directed;
  directed_ ? RandomDirected(size, zero_probability, max_weight)
            : RandomUndirected(size, zero_probability, max_weight);
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
    vertices_[k] = CellName(k);
    for (int g = 0; g < size; ++g) {
      if (k != g && !Random::Bool(zero_probability)) {
        matrix_(k, g) = Random::Int(1, max_weight);
      }
    }
  }
}

void Graph::RandomUndirected(int size, float zero_probability, int max_weight) {
  for (int k = 0; k < size; ++k) {
    vertices_[k] = CellName(k);
    for (int g = k + 1; g < size; ++g) {
      if (!Random::Bool(zero_probability)) {
        matrix_(k, g) = matrix_(g, k) = Random::Int(1, max_weight);
      }
    }
  }
}

void Graph::LoadGraphFromFile(const std::string& filename) {
  std::ifstream file(filename, std::ios::in);
  if (!file) {
    throw std::invalid_argument("invalid file!");
  }
  int size = 0;
  file >> size;
  if (size == 0) {
    throw std::invalid_argument("invalid size of matrix in file!");
  }
  vertices_.resize(size);
  matrix_ = Matrix<int>(size, size, -1);
  for (int k = 0; k < size; ++k) {
    vertices_[k] = CellName(k);
    for (int g = 0; g < size; ++g) {
      file >> matrix_(k, g);
      if (matrix_(k, g) < 0 || (k == g && matrix_(k, g) != 0)) {
        throw std::invalid_argument("invalid matrix in file!");
      }
    }
    if (file.peek() != '\n' && file.peek() != EOF) {
      throw std::invalid_argument("invalid file struct!" + std::to_string(k));
    }
  }
  directed_ = IsDirected();
  file.close();
}

bool Graph::IsDirected() const {
  for (int k = 0; k < matrix_.GetCols(); ++k) {
    for (int g = k + 1; g < matrix_.GetRows(); ++g) {
      if (matrix_(g, k) != matrix_(k, g)) {
        return true;
      }
    }
  }
  return false;
}

void Graph::GraphToFile(const std::string& filename) {
  if (filename.length() >= 4 &&
      filename.substr(filename.length() - 4) == ".dot") {
    ExportGraphToDot(filename);
  } else {
    ExportGraphToFile(filename);
  }
}

void Graph::ExportGraphToFile(const std::string& filename) {
  std::ofstream file(filename);
  if (!file) {
    throw std::invalid_argument("invalid file!");
  }
  const int size = matrix_.GetCols();
  file << size << "\n";
  file << matrix_;
  file.close();
}

void Graph::ExportGraphToDot(const std::string& filename) {
  std::ofstream file(filename);
  if (!file) {
    throw std::invalid_argument("invalid file!");
  }
  const int size = matrix_.GetCols();
  file << (directed_ ? "digraph " : "graph ") << name_ << " {\n";
  for (int i = 0; i < size; ++i) {
    for (int j = (directed_ ? 0 : i); j < size; ++j) {
      int weight = matrix_(i, j);
      if (weight != 0) {
        file << "  " << vertices_[i] << (directed_ ? " -> " : " -- ")
             << vertices_[j];
        if (weight != 1) {
          file << " [label=\"" << weight << "\"]";
        }
        file << ";\n";
      }
    }
  }
  file << "}\n";
  file.close();
  return;
}

int& Graph::operator()(int row, int col) { return matrix_(row, col); }

void Graph::PrintMatrix() { matrix_.Print(); }

Matrix<int>& Graph::GetMatrix() { return matrix_; }

int Graph::Size() const { return matrix_.GetCols(); }

bool Graph::Directed() const { return directed_; }

const int& Graph::operator()(int row, int col) const {
  return matrix_(row, col);
}

const Matrix<int>& Graph::GetMatrix() const { return matrix_; }

void Graph::SetName(const std::string name) { name_ = name; }

vector<string> Graph::SplitStr(std::string const& str, const char delim = ' ') {
  vector<std::string> out;
  std::stringstream s(str);
  string s2;

  while (std::getline(s, s2, delim)) {
    if (s2.size() > 0) out.push_back(s2);  // store the string in s2
  }
  return out;
}

//   void Graph::FromFileDot(const string& filepath) {
//   std::ifstream in(filepath, std::ios::in);
//   string line;
//   std::map<string,string> temp;
//   int temp_count = 0;

//   getline(in, line);
//   auto spl = SplitStr(line);
//   if (spl[0] =="digraph") {
//     directed_ = 1;
//   } else if (spl[0] =="graph") {
//     directed_ = 0;
//   } else {
//     throw std::invalid_argument("invalid file!");
//   }

// //  TODO сделать проверку строки

//   while (getline(in, line)) {
//     vector<string> w = SplitStr(line);
//     if (w.size() == 1) {
// //      TODO сделать добавление строк тут
//       continue;
//     }
//     for (int i = 0; i < w.size(); i+=2) {
//       if (w[i][w[i].size()-1] == ';') {
//         w[i].pop_back();
//       }
//       if (vertices_.find(w[i])==vertices_.end())
//         vertices_[w[i]] = vertices_.size();

//     }
//   }
//   in.close();
//   in.open(filepath);

//   matrix_ = Matrix<int>(vertices_.size(), vertices_.size());
//   getline(in, line);
//   while (getline(in, line)) {
//     vector<string> w = SplitStr(line);
//     if (w.size() == 1) {
// //      TODO сделать добавление строк тут
//       continue;
//     }
//     for (int i = 0; i < w.size()-2; i+=2) {
//       if (w[i+2][w[i+2].size()-1] == ';')
//         w[i+2].pop_back();

//       matrix_(vertices_[w[i]], vertices_[w[i+2]]) = 1;
//       matrix_(vertices_[w[i+2]], vertices_[w[i]]) = 1;
//     }
//   }
// }

}  // namespace s21