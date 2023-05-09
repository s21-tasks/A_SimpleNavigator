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

TEST(GraphTest, FileConstructor1) {
    Graph G(SStr::RelativePath(__FILE__, "/../materials/test_files/1.txt"));
    ASSERT_EQ(G.Size(), 11);
    ASSERT_EQ(G.GetMatrix().GetCols(), 11);
    ASSERT_EQ(G.GetMatrix().GetRows(), 11);
    ASSERT_EQ(G.Directed(), false);
}

TEST(GraphTest, FileConstructor2) {
    Graph G(SStr::RelativePath(__FILE__, "/../materials/test_files/2.txt"));
    ASSERT_EQ(G.Size(), 15);
    ASSERT_EQ(G.Directed(), true);
}

TEST(GraphTest, FileConstructor3) {
    ASSERT_ANY_THROW(Graph G(SStr::RelativePath(__FILE__, "/../materials/test_files/3.txt")));
}

TEST(GraphTest, FileConstructor4) {
    ASSERT_ANY_THROW(Graph G(SStr::RelativePath(__FILE__, "/../materials/test_files/4.txt")));
}

TEST(GraphTest, FileConstructor5) {
    ASSERT_ANY_THROW(Graph G(SStr::RelativePath(__FILE__, "/../materials/test_files/5.txt")));
}

TEST(GraphTest, FileConstructor6) {
    ASSERT_ANY_THROW(Graph G(SStr::RelativePath(__FILE__, "/../materials/test_files/6.txt")));
}

TEST(GraphTest, FileConstructor7) {
    ASSERT_ANY_THROW(Graph G(SStr::RelativePath(__FILE__, "/../materials/test_files/7.txt")));
}

TEST(GraphTest, FileConstructor8) {
    ASSERT_ANY_THROW(Graph G(SStr::RelativePath(__FILE__, "/../materials/test_files/8.txt")));
}

TEST(GraphTest, FileConstructor9) {
    ASSERT_ANY_THROW(Graph G(SStr::RelativePath(__FILE__, "/../materials/test_files/9.txt")));
}

TEST(GraphTest, FileConstructor10) {
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
