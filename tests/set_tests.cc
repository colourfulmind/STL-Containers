#include <gtest/gtest.h>

#include <set>

#include "../set/s21_set.h"

TEST(set_constructor, case1) {
  S21::Set<int> s21_set_int;
  S21::Set<double> s21_set_double;
  S21::Set<std::string> s21_set_string;

  EXPECT_EQ(s21_set_int.Size(), 0U);
  EXPECT_EQ(s21_set_double.Size(), 0U);
  EXPECT_EQ(s21_set_string.Size(), 0U);
}

TEST(set_constructor, case2) {
  S21::Set<int> s21_set_int{1, 2, 3, 4, 5};
  S21::Set<double> s21_set_double{1.30359, 2847.4925, 923.39281};
  S21::Set<std::string> s21_set_string{"Hello", ",", "world", "!"};

  EXPECT_EQ(s21_set_int.Size(), 5U);
  EXPECT_EQ(s21_set_double.Size(), 3U);
  EXPECT_EQ(s21_set_string.Size(), 4U);
}

TEST(set_constructor, case3) {
  S21::Set<int> s21_set_ref_int{1, 2, 3, 4, 5};
  S21::Set<int> s21_set_res_int{s21_set_ref_int};

  S21::Set<double> s21_set_ref_double{1.30359, 2847.4925, 923.39281};
  S21::Set<double> s21_set_res_double{s21_set_ref_double};

  S21::Set<std::string> s21_set_ref_string{"Hello", ",", "world", "!"};
  S21::Set<std::string> s21_set_res_string{s21_set_ref_string};

  EXPECT_EQ(s21_set_ref_int.Size(), s21_set_res_int.Size());
  EXPECT_EQ(s21_set_ref_double.Size(), s21_set_res_double.Size());
  EXPECT_EQ(s21_set_ref_string.Size(), s21_set_res_string.Size());
}

TEST(set_constructor, case4) {
  S21::Set<int> s21_set_ref_int{1, 2, 3, 4, 5};
  S21::Set<int> s21_set_res_int = std::move(s21_set_ref_int);

  S21::Set<double> s21_set_ref_double{1.30359, 2847.4925, 923.39281};
  S21::Set<double> s21_set_res_double = std::move(s21_set_ref_double);

  S21::Set<std::string> s21_set_ref_string{"Hello", ",", "world", "!"};
  S21::Set<std::string> s21_set_res_string = std::move(s21_set_ref_string);

  EXPECT_EQ(s21_set_ref_int.Size(), 0U);
  EXPECT_EQ(s21_set_res_int.Size(), 5U);

  EXPECT_EQ(s21_set_ref_double.Size(), 0U);
  EXPECT_EQ(s21_set_res_double.Size(), 3U);

  EXPECT_EQ(s21_set_ref_string.Size(), 0U);
  EXPECT_EQ(s21_set_res_string.Size(), 4U);
}

TEST(set_constructor, case5) {
  S21::Set<int> s21_set_ref_int{1, 2, 3, 4, 5};
  S21::Set<int> s21_set_res_int;
  s21_set_res_int = std::move(s21_set_ref_int);

  S21::Set<double> s21_set_ref_double{1.30359, 2847.4925, 923.39281};
  S21::Set<double> s21_set_res_double;
  s21_set_res_double = std::move(s21_set_ref_double);

  S21::Set<std::string> s21_set_ref_string{"Hello", ",", "world", "!"};
  S21::Set<std::string> s21_set_res_string;
  s21_set_res_string = std::move(s21_set_ref_string);

  EXPECT_EQ(s21_set_ref_int.Size(), 0U);
  EXPECT_EQ(s21_set_res_int.Size(), 5U);

  EXPECT_EQ(s21_set_ref_double.Size(), 0U);
  EXPECT_EQ(s21_set_res_double.Size(), 3U);

  EXPECT_EQ(s21_set_ref_string.Size(), 0U);
  EXPECT_EQ(s21_set_res_string.Size(), 4U);
}

