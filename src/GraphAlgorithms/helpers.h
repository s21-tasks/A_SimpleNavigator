#pragma once

#include "../Graph/Graph.h"

struct TsmResult {
  std::vector<int> vertices;    // Массив с искомым маршрутом (с порядком обхода вершин). Вместо int* можно использовать std::vector<int>
  double distance;  // длина этого маршрута
};