#pragma once

#include "lib/ConsoleInterface/ConsoleInterface.h"
#include "Graph.h"
#include "GraphAlgorithms.h"
#include "lib/sstr.h"
#include "TslCompare/Compare.h"

namespace s21 {

class Interface : public ConsoleInterface {
    public:
        Interface();

    private:
        Graph graph_;
};

} // namespace s21