TEST(set_constructor, case7) {
  S21::Set<int> s21_set_ref_int{1, 2, 3, 4};
  S21::Set<int> s21_set_res_int{s21_set_ref_int};

  S21::Set<double> s21_set_ref_double{1.30359, 2847.4925, 923.39281, 1.23};
  S21::Set<double> s21_set_res_double{s21_set_ref_double};

  S21::Set<std::string> s21_set_ref_string{"Hello", ",", "world", "!"};
  S21::Set<std::string> s21_set_res_string{s21_set_ref_string};

  auto it_res_int = s21_set_res_int.Begin();
  for (auto it_ref_int = s21_set_ref_int.Begin();
       it_ref_int != s21_set_ref_int.End(); ++it_ref_int) {
    EXPECT_EQ(*it_res_int, *it_ref_int);
    it_res_int++;
  }

  auto it_res_double = s21_set_res_double.Begin();
  for (auto it_ref_double = s21_set_ref_double.Begin();
       it_ref_double != s21_set_ref_double.End(); ++it_ref_double) {
    EXPECT_EQ(*it_res_double, *it_ref_double);
    it_res_double++;
  }

  auto it_res_string = s21_set_res_string.Begin();
  for (auto it_ref_string = s21_set_ref_string.Begin();
       it_ref_string != s21_set_ref_string.End(); ++it_ref_string) {
    EXPECT_EQ(*it_res_string, *it_ref_string);
    it_res_string++;
  }
}

TEST(set_insert, case1) {
  S21::Set<int> s21_set;

  std::pair<S21::Set<int>::iterator, bool> insert1 = s21_set.Insert(9);
  EXPECT_EQ(*insert1.first, 9);
  EXPECT_EQ(insert1.second, true);

  std::pair<S21::Set<int>::iterator, bool> insert2 = s21_set.Insert(9);
  std::pair<S21::Set<int>::iterator, bool> insert3 = s21_set.Insert(9);
  EXPECT_EQ(insert2.second, 0);
  EXPECT_EQ(insert3.second, false);

  std::pair<S21::Set<int>::iterator, bool> insert4 = s21_set.Insert(23);
  EXPECT_EQ(*insert4.first, 23);
  EXPECT_EQ(insert4.second, true);

  std::pair<S21::Set<int>::iterator, bool> insert5 = s21_set.Insert(98);
  EXPECT_EQ(*insert5.first, 98);
  EXPECT_EQ(insert5.second, true);

  EXPECT_EQ(s21_set.Size(), 3U);
}

TEST(set_insert, case2) {
  S21::Set<double> s21_set;

  std::pair<S21::Set<double>::iterator, bool> insert1 = s21_set.Insert(1.4);
  EXPECT_EQ(*insert1.first, 1.4);
  EXPECT_EQ(insert1.second, true);

  std::pair<S21::Set<double>::iterator, bool> insert2 = s21_set.Insert(2.77);
  EXPECT_EQ(*insert2.first, 2.77);
  EXPECT_EQ(insert2.second, true);

  std::pair<S21::Set<double>::iterator, bool> insert3 = s21_set.Insert(3.9);
  EXPECT_EQ(*insert3.first, 3.9);
  EXPECT_EQ(insert3.second, true);

  std::pair<S21::Set<double>::iterator, bool> insert4 = s21_set.Insert(2.77);
  std::pair<S21::Set<double>::iterator, bool> insert5 = s21_set.Insert(3.9);
  EXPECT_EQ(insert4.second, false);
  EXPECT_EQ(insert5.second, false);

  EXPECT_EQ(s21_set.Size(), 3U);
}

TEST(set_insert, case3) {
  S21::Set<std::string> s21_set;

  std::pair<S21::Set<std::string>::iterator, bool> insert1 =
      s21_set.Insert("hello");
  EXPECT_EQ(*insert1.first, "hello");
  EXPECT_EQ(insert1.second, true);

  std::pair<S21::Set<std::string>::iterator, bool> insert2 =
      s21_set.Insert("hi");
  EXPECT_EQ(*insert2.first, "hi");
  EXPECT_EQ(insert2.second, true);

  std::pair<S21::Set<std::string>::iterator, bool> insert3 =
      s21_set.Insert("hi");
  EXPECT_EQ(insert3.second, false);

  std::pair<S21::Set<std::string>::iterator, bool> insert4 =
      s21_set.Insert("hola");
  EXPECT_EQ(*insert4.first, "hola");
  EXPECT_EQ(insert4.second, true);

  std::pair<S21::Set<std::string>::iterator, bool> insert5 =
      s21_set.Insert("hello");
  EXPECT_EQ(insert5.second, false);

  EXPECT_EQ(s21_set.Size(), 3U);
}

