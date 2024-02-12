#include <gtest/gtest.h>

#include <stack>

#include "../s21_containers.h"

TEST(STACK, case1) {
  S21::Stack<int> s21_stack_int;
  S21::Stack<double> s21_stack_double;
  S21::Stack<std::string> s21_stack_string;

  EXPECT_EQ(s21_stack_int.Size(), 0U);
  EXPECT_THROW(s21_stack_int.Top(), std::logic_error);
  EXPECT_THROW(s21_stack_int.Pop(), std::logic_error);

  EXPECT_EQ(s21_stack_double.Size(), 0U);
  EXPECT_THROW(s21_stack_double.Top(), std::logic_error);
  EXPECT_THROW(s21_stack_double.Pop(), std::logic_error);

  EXPECT_EQ(s21_stack_string.Size(), 0U);
  EXPECT_THROW(s21_stack_string.Top(), std::logic_error);
  EXPECT_THROW(s21_stack_string.Pop(), std::logic_error);
}

TEST(STACK, case2) {
  S21::Stack<int> s21_stack_int{1, 4, 8, 9, 1};
  S21::Stack<double> s21_stack_double{1.4, 4.8, 8.9, 9.1, 1.1};
  S21::Stack<std::string> s21_stack_string{"Hello", ",", "world", "!", "!!"};

  EXPECT_EQ(s21_stack_int.Size(), 5U);
  EXPECT_EQ(s21_stack_int.Top(), 1);

  EXPECT_EQ(s21_stack_double.Size(), 5U);
  EXPECT_EQ(s21_stack_double.Top(), 1.1);

  EXPECT_EQ(s21_stack_string.Size(), 5U);
  EXPECT_EQ(s21_stack_string.Top(), "!!");
}

TEST(STACK, case3) {
  S21::Stack<int> s21_stack_ref_int{1, 4, 8, 9, 1};
  S21::Stack<int> s21_stack_res_int(s21_stack_ref_int);

  S21::Stack<double> s21_stack_ref_double{1.4, 4.8, 8.9, 9.1, 1.1};
  S21::Stack<double> s21_stack_res_double(s21_stack_ref_double);

  S21::Stack<std::string> s21_stack_ref_string{"Hello", ",", "world", "!",
                                               "!!"};
  S21::Stack<std::string> s21_stack_res_string(s21_stack_ref_string);

  EXPECT_EQ(s21_stack_res_int.Size(), 5U);
  EXPECT_EQ(s21_stack_res_int.Top(), 1);

  EXPECT_EQ(s21_stack_res_double.Size(), 5U);
  EXPECT_EQ(s21_stack_res_double.Top(), 1.1);

  EXPECT_EQ(s21_stack_res_string.Size(), 5U);
  EXPECT_EQ(s21_stack_res_string.Top(), "!!");
}

TEST(STACK, case4) {
  S21::Stack<int> s21_stack_ref_int{1, 4, 8, 9, 1};
  S21::Stack<int> s21_stack_res_int = s21_stack_ref_int;

  S21::Stack<double> s21_stack_ref_double{1.4, 4.8, 8.9, 9.1, 1.1};
  S21::Stack<double> s21_stack_res_double = s21_stack_ref_double;

  S21::Stack<std::string> s21_stack_ref_string{"Hello", ",", "world", "!",
                                               "!!"};
  S21::Stack<std::string> s21_stack_res_string = s21_stack_ref_string;

  EXPECT_EQ(s21_stack_res_int.Size(), 5U);
  EXPECT_EQ(s21_stack_res_int.Top(), 1);

  EXPECT_EQ(s21_stack_res_double.Size(), 5U);
  EXPECT_EQ(s21_stack_res_double.Top(), 1.1);

  EXPECT_EQ(s21_stack_res_string.Size(), 5U);
  EXPECT_EQ(s21_stack_res_string.Top(), "!!");
}

