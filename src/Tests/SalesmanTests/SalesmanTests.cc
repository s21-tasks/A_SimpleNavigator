#include "SalesmanTests.h"

using namespace s21;

INSTANTIATE_TEST_SUITE_P(AlgorithmsGTTests, AlgorithmsGT, testing::Combine(
    testing::Values(true, false), // directed
    testing::Values(20, 5), // size
    testing::Values(0.7f, 0.1f), // zero probability
    testing::Values(10, 100) // max weight
));

TEST_P(AlgorithmsGT, SalesmanProblem) {
    Test(GraphAlgorithms::solveTravelingSalesmanProblem);
    // Test(GraphAlgorithms::GeneticSolveSalesmanProblem);
    // Test(GraphAlgorithms::???);
}


TEST_F(FileSalesmanGT, Test1) {
    file_name_ = "c1.txt";
    salesman_distance_ = 253.0;
    Test();
}
