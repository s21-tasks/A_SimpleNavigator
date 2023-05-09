#include "Compare.h"

// #include "sstr.h"



namespace s21 {

TimeResult Compare::Time(Graph &G, int N) {
    return Time::Compare(N, [&] {
        GraphAlgorithms::solveTravelingSalesmanProblem(G);
    }, [&] {
        // 2 algorithm
    }, [&] {
        // 3 algorithm
    });
}

CompareResult Compare::Full(Graph &G, int N) {
    CompareResult result(3);
    result.time = std::move(Time::Compare(N, [&] {
        result.mean[0] += GraphAlgorithms::solveTravelingSalesmanProblem(G).distance / (double)N;
    }, [&] {
        result.mean[1] = 0; // 2 algorithm
    }, [&] {
        result.mean[2] = 0; // 3 algorithm
    }));
    return result;
}

} // namespace s21

using namespace s21;

// int main() {
//     Graph G;
//     G.LoadGraphFromFile("../1.txt");
//     G.PrintMatrix();
//     auto res = s21::Compare::Full(G, 10);
//     SStr::Print(res.mean, res.time);
//     SStr::Print(s21::Compare::Time(G, 10));
//     return 0;
// }
