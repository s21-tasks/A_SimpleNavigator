#include "Tests.h"

using namespace s21;

INSTANTIATE_TEST_SUITE_P(GraphGTTests, GraphGT, testing::Combine(
    testing::Values(true, false), // directed
    testing::Values(100, 20, 5), // size
    testing::Values(0.7f, 0.1f, 0.0f, 1.0f), // zero probability
    testing::Values(10, 100) // max weight
));

TEST_P(GraphGT, Test1) {
    Tester();
}

static bool CheckDirected(const Graph &G) {
    for (int k = 0; k < G.Size(); ++k) {
        for (int i = k + 1; i < G.Size(); ++i) {
            if (G(k, i) != G(i, k)) {
                return false;
            }
        }
    }
    return true;
}

TEST(GraphTest, FileConstructor) {
    Graph G(SStr::RelativePath(__FILE__, "/../materials/1.txt"));
    ASSERT_EQ(G.Size(), 11);
    ASSERT_EQ(G.GetMatrix().GetCols(), 11);
    ASSERT_EQ(G.GetMatrix().GetRows(), 11);

    ASSERT_ANY_THROW(Graph GE(""));
    ASSERT_ANY_THROW(Graph GE("INCORRECT_FILE_PATH.txt"));
}

TEST(GraphTest, RandomConstructor) {
    ASSERT_ANY_THROW(Graph G(true, 1, 0.5, 10));
    ASSERT_ANY_THROW(Graph G(true, -1, 0.5, 10));
    ASSERT_ANY_THROW(Graph G(true, 5, 1.4, 10));
    ASSERT_ANY_THROW(Graph G(true, 5, -0.5, 10));
    ASSERT_ANY_THROW(Graph G(true, 5, 0.5, -10));
    ASSERT_ANY_THROW(Graph G(true, 5, 0.5, 0));
}