TEST(set_insert, case4) {
  S21::Set<int> s21_set;

  std::pair<S21::Set<int>::iterator, bool> insert1 = s21_set.Insert(9);
  EXPECT_EQ(*insert1.first, 9);
  EXPECT_EQ(insert1.second, true);

  std::pair<S21::Set<int>::iterator, bool> insert2 = s21_set.Insert(9);
  std::pair<S21::Set<int>::iterator, bool> insert3 = s21_set.Insert(9);
  EXPECT_EQ(insert2.second, false);
  EXPECT_EQ(insert3.second, false);

  EXPECT_EQ(s21_set.Size(), 1U);
}

TEST(set_insert, case5) {
  S21::Set<double> s21_set = {21};

  std::pair<S21::Set<double>::iterator, bool> insert1 = s21_set.Insert(1.4);
  EXPECT_EQ(insert1.second, true);

  EXPECT_EQ(s21_set.Size(), 2U);
}

TEST(set_insert, case6) {
  S21::Set<std::string> s21_set = {"hello"};

  std::pair<S21::Set<std::string>::iterator, bool> insert1 =
      s21_set.Insert("hi");
  EXPECT_EQ(*insert1.first, "hi");
  EXPECT_EQ(insert1.second, true);

  EXPECT_EQ(s21_set.Size(), 2U);
}

TEST(set_begin, case1) {
  S21::Set<int> s21_set = {9, 15, 7, 23, 2};

  EXPECT_EQ(*s21_set.Begin(), 2);
}

TEST(set_begin, case2) {
  S21::Set<double> s21_set = {11.4, 2.770001, 3.901, 2.77, 3.9};

  EXPECT_EQ(*s21_set.Begin(), 2.77);
}

TEST(set_begin, case3) {
  S21::Set<std::string> s21_set = {"hello", "hi", "hi-hi", "hola",
                                   "hello, there"};

  EXPECT_EQ(*s21_set.Begin(), "hello");
}

TEST(set_begin, case4) {
  S21::Set<int> s21_set;

  EXPECT_THROW(s21_set.Begin(), std::out_of_range);
}

TEST(set_begin, case5) {
  S21::Set<double> s21_set = {1.4, 1.4};

  EXPECT_EQ(*s21_set.Begin(), 1.4);
}

TEST(set_begin, case6) {
  S21::Set<std::string> s21_set = {"hello", "hello", "hello"};

  EXPECT_EQ(*s21_set.Begin(), "hello");
}

TEST(set_end, case1) {
  S21::Set<int> s21_set = {9, 15, 7, 23, 2};

  EXPECT_EQ(*s21_set.End(), 23);
}

TEST(set_end, case2) {
  S21::Set<double> s21_set = {11.4, 2.770001, 3.901, 11.400000001, 3.9};

  EXPECT_EQ(*s21_set.End(), 11.400000001);
}

TEST(set_end, case3) {
  S21::Set<std::string> s21_set = {"hello", "hi", "hola-hola", "hola",
                                   "hello, there"};

  EXPECT_EQ(*s21_set.End(), "hola-hola");
}

TEST(set_end, case4) {
  S21::Set<int> s21_set;

  EXPECT_THROW(s21_set.End(), std::out_of_range);
}

TEST(set_end, case5) {
  S21::Set<double> s21_set = {1.4, 1.4};

  EXPECT_EQ(*s21_set.End(), 1.4);
}

TEST(set_end, case6) {
  S21::Set<std::string> s21_set = {"hello", "hello", "hello"};

  EXPECT_EQ(*s21_set.End(), "hello");
}

TEST(set_balance, case1) {
  S21::Set<int> s21_set = {1, 15, 5};

  EXPECT_EQ(*s21_set.End(), 15);
  EXPECT_EQ(s21_set.Size(), 3U);
}

TEST(set_balance, case2) {
  S21::Set<double> s21_set = {11.4, 2.770001, 3.901};

  EXPECT_EQ(*s21_set.End(), 11.4);
  EXPECT_EQ(s21_set.Size(), 3U);
}

TEST(set_balance, case3) {
  S21::Set<std::string> s21_set = {"hello", "hi", "hola-hola", "hola",
                                   "hello, there"};

  EXPECT_EQ(*s21_set.End(), "hola-hola");
  EXPECT_EQ(s21_set.Size(), 5U);
}

TEST(set_balance, case4) {
  S21::Set<int> s21_set = {10, 5, 20, 30, 1543};

  EXPECT_EQ(*s21_set.End(), 1543);
  EXPECT_EQ(*s21_set.Begin(), 5);
  EXPECT_EQ(s21_set.Size(), 5U);
}