TEST(STACK, case5) {
  S21::Stack<int> s21_stack_ref_int{1, 4, 8, 9, 1};
  S21::Stack<int> s21_stack_res_int = std::move(s21_stack_ref_int);

  S21::Stack<double> s21_stack_ref_double{1.4, 4.8, 8.9, 9.1, 1.1};
  S21::Stack<double> s21_stack_res_double = std::move(s21_stack_ref_double);

  S21::Stack<std::string> s21_stack_ref_string{"Hello", ",", "world", "!",
                                               "!!"};
  S21::Stack<std::string> s21_stack_res_string =
      std::move(s21_stack_ref_string);

  EXPECT_EQ(s21_stack_ref_int.Size(), 0U);
  EXPECT_EQ(s21_stack_res_int.Size(), 5U);
  EXPECT_EQ(s21_stack_res_int.Top(), 1);

  EXPECT_EQ(s21_stack_ref_double.Size(), 0U);
  EXPECT_EQ(s21_stack_res_double.Size(), 5U);
  EXPECT_EQ(s21_stack_res_double.Top(), 1.1);

  EXPECT_EQ(s21_stack_ref_string.Size(), 0U);
  EXPECT_EQ(s21_stack_res_string.Size(), 5U);
  EXPECT_EQ(s21_stack_res_string.Top(), "!!");
}

TEST(STACK, case6) {
  S21::Stack<int> s21_stack_ref_int{1, 4, 8, 9, 1};
  S21::Stack<int> s21_stack_res_int;
  s21_stack_res_int = std::move(s21_stack_ref_int);

  S21::Stack<double> s21_stack_ref_double{1.4, 4.8, 8.9, 9.1, 1.1};
  S21::Stack<double> s21_stack_res_double;
  s21_stack_res_double = std::move(s21_stack_ref_double);

  S21::Stack<std::string> s21_stack_ref_string{"Hello", ",", "world", "!",
                                               "!!"};
  S21::Stack<std::string> s21_stack_res_string;
  s21_stack_res_string = std::move(s21_stack_ref_string);

  EXPECT_EQ(s21_stack_ref_int.Size(), 0U);
  EXPECT_EQ(s21_stack_res_int.Size(), 5U);
  EXPECT_EQ(s21_stack_res_int.Top(), 1);

  EXPECT_EQ(s21_stack_ref_double.Size(), 0U);
  EXPECT_EQ(s21_stack_res_double.Size(), 5U);
  EXPECT_EQ(s21_stack_res_double.Top(), 1.1);

  EXPECT_EQ(s21_stack_ref_string.Size(), 0U);
  EXPECT_EQ(s21_stack_res_string.Size(), 5U);
  EXPECT_EQ(s21_stack_res_string.Top(), "!!");
}

TEST(STACK, case7) {
  int n = 1e4;
  S21::Stack<int> st = {};
  std::stack<int> orig_st = {};
  for (int i = 0; i < n; i++) {
    st.Push(i);
    orig_st.push(i);
  }
  EXPECT_EQ(st.Size(), orig_st.size());
  st.Pop();
  st.Pop();
  orig_st.pop();
  orig_st.pop();
  EXPECT_EQ(st.Size(), orig_st.size());
  int top = st.Top();
  int orig_top = orig_st.top();
  EXPECT_EQ(top, orig_top);
}

TEST(STACK_EMPTY, case1) {
  S21::Stack<int> s21_stack_int{1, 4, 8, 9, 1};
  S21::Stack<double> s21_stack_double{1.4, 4.8, 8.9, 9.1, 1.1};
  S21::Stack<std::string> s21_stack_string{"Hello", ",", "world", "!", "!!"};

  EXPECT_EQ(s21_stack_int.Empty(), 0);
  EXPECT_EQ(s21_stack_double.Empty(), 0);
  EXPECT_EQ(s21_stack_string.Empty(), 0);
}

