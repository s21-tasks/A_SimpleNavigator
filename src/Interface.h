#pragma once

#include "ConsoleInterface/ConsoleInterface.h"
#include "Graph.h"
#include "GraphAlgorithms.h"
#include "sstr.h"

namespace s21 {

class Interface : public ConsoleInterface {
    public:
        Interface();

    private:
        Graph graph_;
};

} // namespace s21
