#include "SalesmanTests.h"

using namespace s21;

// INSTANTIATE_TEST_SUITE_P(AlgorithmsGTTests, AlgorithmsGT, testing::Combine(
//     testing::Values(true, false), // directed, undirected
//     testing::Values(6, 5), // size
//     testing::Values(0.7f, 0.1f), // zero probability
//     testing::Values(10, 100) // max weight
// ));

// TEST_P(AlgorithmsGT, SalesmanProblem) {
//     Test();
// }

// int main() {
//     Graph G("materials/test_files/c10.txt");
//     // Graph G(true, 7, 0.0, 10);
//     G.PrintMatrix();

//     auto func = [&G] (std::function<TsmResult(Graph)> tf) {
//         auto res = tf(G);
//         int d = 0;
//         for (int k = 0; k < (int)res.vertices.size() - 1; ++k) {
//             d += G(res.vertices[k], res.vertices[k + 1]);
//             if (G(res.vertices[k], res.vertices[k + 1]) == 0) {
//                 std::cout << res.vertices[k] << ' ' << res.vertices[k + 1] << " SUKA\n";
//             }
//         }
//         SStr::Print<' '>(res.vertices, res.distance, d, '\n');
//     };
//     func(GraphAlgorithms::BnBSolveSalesmanProblem);
//     func(GraphAlgorithms::solveTravelingSalesmanProblem);
//     // func(GraphAlgorithms::GeneticSolveSalesmanProblem);

//     return 0;
// }

TEST_F(FileSalesmanGT, Test1) {
    file_name_ = "c1.txt";
    salesman_loop_count_ = 2;
    salesman_distance_ = 253.0;
    Test();
}

TEST_F(FileSalesmanGT, Test2) {
    file_name_ = "c2.txt";
    salesman_loop_count_ = 1;
    Test();
}

TEST_F(FileSalesmanGT, Test7) {
    salesman_loop_count_ = 15;
    file_name_ = "c7.txt";
    Test();
}

TEST_F(FileSalesmanGT, Test9) {
    salesman_loop_count_ = 25;
    file_name_ = "c9.txt";
    Test();
}

TEST_F(FileSalesmanGT, Test10) {
    salesman_loop_count_ = 25;
    file_name_ = "c10.txt";
    Test();
}
