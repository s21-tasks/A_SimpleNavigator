#pragma once

#include "Compare.h"
#include "ConsoleInterface.h"
#include "Graph.h"
#include "GraphAlgorithms.h"
#include "Utility.h"

namespace s21 {

class Interface : public ConsoleInterface {
 public:
  Interface();
  Graph &GetGraph() { return graph_; }

 private:
  Graph graph_;
};

class RandomGraph : public Input {
 public:
  RandomGraph(Interface *ci, AbsMenu *next_menu) : Input(ci, next_menu) {}
  void Func() override;
};

class TwoVertices : public Input {
 public:
  TwoVertices(Interface *ci, AbsMenu *next_menu) : Input(ci, next_menu) {}
  void Func() override;
};

}  // namespace s21