TEST(set_balance, case5) {
  S21::Set<int> s21_set = {30, 5, 43, 1, 20, 40, 60, 35, 32};

  EXPECT_EQ(*s21_set.End(), 60);
  EXPECT_EQ(*s21_set.Begin(), 1);
  EXPECT_EQ(s21_set.Size(), 9U);
}

TEST(set_erase, case1) {
  S21::Set<int> s21_set = {10, 5, 15, 4, 18, 13, 16};

  auto it = s21_set.Begin();
  it++;
  it++;
  it++;
  it++;
  s21_set.Erase(it);
  EXPECT_EQ(*s21_set.Begin(), 4);
  EXPECT_EQ(*s21_set.End(), 18);
  EXPECT_EQ(s21_set.Size(), 6U);

  it = s21_set.Begin();
  s21_set.Erase(it);
  EXPECT_EQ(*s21_set.Begin(), 5);
  EXPECT_EQ(*s21_set.End(), 18);
  EXPECT_EQ(s21_set.Size(), 5U);

  it = s21_set.Begin();
  it++;
  s21_set.Erase(it);
  EXPECT_EQ(*s21_set.Begin(), 5);
  EXPECT_EQ(*s21_set.End(), 18);
  EXPECT_EQ(s21_set.Size(), 4U);

  it = s21_set.End();
  s21_set.Erase(it);
  EXPECT_EQ(*s21_set.Begin(), 5);
  EXPECT_EQ(*s21_set.End(), 16);
  EXPECT_EQ(s21_set.Size(), 3U);

  it = s21_set.Begin();
  it++;
  s21_set.Erase(it);

  it = s21_set.Begin();
  it++;
  s21_set.Erase(it);

  it = s21_set.Begin();
  s21_set.Erase(it);

  EXPECT_EQ(s21_set.Size(), 0U);
}

TEST(set_erase, case2) {
  S21::Set<int> s21_set = {30, 1543};

  auto it = s21_set.Begin();
  it += 1;
  s21_set.Erase(it);
  it = s21_set.Begin();
  s21_set.Erase(it);

  EXPECT_EQ(s21_set.Size(), 0U);
}

TEST(set_erase, case3) {
  S21::Set<std::string> s21_set = {"hello", "hi", "hola-hola", "hola",
                                   "hello, there"};

  auto it = s21_set.End();
  s21_set.Erase(it);
  EXPECT_EQ(*s21_set.End(), "hola");
  EXPECT_EQ(s21_set.Size(), 4U);

  it = s21_set.End();
  s21_set.Erase(it);
  EXPECT_EQ(*s21_set.End(), "hi");
  EXPECT_EQ(s21_set.Size(), 3U);

  s21_set.Insert("hola-hola");
  s21_set.Insert("hola");
  it = s21_set.End();
  s21_set.Erase(it);
  EXPECT_EQ(*s21_set.End(), "hola");
  EXPECT_EQ(s21_set.Size(), 4U);
}

TEST(set_erase, case4) {
  S21::Set<double> s21_set = {22.2, 12.4457, 56.84, 941.44, 44.48};

  auto it = s21_set.End();
  it--;
  s21_set.Erase(it);
  it = s21_set.End();
  EXPECT_EQ(*it, 941.44);
  EXPECT_EQ(s21_set.Size(), 4U);

  it = s21_set.Begin();
  ++it;
  ++it;
  ++it;
  s21_set.Erase(it);
  it = s21_set.Begin();
  ++it;
  ++it;
  ++it;
  EXPECT_EQ(*s21_set.End(), 44.48);
  EXPECT_EQ(s21_set.Size(), 3U);
}

TEST(set_erase, case5) {
  S21::Set<double> s21_set = {22.2, 44.48, 12.4457, 1.44};

  auto it = s21_set.Begin();
  it -= 1;
  s21_set.Erase(it);
  it = s21_set.Begin();
  ++it;
  ++it;
  EXPECT_EQ(*it, 44.48);
  EXPECT_EQ(s21_set.Size(), 3U);
}

TEST(set_erase, case6) {
  S21::Set<double> s21_set = {22.2, 44.48, 12.4457, 6.84, 1.44};

  auto it = s21_set.Begin();
  ++it;
  ++it;
  ++it;
  s21_set.Erase(it);
  it = s21_set.Begin();
  it += 3;
  EXPECT_EQ(*it, 44.48);
  EXPECT_EQ(s21_set.Size(), 4U);
}

