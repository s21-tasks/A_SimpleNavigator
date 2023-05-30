#include "GraphTests.h"

using namespace s21;

INSTANTIATE_TEST_SUITE_P(
    GraphGTTests, GraphGT,
    testing::Combine(testing::Values(true, false),  // directed
                     testing::Values(100, 20, 5),   // size
                     testing::Values(0.7f, 0.1f, 0.0f,
                                     1.0f),    // zero probability
                     testing::Values(10, 100)  // max weight
                     ));

TEST_P(GraphGT, Test1) { Tester(); }

TEST(GraphTest, FileConstructor1) {
  Graph G(GT::FilePath("c1.txt"));
  ASSERT_EQ(G.Size(), 11);
  ASSERT_EQ(G.GetMatrix().GetCols(), 11);
  ASSERT_EQ(G.GetMatrix().GetRows(), 11);
  ASSERT_EQ(G.Directed(), false);
}

TEST(GraphTest, FileConstructor2) {
  Graph G(GT::FilePath("c2.txt"));
  ASSERT_EQ(G.Size(), 15);
  ASSERT_EQ(G.Directed(), true);
}

TEST(GraphTest, FileConstructor3) {
  Graph G(GT::FilePath("c3.txt"));
  ASSERT_EQ(G.Size(), 50);
  ASSERT_EQ(G.Directed(), false);
}

TEST(GraphTest, FileConstructor4) {
  Graph G(GT::FilePath("c4.txt"));
  ASSERT_EQ(G.Size(), 37);
  ASSERT_EQ(G.Directed(), true);
}

TEST(GraphTest, FileConstructor5) {
  Graph G(GT::FilePath("c5.txt"));
  ASSERT_EQ(G.Size(), 2);
  ASSERT_EQ(G.Directed(), false);
}

TEST(GraphTest, FileConstructor6) {
  Graph G(GT::FilePath("c6.txt"));
  ASSERT_EQ(G.Size(), 75);
  ASSERT_EQ(G.Directed(), true);
}

TEST(GraphTest, FileConstructorError1) {
  ASSERT_ANY_THROW(Graph G(GT::FilePath("u1.txt")));
}

TEST(GraphTest, FileConstructorError2) {
  ASSERT_ANY_THROW(Graph G(GT::FilePath("u2.txt")));
}

TEST(GraphTest, FileConstructorError3) {
  ASSERT_ANY_THROW(Graph G(GT::FilePath("u3.txt")));
}

TEST(GraphTest, FileConstructorError4) {
  ASSERT_ANY_THROW(Graph G(GT::FilePath("u4.txt")));
}

TEST(GraphTest, FileConstructorError5) {
  ASSERT_ANY_THROW(Graph G(GT::FilePath("u5.txt")));
}

TEST(GraphTest, FileConstructorError6) {
  ASSERT_ANY_THROW(Graph G(GT::FilePath("u6.txt")));
}

TEST(GraphTest, FileConstructorError7) {
  ASSERT_ANY_THROW(Graph G(GT::FilePath("u7.txt")));
}

TEST(GraphTest, FileConstructorError8) {
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
