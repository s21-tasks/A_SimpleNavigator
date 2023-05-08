#include <iostream>
#include "AntColonyTSL.h"
#include "../Graph.h"

using namespace s21;

int main() {
    Graph G(0, 10, 0.5, 10);
    AntColony<int> ac(G.GetMatrix());
    return 0;
}