TEST(STACK_EMPTY, case2) {
  S21::Stack<int> s21_stack_int;
  S21::Stack<double> s21_stack_double;
  S21::Stack<std::string> s21_stack_string;

  EXPECT_EQ(s21_stack_int.Empty(), 1);
  EXPECT_EQ(s21_stack_double.Empty(), 1);
  EXPECT_EQ(s21_stack_string.Empty(), 1);
}

TEST(STACK_SIZE, case1) {
  S21::Stack<int> s21_stack_int{1, 4, 8, 9, 1};
  S21::Stack<double> s21_stack_double{1.4, 4.8, 8.9, 9.1, 1.1};
  S21::Stack<std::string> s21_stack_string{"Hello", ",", "world", "!", "!!"};

  EXPECT_EQ(s21_stack_int.Size(), 5U);
  EXPECT_EQ(s21_stack_double.Size(), 5U);
  EXPECT_EQ(s21_stack_string.Size(), 5U);
}

TEST(STACK_SIZE, case2) {
  S21::Stack<int> s21_stack_int;
  S21::Stack<double> s21_stack_double;
  S21::Stack<std::string> s21_stack_string;

  EXPECT_EQ(s21_stack_int.Size(), 0U);
  EXPECT_EQ(s21_stack_double.Size(), 0U);
  EXPECT_EQ(s21_stack_string.Size(), 0U);
}

TEST(STACK_TOP, case1) {
  S21::Stack<int> s21_stack_int{1, 4, 8, 9, 1};
  S21::Stack<double> s21_stack_double{1.4, 4.8, 8.9, 9.1, 1.1};
  S21::Stack<std::string> s21_stack_string{"Hello", ",", "world", "!", "!!"};

  EXPECT_EQ(s21_stack_int.Top(), 1);
  EXPECT_EQ(s21_stack_double.Top(), 1.1);
  EXPECT_EQ(s21_stack_string.Top(), "!!");
}

TEST(STACK_TOP, case2) {
  S21::Stack<int> s21_stack_int;
  S21::Stack<double> s21_stack_double;
  S21::Stack<std::string> s21_stack_string;

  EXPECT_THROW(s21_stack_int.Top(), std::logic_error);
  EXPECT_THROW(s21_stack_double.Top(), std::logic_error);
  EXPECT_THROW(s21_stack_string.Top(), std::logic_error);
}

TEST(STACK_PUSH, case1) {
  S21::Stack<int> s21_stack_int{1, 4, 8, 9, 1};
  S21::Stack<double> s21_stack_double{1.4, 4.8, 8.9, 9.1, 1.1};
  S21::Stack<std::string> s21_stack_string{"Hello", ",", "world", "!", "!!"};

  s21_stack_int.Push(255);
  s21_stack_double.Push(255.0);
  s21_stack_string.Push("255");

  EXPECT_EQ(s21_stack_int.Top(), 255);
  EXPECT_EQ(s21_stack_double.Top(), 255.0);
  EXPECT_EQ(s21_stack_string.Top(), "255");
}

TEST(STACK_PUSH, case2) {
  S21::Stack<int> s21_stack_int;
  S21::Stack<double> s21_stack_double;
  S21::Stack<std::string> s21_stack_string;

  s21_stack_int.Push(255);
  s21_stack_double.Push(255.0);
  s21_stack_string.Push("255");

  EXPECT_EQ(s21_stack_int.Top(), 255);
  EXPECT_EQ(s21_stack_double.Top(), 255.0);
  EXPECT_EQ(s21_stack_string.Top(), "255");
}

TEST(STACK_POP, case1) {
  S21::Stack<int> s21_stack_int{1, 4, 8, 9, 1};
  S21::Stack<double> s21_stack_double{1.4, 4.8, 8.9, 9.1, 1.1};
  S21::Stack<std::string> s21_stack_string{"Hello", ",", "world", "!", "!!"};

  s21_stack_int.Pop();
  s21_stack_double.Pop();
  s21_stack_string.Pop();

  EXPECT_EQ(s21_stack_int.Top(), 9);
  EXPECT_EQ(s21_stack_double.Top(), 9.1);
  EXPECT_EQ(s21_stack_string.Top(), "!");
}

