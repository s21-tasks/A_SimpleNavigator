#pragma once

#include "../submodules/cpp_libs/ConsoleInterface/ConsoleInterface.h"
#include "Graph.h"
#include "GraphAlgorithms.h"
#include "../submodules/cpp_libs/utility/sstr.h"
#include "../TslCompare/Compare.h"

namespace s21 {

class Interface : public ConsoleInterface {
    public:
        Interface();

    private:
        Graph graph_;
};

} // namespace s21
