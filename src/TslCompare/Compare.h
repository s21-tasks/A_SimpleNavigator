#pragma once

#include "../Graph.h"
#include "../GraphAlgorithms.h"
#include "../lib/time.h"

namespace s21 {

typedef std::vector<int64_t> TimeResult;

struct CompareResult {
    TimeResult time;
    std::vector<double> mean;
    CompareResult(int N) : mean(N) {}
};

class Compare {
    public:
        static TimeResult Time(Graph &G, int N);
        static CompareResult Full(Graph &G, int N);
};

} // namespace s21
