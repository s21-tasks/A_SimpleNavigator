#pragma once

#include <gtest/gtest.h>

#include <tuple>

#include "Graph.h"
#include "M_sstr.h"

namespace s21 {

class GT : public testing::TestWithParam<std::tuple<bool, int, float, int>> {
 protected:
  Graph graph_;

 public:
  GT()
      : graph_(std::get<0>(GetParam()), std::get<1>(GetParam()),
               std::get<2>(GetParam()), std::get<3>(GetParam())) {}

  static std::string FilePath(const std::string &file_name) {
    return SStr::RelativePath(__FILE__, "/test_files") + '/' + file_name;
  }
};

class FileGT : public testing::Test {
 protected:
  Graph graph_;
  std::string file_name_;

  virtual void Tester() = 0;

 public:
  FileGT() {}

  void Test() {
    Load();
    Tester();
  }

  void Load() { graph_.LoadGraphFromFile(GT::FilePath(file_name_)); }
};

}  // namespace s21