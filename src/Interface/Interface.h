#pragma once

#include "ConsoleInterface.h"
#include "Graph.h"
#include "GraphAlgorithms.h"
#include "utility.h"
#include "Compare.h"

namespace s21 {

class Interface : public ConsoleInterface {
    public:
        Interface();

    private:
        Graph graph_;
};

} // namespace s21
