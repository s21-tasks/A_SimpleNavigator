#include "Tests.h"

using namespace s21;

INSTANTIATE_TEST_SUITE_P(AntGTTests, AntGT, testing::Combine(
    testing::Values(true, false), // directed
    testing::Values(20, 5), // size
    testing::Values(0.7f, 0.1f), // zero probability
    testing::Values(10, 100) // max weight
));

TEST_P(AntGT, Test1) {
    auto res = colony_.Solve();
    ASSERT_EQ(res.vertices.size(), graph_.Size() + 1);
    ASSERT_TRUE((res.distance < std::get<3>(GetParam()) * graph_.Size() || res.distance == INFINITY) && res.distance > 0);
}

TEST(FileTest, Test1) {
    Graph G(SStr::RelativePath(__FILE__, "/../materials/test_files/1.txt"));
    double mean = 0.0;
    int count = 25;
    for (int k = 0; k < count; ++k) {
        mean += GraphAlgorithms::solveTravelingSalesmanProblem(G).distance;
    }
    ASSERT_NEAR(mean / (double)count, 253.0, 0.5);
}
