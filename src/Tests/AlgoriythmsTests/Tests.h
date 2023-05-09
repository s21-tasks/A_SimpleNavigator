#pragma once

#include <gtest/gtest.h>
#include <tuple>
#include "GraphAlgorithms.h"
#include "m_sstr.h"

namespace s21 {

class AntGT : public testing::TestWithParam<std::tuple<bool, int, float, int>> {
    protected:
        Graph graph_;
        AntColony<int> colony_;

    public:
        AntGT() :
            graph_(std::get<0>(GetParam()), std::get<1>(GetParam()),
                    std::get<2>(GetParam()), std::get<3>(GetParam())),
            colony_(graph_.GetMatrix()) {}

};

} // namespace s21