TEST(set_erase, case7) {
  S21::Set<double> s21_set = {22.2, 12.4457, 56.84, 941.44, 44.48};

  auto it = s21_set.Begin();
  ++it;
  s21_set.Erase(it);
  it = s21_set.Begin();
  ++it;
  EXPECT_EQ(*it, 44.48);
  EXPECT_EQ(s21_set.Size(), 4U);
}

TEST(set_erase, case8) {
  S21::Set<double> s21_set = {22.2, 44.48, 12.4457, 1.44};

  auto it = s21_set.Begin();
  ++it;
  s21_set.Erase(it);
  it = s21_set.Begin();
  ++it;
  EXPECT_EQ(*it, 22.2);
  EXPECT_EQ(s21_set.Size(), 3U);
}

TEST(set_erase, case9) {
  S21::Set<double> s21_set = {22.2,  44.48, 12.4457, 32.45,
                              65.12, 66.32, 40.54,   6.4};

  auto it = s21_set.End();
  it -= 4;
  s21_set.Erase(it);
  it = s21_set.Begin();
  ++it;
  ++it;
  ++it;
  EXPECT_EQ(*it, 40.54);
  EXPECT_EQ(s21_set.Size(), 7U);
}

TEST(set_erase, case10) {
  S21::Set<double> s21_set = {22.2};

  auto it = s21_set.End();
  it -= 1;
  ++it;
  s21_set.Erase(it);
  EXPECT_EQ(s21_set.Size(), 0U);
}

TEST(set_empty, case1) {
  S21::Set<double> s21_set = {22.2, 44.48, 12.4457, 1.44};

  EXPECT_EQ(s21_set.Empty(), 0);
}

TEST(set_empty, case2) {
  S21::Set<double> s21_set;

  EXPECT_EQ(s21_set.Empty(), 1);
}

TEST(set_MaxSize, case1) {
  S21::Set<double> s21_set;
  std::set<double> std_set;

  EXPECT_EQ(s21_set.MaxSize(), std_set.max_size());
}

TEST(set_MaxSize, case2) {
  S21::Set<double> s21_set = {22.2, 44.48, 12.4457, 1.44};

  std::set<double> std_set = {22.2, 44.48, 12.4457, 1.44};

  EXPECT_EQ(s21_set.MaxSize(), std_set.max_size());
}

TEST(set_swap, case1) {
  S21::Set<double> s21_set_ref = {22.2, 44.48};
  S21::Set<double> s21_set_res = {12.4457, 1.44, 22.2};

  s21_set_ref.Swap(s21_set_res);

  EXPECT_EQ(s21_set_ref.Size(), 3U);
  EXPECT_EQ(*s21_set_ref.Begin(), 1.44);

  EXPECT_EQ(s21_set_res.Size(), 2U);
  EXPECT_EQ(*s21_set_res.Begin(), 22.2);
}

TEST(set_swap, case2) {
  S21::Set<double> s21_set_ref = {22.2, 44.48};
  S21::Set<double> s21_set_res;

  s21_set_ref.Swap(s21_set_res);

  EXPECT_EQ(s21_set_ref.Size(), 0U);

  EXPECT_EQ(s21_set_res.Size(), 2U);
  EXPECT_EQ(*s21_set_res.Begin(), 22.2);
}

TEST(set_swap, case3) {
  S21::Set<double> s21_set_ref;
  S21::Set<double> s21_set_res = {12.4457, 1.44, 22.2};

  s21_set_ref.Swap(s21_set_res);

  EXPECT_EQ(s21_set_ref.Size(), 3U);
  EXPECT_EQ(*s21_set_ref.Begin(), 1.44);

  EXPECT_EQ(s21_set_res.Size(), 0U);
}

TEST(set_swap, case4) {
  S21::Set<double> s21_set_ref;
  S21::Set<double> s21_set_res;

  s21_set_ref.Swap(s21_set_res);

  EXPECT_EQ(s21_set_ref.Size(), 0U);
  EXPECT_EQ(s21_set_res.Size(), 0U);
}

TEST(set_contains, case1) {
  S21::Set<double> s21_set = {22.2, 44.48};

  EXPECT_EQ(s21_set.Contains(22.2), true);
  EXPECT_EQ(s21_set.Contains(44.48), true);
}

