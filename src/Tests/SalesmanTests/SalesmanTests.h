#pragma once

#include "../Test.h"

#include <list>

#include "GraphAlgorithms.h"
#include "Compare.h"


namespace s21 {

class AlgorithmsGT : public GT {

    protected:
        void Test(const std::function<TsmResult(const Graph&)> &func) {
            auto res = func(graph_);
            ASSERT_EQ(res.vertices.size(), graph_.Size() + 1);
            ASSERT_TRUE((res.distance < std::get<3>(GetParam()) * graph_.Size() || res.distance == INFINITY) && res.distance > 0);
        }

    public:
        AlgorithmsGT() : GT() {}
};

class FileSalesmanGT : public FileGT {

    protected:
        int salesman_loop_count_ = 20;
        double salesman_distance_;
    
    void Tester() override {
            auto compare_result = Compare::Full(graph_, salesman_loop_count_);

            ASSERT_NEAR(compare_result.mean[0], salesman_distance_, salesman_distance_ / 1e3);
            ASSERT_NEAR(compare_result.mean[1], salesman_distance_, salesman_distance_ / 1e3);
            // ASSERT_NEAR(compare_result.mean[2], salesman_distance_, salesman_distance_ / 1e3);

            std::cout << "\nAnt colony:\n\tTime: " << compare_result.time[0] << " ms\n\tMean: " << compare_result.mean[0];
            std::cout << "\nGenetic:\n\tTime: " << compare_result.time[1] << " ms\n\tMean: " << compare_result.mean[1];
            std::cout << "\n ??? :\n\tTime: " << compare_result.time[2] << " ms\n\tMean: " << compare_result.mean[2];
            std::cout << "\n\n";
    }
};

} // namespace s21