TEST(STACK_POP, case2) {
  S21::Stack<int> s21_stack_int;
  S21::Stack<double> s21_stack_double;
  S21::Stack<std::string> s21_stack_string;

  EXPECT_THROW(s21_stack_int.Pop(), std::logic_error);
  EXPECT_THROW(s21_stack_double.Pop(), std::logic_error);
  EXPECT_THROW(s21_stack_string.Pop(), std::logic_error);
}

TEST(STACK_SWAP, case1) {
  S21::Stack<int> s21_stack_ref_int{1, 4, 8, 9, 1};
  S21::Stack<int> s21_stack_res_int;

  S21::Stack<double> s21_stack_ref_double{1.4, 4.8, 8.9, 9.1, 1.1};
  S21::Stack<double> s21_stack_res_double;

  S21::Stack<std::string> s21_stack_ref_string{"Hello", ",", "world", "!",
                                               "!!"};
  S21::Stack<std::string> s21_stack_res_string;

  s21_stack_ref_int.Swap(s21_stack_res_int);
  s21_stack_ref_double.Swap(s21_stack_res_double);
  s21_stack_ref_string.Swap(s21_stack_res_string);

  EXPECT_EQ(s21_stack_ref_int.Size(), 0U);
  EXPECT_EQ(s21_stack_res_int.Size(), 5U);
  EXPECT_EQ(s21_stack_res_int.Top(), 1);

  EXPECT_EQ(s21_stack_ref_double.Size(), 0U);
  EXPECT_EQ(s21_stack_res_double.Size(), 5U);
  EXPECT_EQ(s21_stack_res_double.Top(), 1.1);

  EXPECT_EQ(s21_stack_ref_string.Size(), 0U);
  EXPECT_EQ(s21_stack_res_string.Size(), 5U);
  EXPECT_EQ(s21_stack_res_string.Top(), "!!");
}

TEST(STACK_SWAP, case2) {
  S21::Stack<int> s21_stack_ref_int{1, 4, 8, 9, 1};
  S21::Stack<int> s21_stack_res_int{12, 13, 14};

  S21::Stack<double> s21_stack_ref_double{1.4, 4.8, 8.9, 9.1, 1.1};
  S21::Stack<double> s21_stack_res_double{13.0};

  S21::Stack<std::string> s21_stack_ref_string{"Hello", ",", "world", "!",
                                               "!!"};
  S21::Stack<std::string> s21_stack_res_string{"14", "15"};

  s21_stack_ref_int.Swap(s21_stack_res_int);
  s21_stack_ref_double.Swap(s21_stack_res_double);
  s21_stack_ref_string.Swap(s21_stack_res_string);

  EXPECT_EQ(s21_stack_ref_int.Size(), 3U);
  EXPECT_EQ(s21_stack_ref_int.Top(), 14);
  EXPECT_EQ(s21_stack_res_int.Size(), 5U);
  EXPECT_EQ(s21_stack_res_int.Top(), 1);

  EXPECT_EQ(s21_stack_ref_double.Size(), 1U);
  EXPECT_EQ(s21_stack_ref_double.Top(), 13.0);
  EXPECT_EQ(s21_stack_res_double.Size(), 5U);
  EXPECT_EQ(s21_stack_res_double.Top(), 1.1);

  EXPECT_EQ(s21_stack_ref_string.Size(), 2U);
  EXPECT_EQ(s21_stack_ref_string.Top(), "15");
  EXPECT_EQ(s21_stack_res_string.Size(), 5U);
  EXPECT_EQ(s21_stack_res_string.Top(), "!!");
}