TEST(set_contains, case2) {
  S21::Set<double> s21_set_ref = {22.2, 44.48};
  S21::Set<double> s21_set_res;

  s21_set_ref.Swap(s21_set_res);

  EXPECT_EQ(s21_set_ref.Size(), 0U);
  EXPECT_EQ(s21_set_ref.Contains(22.2), false);
  EXPECT_EQ(s21_set_ref.Contains(44.48), false);

  EXPECT_EQ(s21_set_res.Size(), 2U);
  EXPECT_EQ(s21_set_res.Contains(22.2), true);
  EXPECT_EQ(s21_set_res.Contains(44.48), true);
}

TEST(set_contains, case3) {
  S21::Set<double> s21_set_ref;
  S21::Set<double> s21_set_res = {12.4457, 1.44, 22.2};

  s21_set_ref.Swap(s21_set_res);

  EXPECT_EQ(s21_set_ref.Size(), 3U);
  EXPECT_EQ(s21_set_ref.Contains(12.4457), true);
  EXPECT_EQ(s21_set_ref.Contains(1.44), true);
  EXPECT_EQ(s21_set_ref.Contains(22.2), true);

  EXPECT_EQ(s21_set_res.Size(), 0U);
  EXPECT_EQ(s21_set_res.Contains(12.4457), false);
  EXPECT_EQ(s21_set_res.Contains(1.44), false);
  EXPECT_EQ(s21_set_res.Contains(22.2), false);
}

TEST(set_contains, case4) {
  S21::Set<double> s21_set;

  EXPECT_EQ(s21_set.Size(), 0U);
  EXPECT_EQ(s21_set.Contains(12.4457), false);
}

TEST(set_find, case1) {
  S21::Set<double> s21_set;

  EXPECT_THROW(s21_set.Find(23.4), std::out_of_range);
}

TEST(set_find, case2) {
  S21::Set<double> s21_set = {12.4457, 1.44, 22.2};

  auto it = s21_set.Begin();
  ++it;
  EXPECT_EQ(*s21_set.Find(12.4457), *it);

  it--;
  EXPECT_EQ(*s21_set.Find(1.44), *it);

  it += 2;
  EXPECT_EQ(*s21_set.Find(22.2), *it);
}

TEST(set_emplace, case1) {
  S21::Set<int> s21_set;

  std::vector<std::pair<S21::Set<int>::iterator, bool>> emplace1 =
      s21_set.Emplace(9, 9, 9, 23, 98);

  EXPECT_EQ(*emplace1[0].first, 23);
  EXPECT_EQ(emplace1[0].second, true);
  EXPECT_EQ(s21_set.Size(), 3U);
}

TEST(set_emplace, case2) {
  S21::Set<double> s21_set;

  std::vector<std::pair<S21::Set<double>::iterator, bool>> emplace1 =
      s21_set.Emplace(1.4, 2.77, 3.9, 2.77, 3.9);

  EXPECT_EQ(*emplace1[0].first, 2.77);
  EXPECT_EQ(emplace1[0].second, true);
  EXPECT_EQ(s21_set.Size(), 3U);
}

TEST(set_emplace, case3) {
  S21::Set<std::string> s21_set;

  std::vector<std::pair<S21::Set<std::string>::iterator, bool>> emplace1 =
      s21_set.Emplace("hello", "hi", "hi", "hola", "hello");

  EXPECT_EQ(*emplace1[0].first, "hi");
  EXPECT_EQ(emplace1[0].second, true);
  EXPECT_EQ(s21_set.Size(), 3U);
}

TEST(set_emplace, case4) {
  S21::Set<int> s21_set;

  std::vector<std::pair<S21::Set<int>::iterator, bool>> emplace1 =
      s21_set.Emplace(9);

  EXPECT_EQ(*emplace1[0].first, 9);
  EXPECT_EQ(emplace1[0].second, true);
  EXPECT_EQ(s21_set.Size(), 1U);
}

TEST(set_emplace, case5) {
  S21::Set<double> s21_set = {1.4};

  std::vector<std::pair<S21::Set<double>::iterator, bool>> emplace1 =
      s21_set.Emplace(1.4);

  EXPECT_EQ(emplace1[0].second, false);
  EXPECT_EQ(s21_set.Size(), 1U);
}

TEST(set_emplace, case6) {
  S21::Set<std::string> s21_set = {"hello"};

  std::vector<std::pair<S21::Set<std::string>::iterator, bool>> emplace1 =
      s21_set.Emplace("hi");

  EXPECT_EQ(*emplace1[0].first, "hi");
  EXPECT_EQ(emplace1[0].second, true);
  EXPECT_EQ(s21_set.Size(), 2U);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
