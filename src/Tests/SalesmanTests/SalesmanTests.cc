#include "SalesmanTests.h"

using namespace s21;

INSTANTIATE_TEST_SUITE_P(
    AlgorithmsGTTests, AlgorithmsGT,
    testing::Combine(testing::Values(true, false),       // directed, undirected
                     testing::Values(6, 5),              // size
                     testing::Values(0.7f, 0.1f, 0.0f),  // zero probability
                     testing::Values(10, 100)            // max weight
                     ));

TEST_P(AlgorithmsGT, SalesmanProblem) { Test(); }

TEST_F(FileSalesmanGT, Test1) {
  file_name_ = "c1.txt";
  salesman_loop_count_ = 2;
  salesman_distance_ = 253.0;
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
