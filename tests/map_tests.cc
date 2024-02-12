#include <gtest/gtest.h>

#include <map>

#include "../map/s21_map.h"

TEST(map_constructor, case1) {
  S21::Map<int, int> s21_map_int;
  S21::Map<double, double> s21_map_double;
  S21::Map<std::string, std::string> s21_map_string;

  EXPECT_EQ(s21_map_int.Size(), 0U);
  EXPECT_EQ(s21_map_double.Size(), 0U);
  EXPECT_EQ(s21_map_string.Size(), 0U);
}

TEST(map_constructor, case2) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{23, 2.77};
  std::pair<int, double> pair3{98, 3.9};

  S21::Map<int, double> s21_map = {pair1, pair2, pair3};

  EXPECT_EQ(s21_map.Size(), 3U);
}

TEST(map_constructor, case3) {
  std::pair<double, std::string> pair1{1.4, "hello"};
  std::pair<double, std::string> pair2{2.77, "hi"};
  std::pair<double, std::string> pair3{3.9, "hola"};

  S21::Map<double, std::string> s21_map = {pair1, pair2, pair3};

  EXPECT_EQ(s21_map.Size(), 3U);
}

TEST(map_constructor, case4) {
  std::pair<std::string, int> pair1{"hello", 1};
  std::pair<std::string, int> pair2{"hi", 2};
  std::pair<std::string, int> pair3{"hola", 3};

  S21::Map<std::string, int> s21_map = {pair1, pair2, pair3};

  EXPECT_EQ(s21_map.Size(), 3U);
}

TEST(map_constructor, case5) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<double, std::string> pair2{2.77, "hi"};
  std::pair<std::string, int> pair3{"hola", 3};

  S21::Map<int, double> s21_map_int{pair1};
  S21::Map<double, std::string> s21_map_double{pair2};
  S21::Map<std::string, int> s21_map_string{pair3};

  EXPECT_EQ(s21_map_int.Size(), 1U);
  EXPECT_EQ(s21_map_double.Size(), 1U);
  EXPECT_EQ(s21_map_string.Size(), 1U);

  S21::Tree<int, double> s21_tree_int(pair1);
  S21::Tree<double, std::string> s21_tree_double(pair2);
  S21::Tree<std::string, int> s21_tree_string(pair3);

  EXPECT_EQ(s21_tree_int.Size(), 1U);
  EXPECT_EQ(s21_tree_double.Size(), 1U);
  EXPECT_EQ(s21_tree_string.Size(), 1U);
}

// конструктор копирования
TEST(map_constructor, case6) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{23, 2.77};
  std::pair<int, double> pair3{98, 3.9};

  S21::Map<int, double> s21_map_ref = {pair1, pair2, pair3};
  S21::Map<int, double> s21_map_res(s21_map_ref);

  EXPECT_EQ(s21_map_res.Size(), s21_map_ref.Size());
}

TEST(map_constructor, case7) {
  std::pair<double, std::string> pair1{1.4, "hello"};
  std::pair<double, std::string> pair2{2.77, "hi"};
  std::pair<double, std::string> pair3{3.9, "hola"};

  S21::Map<double, std::string> s21_map_ref = {pair1, pair2, pair3};
  S21::Map<double, std::string> s21_map_res(s21_map_ref);

  EXPECT_EQ(s21_map_res.Size(), s21_map_ref.Size());
}

TEST(map_constructor, case8) {
  std::pair<std::string, int> pair1{"hello", 1};
  std::pair<std::string, int> pair2{"hi", 2};
  std::pair<std::string, int> pair3{"hola", 3};

  S21::Map<std::string, int> s21_map_ref = {pair1, pair2, pair3};
  S21::Map<std::string, int> s21_map_res(s21_map_ref);

  EXPECT_EQ(s21_map_res.Size(), s21_map_ref.Size());
}

// конструктор перемещения
TEST(map_constructor, case9) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{23, 2.77};
  std::pair<int, double> pair3{98, 3.9};

  S21::Map<int, double> s21_map_ref = {pair1, pair2, pair3};
  S21::Map<int, double> s21_map_res = std::move(s21_map_ref);

  EXPECT_EQ(s21_map_ref.Size(), 0U);
  EXPECT_EQ(s21_map_res.Size(), 3U);
}

TEST(map_constructor, case10) {
  std::pair<double, std::string> pair1{1.4, "hello"};
  std::pair<double, std::string> pair2{2.77, "hi"};
  std::pair<double, std::string> pair3{3.9, "hola"};

  S21::Map<double, std::string> s21_map_ref = {pair1, pair2, pair3};
  S21::Map<double, std::string> s21_map_res = std::move(s21_map_ref);

  EXPECT_EQ(s21_map_ref.Size(), 0U);
  EXPECT_EQ(s21_map_res.Size(), 3U);
}

TEST(map_constructor, case11) {
  std::pair<std::string, int> pair1{"hello", 1};
  std::pair<std::string, int> pair2{"hi", 2};
  std::pair<std::string, int> pair3{"hola", 3};

  S21::Map<std::string, int> s21_map_ref = {pair1, pair2, pair3};
  S21::Map<std::string, int> s21_map_res = std::move(s21_map_ref);

  EXPECT_EQ(s21_map_ref.Size(), 0U);
  EXPECT_EQ(s21_map_res.Size(), 3U);
}

// оператор =
TEST(map_constructor, case12) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{23, 2.77};
  std::pair<int, double> pair3{98, 3.9};

  S21::Map<int, double> s21_map_ref = {pair1, pair2, pair3};
  S21::Map<int, double> s21_map_res;
  s21_map_res = std::move(s21_map_ref);

  EXPECT_EQ(s21_map_ref.Size(), 0U);
  EXPECT_EQ(s21_map_res.Size(), 3U);
}

TEST(map_constructor, case13) {
  std::pair<double, std::string> pair1{1.4, "hello"};
  std::pair<double, std::string> pair2{2.77, "hi"};
  std::pair<double, std::string> pair3{3.9, "hola"};

  S21::Map<double, std::string> s21_map_ref = {pair1, pair2, pair3};

  S21::Map<double, std::string> s21_map_res;
  s21_map_res = std::move(s21_map_ref);

  EXPECT_EQ(s21_map_ref.Size(), 0U);
  EXPECT_EQ(s21_map_res.Size(), 3U);
}

TEST(map_constructor, case14) {
  std::pair<std::string, int> pair1{"hello", 1};
  std::pair<std::string, int> pair2{"hi", 2};
  std::pair<std::string, int> pair3{"hola", 3};

  S21::Map<std::string, int> s21_map_ref = {pair1, pair2, pair3};

  S21::Map<std::string, int> s21_map_res;
  s21_map_res = std::move(s21_map_ref);

  EXPECT_EQ(s21_map_ref.Size(), 0U);
  EXPECT_EQ(s21_map_res.Size(), 3U);
}

TEST(map_constructor, case15) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{23, 2.77};
  std::pair<int, double> pair3{98, 3.9};

  S21::Map<int, double> s21_map_ref_int{pair1, pair2, pair3};
  S21::Map<int, double> s21_map_res_int{s21_map_ref_int};

  std::pair<double, std::string> pair4{1.4, "hello"};
  std::pair<double, std::string> pair5{2.77, "hi"};
  std::pair<double, std::string> pair6{3.9, "hola"};

  S21::Map<double, std::string> s21_map_ref_double{pair4, pair5, pair6};
  S21::Map<double, std::string> s21_map_res_double{s21_map_ref_double};

  std::pair<std::string, int> pair7{"hello", 1};
  std::pair<std::string, int> pair8{"hi", 2};
  std::pair<std::string, int> pair9{"hola", 3};

  S21::Map<std::string, int> s21_map_ref_string{pair7, pair8, pair9};
  S21::Map<std::string, int> s21_map_res_string{s21_map_ref_string};

  auto it_res_int = s21_map_res_int.Begin();
  for (auto it_ref_int = s21_map_ref_int.Begin();
       it_ref_int != s21_map_ref_int.End(); ++it_ref_int) {
    EXPECT_EQ(it_res_int->first, it_ref_int->first);
    it_res_int++;
  }

  auto it_res_double = s21_map_res_double.Begin();
  for (auto it_ref_double = s21_map_ref_double.Begin();
       it_ref_double != s21_map_ref_double.End(); ++it_ref_double) {
    EXPECT_EQ(it_res_double->first, it_ref_double->first);
    it_res_double++;
  }

  auto it_res_string = s21_map_res_string.Begin();
  for (auto it_ref_string = s21_map_ref_string.Begin();
       it_ref_string != s21_map_ref_string.End(); ++it_ref_string) {
    EXPECT_EQ(it_res_string->first, it_ref_string->first);
    it_res_string++;
  }
}

TEST(map_insert, case1) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{9, 1.4};
  std::pair<int, double> pair3{9, 1.4};
  std::pair<int, double> pair4{23, 2.77};
  std::pair<int, double> pair5{98, 3.9};

  S21::Map<int, double> s21_map;

  std::pair<S21::Map<int, double>::iterator, bool> insert1 =
      s21_map.Insert(pair1);
  EXPECT_EQ(insert1.first->first, 9);
  EXPECT_EQ(insert1.second, 1);

  std::pair<S21::Map<int, double>::iterator, bool> insert2 =
      s21_map.Insert(pair2);
  std::pair<S21::Map<int, double>::iterator, bool> insert3 =
      s21_map.Insert(pair3);
  EXPECT_EQ(insert2.second, 0);
  EXPECT_EQ(insert3.second, 0);

  std::pair<S21::Map<int, double>::iterator, bool> insert4 =
      s21_map.Insert(pair4);
  EXPECT_EQ(insert4.first->first, 23);
  EXPECT_EQ(insert4.second, 1);

  std::pair<S21::Map<int, double>::iterator, bool> insert5 =
      s21_map.Insert(pair5);
  EXPECT_EQ(insert5.first->first, 98);
  EXPECT_EQ(insert5.second, 1);

  EXPECT_EQ(s21_map.Size(), 3U);
}

TEST(map_insert, case2) {
  std::pair<double, std::string> pair1{1.4, "hello"};
  std::pair<double, std::string> pair2{2.77, "hi"};
  std::pair<double, std::string> pair3{3.9, "hola"};
  std::pair<double, std::string> pair4{2.77, "hi"};
  std::pair<double, std::string> pair5{3.9, "hola"};

  S21::Map<double, std::string> s21_map;

  std::pair<S21::Map<double, std::string>::iterator, bool> insert1 =
      s21_map.Insert(pair1);
  EXPECT_EQ(insert1.first->first, 1.4);
  EXPECT_EQ(insert1.second, 1);

  std::pair<S21::Map<double, std::string>::iterator, bool> insert2 =
      s21_map.Insert(pair2);
  EXPECT_EQ(insert2.first->first, 2.77);
  EXPECT_EQ(insert2.second, 1);

  std::pair<S21::Map<double, std::string>::iterator, bool> insert3 =
      s21_map.Insert(pair3);
  EXPECT_EQ(insert3.first->first, 3.9);
  EXPECT_EQ(insert3.second, 1);

  std::pair<S21::Map<double, std::string>::iterator, bool> insert4 =
      s21_map.Insert(pair4);
  std::pair<S21::Map<double, std::string>::iterator, bool> insert5 =
      s21_map.Insert(pair5);
  EXPECT_EQ(insert4.second, 0);
  EXPECT_EQ(insert5.second, 0);

  EXPECT_EQ(s21_map.Size(), 3U);
}

TEST(map_insert, case3) {
  std::pair<std::string, int> pair1{"hello", 1};
  std::pair<std::string, int> pair2{"hi", 2};
  std::pair<std::string, int> pair3{"hi", 2};
  std::pair<std::string, int> pair4{"hola", 3};
  std::pair<std::string, int> pair5{"hello", 1};

  S21::Map<std::string, int> s21_map;

  std::pair<S21::Map<std::string, int>::iterator, bool> insert1 =
      s21_map.Insert(pair1);
  EXPECT_EQ(insert1.first->first, "hello");
  EXPECT_EQ(insert1.second, 1);

  std::pair<S21::Map<std::string, int>::iterator, bool> insert2 =
      s21_map.Insert(pair2);
  EXPECT_EQ(insert2.first->first, "hi");
  EXPECT_EQ(insert2.second, 1);

  std::pair<S21::Map<std::string, int>::iterator, bool> insert3 =
      s21_map.Insert(pair3);
  EXPECT_EQ(insert3.second, 0);

  std::pair<S21::Map<std::string, int>::iterator, bool> insert4 =
      s21_map.Insert(pair4);
  EXPECT_EQ(insert4.first->first, "hola");
  EXPECT_EQ(insert4.second, 1);

  std::pair<S21::Map<std::string, int>::iterator, bool> insert5 =
      s21_map.Insert(pair5);
  EXPECT_EQ(insert5.second, 0);

  EXPECT_EQ(s21_map.Size(), 3U);
}

TEST(map_insert, case4) {
  std::pair<int, double> pair1{9, 1.4};

  S21::Map<int, double> s21_map;

  std::pair<S21::Map<int, double>::iterator, bool> insert1 =
      s21_map.Insert(pair1);
  EXPECT_EQ(insert1.first->first, 9);
  EXPECT_EQ(insert1.second, 1);

  std::pair<S21::Map<int, double>::iterator, bool> insert2 =
      s21_map.Insert(pair1);
  std::pair<S21::Map<int, double>::iterator, bool> insert3 =
      s21_map.Insert(pair1);
  EXPECT_EQ(insert2.second, 0);
  EXPECT_EQ(insert3.second, 0);

  EXPECT_EQ(s21_map.Size(), 1U);
}

TEST(map_insert, case5) {
  std::pair<double, std::string> pair1{1.4, "hello"};

  S21::Map<double, std::string> s21_map = {pair1};

  std::pair<S21::Map<double, std::string>::iterator, bool> insert1 =
      s21_map.Insert(pair1);
  EXPECT_EQ(insert1.second, 0);

  EXPECT_EQ(s21_map.Size(), 1U);
}

TEST(map_insert, case6) {
  std::pair<std::string, int> pair1{"hello", 1};
  std::pair<std::string, int> pair2{"hi", 2};

  S21::Map<std::string, int> s21_map = {pair1};

  std::pair<S21::Map<std::string, int>::iterator, bool> insert1 =
      s21_map.Insert(pair2);
  EXPECT_EQ(insert1.first->first, "hi");
  EXPECT_EQ(insert1.second, 1);

  EXPECT_EQ(s21_map.Size(), 2U);
}

TEST(map_insert, case7) {
  S21::Map<int, double> s21_map;

  std::pair<S21::Map<int, double>::iterator, bool> insert1 =
      s21_map.Insert(9, 1.4);
  EXPECT_EQ(insert1.first->first, 9);
  EXPECT_EQ(insert1.second, 1);

  std::pair<S21::Map<int, double>::iterator, bool> insert2 =
      s21_map.Insert(9, 1.4);
  std::pair<S21::Map<int, double>::iterator, bool> insert3 =
      s21_map.Insert(9, 1.4);
  EXPECT_EQ(insert2.second, 0);
  EXPECT_EQ(insert3.second, 0);

  std::pair<S21::Map<int, double>::iterator, bool> insert4 =
      s21_map.Insert(23, 2.77);
  EXPECT_EQ(insert4.first->first, 23);
  EXPECT_EQ(insert4.second, 1);

  std::pair<S21::Map<int, double>::iterator, bool> insert5 =
      s21_map.Insert(98, 3.9);
  EXPECT_EQ(insert5.first->first, 98);
  EXPECT_EQ(insert5.second, 1);

  EXPECT_EQ(s21_map.Size(), 3U);
}

TEST(map_insert, case8) {
  S21::Map<double, std::string> s21_map;

  std::pair<S21::Map<double, std::string>::iterator, bool> insert1 =
      s21_map.Insert(1.4, "hello");
  EXPECT_EQ(insert1.first->first, 1.4);
  EXPECT_EQ(insert1.second, 1);

  std::pair<S21::Map<double, std::string>::iterator, bool> insert2 =
      s21_map.Insert(2.77, "hi");
  EXPECT_EQ(insert2.first->first, 2.77);
  EXPECT_EQ(insert2.second, 1);

  std::pair<S21::Map<double, std::string>::iterator, bool> insert3 =
      s21_map.Insert(3.9, "hola");
  EXPECT_EQ(insert3.first->first, 3.9);
  EXPECT_EQ(insert3.second, 1);

  std::pair<S21::Map<double, std::string>::iterator, bool> insert4 =
      s21_map.Insert(2.77, "hi");
  std::pair<S21::Map<double, std::string>::iterator, bool> insert5 =
      s21_map.Insert(3.9, "hola");
  EXPECT_EQ(insert4.second, 0);
  EXPECT_EQ(insert5.second, 0);

  EXPECT_EQ(s21_map.Size(), 3U);
}

TEST(map_insert, case9) {
  S21::Map<std::string, int> s21_map;

  std::pair<S21::Map<std::string, int>::iterator, bool> insert1 =
      s21_map.Insert("hello", 1);
  EXPECT_EQ(insert1.first->first, "hello");
  EXPECT_EQ(insert1.second, 1);

  std::pair<S21::Map<std::string, int>::iterator, bool> insert2 =
      s21_map.Insert("hi", 2);
  EXPECT_EQ(insert2.first->first, "hi");
  EXPECT_EQ(insert2.second, 1);

  std::pair<S21::Map<std::string, int>::iterator, bool> insert3 =
      s21_map.Insert("hi", 2);
  EXPECT_EQ(insert3.second, 0);

  std::pair<S21::Map<std::string, int>::iterator, bool> insert4 =
      s21_map.Insert("hola", 3);
  EXPECT_EQ(insert4.first->first, "hola");
  EXPECT_EQ(insert4.second, 1);

  std::pair<S21::Map<std::string, int>::iterator, bool> insert5 =
      s21_map.Insert("hello", 1);
  EXPECT_EQ(insert5.second, 0);

  EXPECT_EQ(s21_map.Size(), 3U);
}

TEST(map_insert, case10) {
  S21::Map<int, double> s21_map;

  std::pair<S21::Map<int, double>::iterator, bool> insert1 =
      s21_map.Insert(9, 1.4);
  EXPECT_EQ(insert1.first->first, 9);
  EXPECT_EQ(insert1.second, 1);

  std::pair<S21::Map<int, double>::iterator, bool> insert2 =
      s21_map.Insert(9, 1.4);
  std::pair<S21::Map<int, double>::iterator, bool> insert3 =
      s21_map.Insert(9, 1.4);
  EXPECT_EQ(insert2.second, 0);
  EXPECT_EQ(insert3.second, 0);

  EXPECT_EQ(s21_map.Size(), 1U);
}

TEST(map_insert, case11) {
  std::pair<double, std::string> pair1{1.4, "hello"};

  S21::Map<double, std::string> s21_map = {pair1};

  std::pair<S21::Map<double, std::string>::iterator, bool> insert1 =
      s21_map.Insert(1.4, "hello");
  EXPECT_EQ(insert1.second, 0);

  EXPECT_EQ(s21_map.Size(), 1U);
}

TEST(map_insert, case12) {
  std::pair<std::string, int> pair1{"hello", 1};

  S21::Map<std::string, int> s21_map = {pair1};

  std::pair<S21::Map<std::string, int>::iterator, bool> insert1 =
      s21_map.Insert("hi", 2);
  EXPECT_EQ(insert1.first->first, "hi");
  EXPECT_EQ(insert1.second, 1);

  EXPECT_EQ(s21_map.Size(), 2U);
}

TEST(map_begin, case1) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{15, 1.456};
  std::pair<int, double> pair3{7, 151.4};
  std::pair<int, double> pair4{23, 2.77};
  std::pair<int, double> pair5{2, 3.9};

  S21::Map<int, double> s21_map = {pair1, pair2, pair3, pair4, pair5};

  auto min_value = s21_map.Begin();

  EXPECT_EQ(min_value->first, 2);
}

TEST(map_begin, case2) {
  std::pair<double, std::string> pair1{11.4, "hello"};
  std::pair<double, std::string> pair2{2.770001, "hee"};
  std::pair<double, std::string> pair3{3.901, "hola"};
  std::pair<double, std::string> pair4{2.77, "hi"};
  std::pair<double, std::string> pair5{3.9, "hee-hee"};

  S21::Map<double, std::string> s21_map = {pair1, pair2, pair3, pair4, pair5};

  auto min_value = s21_map.Begin();

  EXPECT_EQ(min_value->first, 2.77);
}

TEST(map_begin, case3) {
  std::pair<std::string, int> pair1{"hello", 1};
  std::pair<std::string, int> pair2{"hi", 2};
  std::pair<std::string, int> pair3{"hi-hi", 2};
  std::pair<std::string, int> pair4{"hola", 3};
  std::pair<std::string, int> pair5{"hello, there", 1};

  S21::Map<std::string, int> s21_map = {pair1, pair2, pair3, pair4, pair5};

  auto min_value = s21_map.Begin();

  EXPECT_EQ(min_value->first, "hello");
}

TEST(map_begin, case4) {
  S21::Map<int, double> s21_map;

  EXPECT_THROW(s21_map.Begin(), std::out_of_range);
}

TEST(map_begin, case5) {
  std::pair<double, std::string> pair1{1.4, "hello"};

  S21::Map<double, std::string> s21_map = {pair1, pair1};

  auto min_value = s21_map.Begin();

  EXPECT_EQ(min_value->first, 1.4);
  EXPECT_EQ(min_value->second, "hello");
}

TEST(map_begin, case6) {
  std::pair<std::string, int> pair1{"hello", 1};
  std::pair<std::string, int> pair2{"hello", 2};
  std::pair<std::string, int> pair3{"hello", 45};

  S21::Map<std::string, int> s21_map = {pair1, pair2, pair3};

  auto min_value = s21_map.Begin();

  EXPECT_EQ(min_value->first, "hello");
  EXPECT_EQ(min_value->second, 1);
}

TEST(map_end, case1) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{15, 1.456};
  std::pair<int, double> pair3{7, 151.4};
  std::pair<int, double> pair4{23, 2.77};
  std::pair<int, double> pair5{2, 3.9};

  S21::Map<int, double> s21_map = {pair1, pair2, pair3, pair4, pair5};

  auto max_value = s21_map.End();

  EXPECT_EQ(max_value->first, 23);
}

TEST(map_end, case2) {
  std::pair<double, std::string> pair1{11.4, "hello"};
  std::pair<double, std::string> pair2{2.770001, "hee"};
  std::pair<double, std::string> pair3{3.901, "hola"};
  std::pair<double, std::string> pair4{11.400000001, "hi"};
  std::pair<double, std::string> pair5{3.9, "hee-hee"};

  S21::Map<double, std::string> s21_map = {pair1, pair2, pair3, pair4, pair5};

  auto max_value = s21_map.End();

  EXPECT_EQ(max_value->first, 11.400000001);
}

TEST(map_end, case3) {
  std::pair<std::string, int> pair1{"hello", 1};
  std::pair<std::string, int> pair2{"hi", 2};
  std::pair<std::string, int> pair3{"hola-hola", 2};
  std::pair<std::string, int> pair4{"hola", 3};
  std::pair<std::string, int> pair5{"hello, there", 1};

  S21::Map<std::string, int> s21_map = {pair1, pair2, pair3, pair4, pair5};

  auto max_value = s21_map.End();

  EXPECT_EQ(max_value->first, "hola-hola");
}

TEST(map_end, case4) {
  S21::Map<int, double> s21_map;

  EXPECT_THROW(s21_map.End(), std::out_of_range);
}

TEST(map_end, case5) {
  std::pair<double, std::string> pair1{1.4, "hello"};

  S21::Map<double, std::string> s21_map = {pair1, pair1};

  auto max_value = s21_map.End();

  EXPECT_EQ(max_value->first, 1.4);
  EXPECT_EQ(max_value->second, "hello");
}

TEST(map_end, case6) {
  std::pair<std::string, int> pair1{"hello", 1};
  std::pair<std::string, int> pair2{"hello", 2};
  std::pair<std::string, int> pair3{"hello", 45};

  S21::Map<std::string, int> s21_map = {pair1, pair2, pair3};

  auto max_value = s21_map.End();

  EXPECT_EQ(max_value->first, "hello");
  EXPECT_EQ(max_value->second, 1);
}

TEST(map_balance, case1) {
  std::pair<int, double> pair1{1, 1.4};
  std::pair<int, double> pair2{15, 1.456};
  std::pair<int, double> pair3{5, 151.4};

  S21::Map<int, double> s21_map = {pair1, pair2, pair3};

  auto max_value = s21_map.End();

  EXPECT_EQ(max_value->first, 15);
  EXPECT_EQ(s21_map.Size(), 3U);
}

TEST(map_balance, case2) {
  std::pair<double, std::string> pair1{11.4, "hello"};
  std::pair<double, std::string> pair2{2.770001, "hi"};
  std::pair<double, std::string> pair3{3.901, "hola"};

  S21::Map<double, std::string> s21_map = {pair1, pair2, pair3};

  auto min_value = s21_map.End();

  EXPECT_EQ(min_value->first, 11.4);
  EXPECT_EQ(s21_map.Size(), 3U);
}

TEST(map_balance, case3) {
  std::pair<std::string, int> pair1{"hello", 1};
  std::pair<std::string, int> pair2{"hi", 2};
  std::pair<std::string, int> pair3{"hola-hola", 2};
  std::pair<std::string, int> pair4{"hola", 3};
  std::pair<std::string, int> pair5{"hello, there", 1};

  S21::Map<std::string, int> s21_map = {pair1, pair2, pair3, pair4, pair5};

  auto min_value = s21_map.End();

  EXPECT_EQ(min_value->first, "hola-hola");
  EXPECT_EQ(s21_map.Size(), 5U);
}

TEST(map_balance, case4) {
  std::pair<int, int> pair1{10, 10};
  std::pair<int, int> pair2{5, 5};
  std::pair<int, int> pair3{20, 20};
  std::pair<int, int> pair4{30, 30};
  std::pair<int, int> pair5{1543, 1543};

  S21::Map<int, int> s21_map = {pair1, pair2, pair3, pair4, pair5};

  EXPECT_EQ(s21_map.End()->first, 1543);
  EXPECT_EQ(s21_map.Begin()->first, 5);
  EXPECT_EQ(s21_map.Size(), 5U);
}

TEST(map_balance, case5) {
  std::pair<int, int> pair1{30, 30};
  std::pair<int, int> pair2{5, 5};
  std::pair<int, int> pair3{43, 43};
  std::pair<int, int> pair4{1, 1};
  std::pair<int, int> pair5{20, 20};
  std::pair<int, int> pair6{40, 60};
  std::pair<int, int> pair7{60, 60};
  std::pair<int, int> pair8{35, 35};
  std::pair<int, int> pair9{32, 32};

  S21::Map<int, int> s21_map = {pair1, pair2, pair3, pair4, pair5,
                                pair6, pair7, pair8, pair9};

  EXPECT_EQ(s21_map.End()->first, 60);
  EXPECT_EQ(s21_map.Begin()->first, 1);
  EXPECT_EQ(s21_map.Size(), 9U);
}

TEST(map_erase, case1) {
  std::pair<int, int> pair1{10, 10};
  std::pair<int, int> pair2{5, 5};
  std::pair<int, int> pair3{15, 15};
  std::pair<int, int> pair4{4, 4};
  std::pair<int, int> pair5{18, 18};
  std::pair<int, int> pair6{13, 13};
  std::pair<int, int> pair7{16, 16};

  S21::Map<int, int> s21_map = {pair1, pair2, pair3, pair4,
                                pair5, pair6, pair7};

  auto it = s21_map.Begin();
  it++;
  it++;
  it++;
  it++;
  s21_map.Erase(it);
  EXPECT_EQ(s21_map.Begin()->first, 4);
  EXPECT_EQ(s21_map.End()->first, 18);
  EXPECT_EQ(s21_map.Size(), 6U);

  it = s21_map.Begin();
  s21_map.Erase(it);
  EXPECT_EQ(s21_map.Begin()->first, 5);
  EXPECT_EQ(s21_map.End()->first, 18);
  EXPECT_EQ(s21_map.Size(), 5U);

  it = s21_map.Begin();
  it++;
  s21_map.Erase(it);
  EXPECT_EQ(s21_map.Begin()->first, 5);
  EXPECT_EQ(s21_map.End()->first, 18);
  EXPECT_EQ(s21_map.Size(), 4U);

  it = s21_map.End();
  s21_map.Erase(it);
  EXPECT_EQ(s21_map.Begin()->first, 5);
  EXPECT_EQ(s21_map.End()->first, 16);
  EXPECT_EQ(s21_map.Size(), 3U);

  it = s21_map.Begin();
  it++;
  s21_map.Erase(it);

  it = s21_map.Begin();
  it++;
  s21_map.Erase(it);

  it = s21_map.Begin();
  s21_map.Erase(it);

  EXPECT_EQ(s21_map.Size(), 0U);
}

TEST(map_erase, case2) {
  std::pair<int, int> pair1{30, 30};
  std::pair<int, int> pair2{1543, 1543};

  S21::Map<int, int> s21_map = {pair1, pair2};

  auto it = s21_map.Begin();
  it += 1;
  s21_map.Erase(it);
  it = s21_map.Begin();
  s21_map.Erase(it);

  EXPECT_EQ(s21_map.Size(), 0U);
}

TEST(map_erase, case3) {
  std::pair<std::string, int> pair1{"hello", 1};
  std::pair<std::string, int> pair2{"hi", 2};
  std::pair<std::string, int> pair3{"hola-hola", 2};
  std::pair<std::string, int> pair4{"hola", 3};
  std::pair<std::string, int> pair5{"hello, there", 1};

  S21::Map<std::string, int> s21_map = {pair1, pair2, pair3, pair4, pair5};

  auto it = s21_map.End();
  s21_map.Erase(it);
  EXPECT_EQ(s21_map.End()->first, "hola");
  EXPECT_EQ(s21_map.Size(), 4U);

  it = s21_map.End();
  s21_map.Erase(it);
  EXPECT_EQ(s21_map.End()->first, "hi");
  EXPECT_EQ(s21_map.Size(), 3U);

  s21_map.Insert(pair3);
  s21_map.Insert(pair4);
  it = s21_map.End();
  s21_map.Erase(it);
  EXPECT_EQ(s21_map.End()->first, "hola");
  EXPECT_EQ(s21_map.Size(), 4U);
}

TEST(map_erase, case4) {
  std::pair<double, int> pair1{22.2, 1};
  std::pair<double, int> pair2{12.4457, 2};
  std::pair<double, int> pair3{56.84, 2};
  std::pair<double, int> pair4{941.44, 3};
  std::pair<double, int> pair5{44.48, 1};

  S21::Map<double, int> s21_map = {pair1, pair2, pair3, pair4, pair5};

  auto it = s21_map.End();
  it--;
  s21_map.Erase(it);
  it = s21_map.End();
  EXPECT_EQ(it->first, 941.44);
  EXPECT_EQ(s21_map.Size(), 4U);

  it = s21_map.Begin();
  ++it;
  ++it;
  ++it;
  s21_map.Erase(it);
  it = s21_map.Begin();
  ++it;
  ++it;
  ++it;
  EXPECT_EQ(s21_map.End()->first, 44.48);
  EXPECT_EQ(s21_map.Size(), 3U);
}

TEST(map_erase, case5) {
  std::pair<double, int> pair1{22.2, 1};
  std::pair<double, int> pair2{44.48, 1};
  std::pair<double, int> pair3{12.4457, 2};
  std::pair<double, int> pair4{1.44, 3};

  S21::Map<double, int> s21_map = {pair1, pair2, pair3, pair4};

  auto it = s21_map.Begin();
  it -= 1;
  s21_map.Erase(it);
  it = s21_map.Begin();
  ++it;
  ++it;
  EXPECT_EQ(it->first, 44.48);
  EXPECT_EQ(s21_map.Size(), 3U);
}

TEST(map_erase, case6) {
  std::pair<double, int> pair1{22.2, 1};
  std::pair<double, int> pair2{44.48, 1};
  std::pair<double, int> pair3{12.4457, 2};
  std::pair<double, int> pair4{6.84, 2};
  std::pair<double, int> pair5{1.44, 3};

  S21::Map<double, int> s21_map = {pair1, pair2, pair3, pair4, pair5};

  auto it = s21_map.Begin();
  ++it;
  ++it;
  ++it;
  s21_map.Erase(it);
  it = s21_map.Begin();
  it += 3;
  EXPECT_EQ(it->first, 44.48);
  EXPECT_EQ(s21_map.Size(), 4U);
}

TEST(map_erase, case7) {
  std::pair<double, int> pair1{22.2, 1};
  std::pair<double, int> pair2{12.4457, 2};
  std::pair<double, int> pair3{56.84, 2};
  std::pair<double, int> pair4{941.44, 3};
  std::pair<double, int> pair5{44.48, 1};

  S21::Map<double, int> s21_map = {pair1, pair2, pair3, pair4, pair5};

  auto it = s21_map.Begin();
  ++it;
  s21_map.Erase(it);
  it = s21_map.Begin();
  ++it;
  EXPECT_EQ(it->first, 44.48);
  EXPECT_EQ(s21_map.Size(), 4U);
}

TEST(map_erase, case8) {
  std::pair<double, int> pair1{22.2, 1};
  std::pair<double, int> pair2{44.48, 1};
  std::pair<double, int> pair3{12.4457, 2};
  std::pair<double, int> pair4{1.44, 3};

  S21::Map<double, int> s21_map = {pair1, pair2, pair3, pair4};

  auto it = s21_map.Begin();
  ++it;
  s21_map.Erase(it);
  it = s21_map.Begin();
  ++it;
  EXPECT_EQ(it->first, 22.2);
  EXPECT_EQ(s21_map.Size(), 3U);
}

TEST(map_erase, case9) {
  std::pair<double, int> pair1{22.2, 1};
  std::pair<double, int> pair2{44.48, 1};
  std::pair<double, int> pair3{12.4457, 2};
  std::pair<double, int> pair4{32.45, 2};
  std::pair<double, int> pair5{65.12, 3};
  std::pair<double, int> pair6{66.32, 3};
  std::pair<double, int> pair7{40.54, 3};
  std::pair<double, int> pair8{6.4, 3};

  S21::Map<double, int> s21_map = {pair1, pair2, pair3, pair4,
                                   pair5, pair6, pair7, pair8};

  auto it = s21_map.End();
  it -= 4;
  s21_map.Erase(it);
  it = s21_map.Begin();
  ++it;
  ++it;
  ++it;
  EXPECT_EQ(it->first, 40.54);
  EXPECT_EQ(s21_map.Size(), 7U);
}

TEST(map_erase, case10) {
  std::pair<double, int> pair1{22.2, 1};

  S21::Map<double, int> s21_map = {pair1};

  auto it = s21_map.End();
  it -= 1;
  ++it;
  s21_map.Erase(it);
  EXPECT_EQ(s21_map.Size(), 0U);
}

TEST(map_empty, case1) {
  std::pair<double, int> pair1{22.2, 1};
  std::pair<double, int> pair2{44.48, 1};
  std::pair<double, int> pair3{12.4457, 2};
  std::pair<double, int> pair4{1.44, 3};

  S21::Map<double, int> s21_map = {pair1, pair2, pair3, pair4};

  EXPECT_EQ(s21_map.Empty(), 0);
}

TEST(map_empty, case2) {
  S21::Map<double, int> s21_map;

  EXPECT_EQ(s21_map.Empty(), 1);
}

// FAIL
// TEST(map_MaxSize, case1) {
//  std::pair<double, int> pair1{22.2, 1};
//
//  S21::Map<double, int> s21_map{pair1};
//  std::map<double, int> std_map{pair1};
//
//  EXPECT_EQ(s21_map.MaxSize(), std_map.max_size());
//}
//
// TEST(map_MaxSize, case2) {
//  S21::Map<double, int> s21_map;
//  std::map<double, int> std_map;
//
//  EXPECT_EQ(s21_map.MaxSize(), std_map.max_size());
//}

TEST(map_swap, case1) {
  std::pair<double, int> pair1{22.2, 1};
  std::pair<double, int> pair2{44.48, 1};
  std::pair<double, int> pair3{12.4457, 2};
  std::pair<double, int> pair4{1.44, 3};
  std::pair<double, int> pair5{22.2, 15};

  S21::Map<double, int> s21_map_ref = {pair1, pair2};
  S21::Map<double, int> s21_map_res = {pair3, pair4, pair5};

  s21_map_ref.Swap(s21_map_res);

  EXPECT_EQ(s21_map_ref.Size(), 3U);
  EXPECT_EQ(s21_map_ref.Begin()->first, 1.44);

  EXPECT_EQ(s21_map_res.Size(), 2U);
  EXPECT_EQ(s21_map_res.Begin()->first, 22.2);
}

TEST(map_swap, case2) {
  std::pair<double, int> pair1{22.2, 1};
  std::pair<double, int> pair2{44.48, 1};

  S21::Map<double, int> s21_map_ref = {pair1, pair2};
  S21::Map<double, int> s21_map_res;

  s21_map_ref.Swap(s21_map_res);

  EXPECT_EQ(s21_map_ref.Size(), 0U);

  EXPECT_EQ(s21_map_res.Size(), 2U);
  EXPECT_EQ(s21_map_res.Begin()->first, 22.2);
}

TEST(map_swap, case3) {
  std::pair<double, int> pair1{12.4457, 2};
  std::pair<double, int> pair2{1.44, 3};
  std::pair<double, int> pair3{22.2, 15};

  S21::Map<double, int> s21_map_ref;
  S21::Map<double, int> s21_map_res = {pair1, pair2, pair3};

  s21_map_ref.Swap(s21_map_res);

  EXPECT_EQ(s21_map_ref.Size(), 3U);
  EXPECT_EQ(s21_map_ref.Begin()->first, 1.44);

  EXPECT_EQ(s21_map_res.Size(), 0U);
}

TEST(map_swap, case4) {
  S21::Map<double, int> s21_map_ref;
  S21::Map<double, int> s21_map_res;

  s21_map_ref.Swap(s21_map_res);

  EXPECT_EQ(s21_map_ref.Size(), 0U);
  EXPECT_EQ(s21_map_res.Size(), 0U);
}

TEST(map_contains, case1) {
  std::pair<double, int> pair1{22.2, 1};
  std::pair<double, int> pair2{44.48, 1};

  S21::Map<double, int> s21_map = {pair1, pair2};

  EXPECT_EQ(s21_map.Contains(22.2), true);
  EXPECT_EQ(s21_map.Contains(44.48), true);
}

TEST(map_contains, case2) {
  std::pair<double, int> pair1{22.2, 1};
  std::pair<double, int> pair2{44.48, 1};

  S21::Map<double, int> s21_map_ref = {pair1, pair2};
  S21::Map<double, int> s21_map_res;

  s21_map_ref.Swap(s21_map_res);

  EXPECT_EQ(s21_map_ref.Size(), 0U);
  EXPECT_EQ(s21_map_ref.Contains(22.2), false);
  EXPECT_EQ(s21_map_ref.Contains(44.48), false);

  EXPECT_EQ(s21_map_res.Size(), 2U);
  EXPECT_EQ(s21_map_res.Contains(22.2), true);
  EXPECT_EQ(s21_map_res.Contains(44.48), true);
}

TEST(map_contains, case3) {
  std::pair<double, int> pair1{12.4457, 2};
  std::pair<double, int> pair2{1.44, 3};
  std::pair<double, int> pair3{22.2, 15};

  S21::Map<double, int> s21_map_ref;
  S21::Map<double, int> s21_map_res = {pair1, pair2, pair3};

  s21_map_ref.Swap(s21_map_res);

  EXPECT_EQ(s21_map_ref.Size(), 3U);
  EXPECT_EQ(s21_map_ref.Contains(12.4457), true);
  EXPECT_EQ(s21_map_ref.Contains(1.44), true);
  EXPECT_EQ(s21_map_ref.Contains(22.2), true);

  EXPECT_EQ(s21_map_res.Size(), 0U);
  EXPECT_EQ(s21_map_res.Contains(12.4457), false);
  EXPECT_EQ(s21_map_res.Contains(1.44), false);
  EXPECT_EQ(s21_map_res.Contains(22.2), false);
}

TEST(map_contains, case4) {
  S21::Map<double, int> s21_map;

  EXPECT_EQ(s21_map.Size(), 0U);
  EXPECT_EQ(s21_map.Contains(12.4457), false);
}

// !!!!!!!
// emplace1[0].first->first, 98 ВЫВОДИТ 23

// TEST(map_emplace, case1) {
//   std::pair<int, double> pair1{9, 1.4};
//   std::pair<int, double> pair2{9, 1.4};
//   std::pair<int, double> pair3{9, 1.4};
//   std::pair<int, double> pair4{23, 2.77};
//   std::pair<int, double> pair5{98, 3.9};
//
//   S21::Map<int, double> s21_map;
//
//   std::vector<std::pair<S21::Map<int, double>::iterator, bool>> emplace1 =
//       s21_map.Emplace(pair1, pair2, pair3, pair4, pair5);
//
//   EXPECT_EQ(emplace1[0].first->first, 98);
//   EXPECT_EQ(emplace1[0].second, true);
//   EXPECT_EQ(s21_map.Size(), 3U);
// }
//
// TEST(map_emplace, case2) {
//   std::pair<double, std::string> pair1{1.4, "hello"};
//   std::pair<double, std::string> pair2{2.77, "hi"};
//   std::pair<double, std::string> pair3{3.9, "hola"};
//   std::pair<double, std::string> pair4{2.77, "hi"};
//   std::pair<double, std::string> pair5{3.9, "hola"};
//
//   S21::Map<double, std::string> s21_map;
//
//   std::vector<std::pair<S21::Map<std::string, int>::iterator, bool>> emplace1
//   =
//       s21_map.Emplace(pair1, pair2, pair3, pair4, pair5);
//
//   EXPECT_EQ(emplace1.second, false);
//   EXPECT_EQ(s21_map.Size(), 3U);
// }
//
// TEST(map_emplace, case3) {
//   std::pair<std::string, int> pair1{"hello", 1};
//   std::pair<std::string, int> pair2{"hi", 2};
//   std::pair<std::string, int> pair3{"hi", 2};
//   std::pair<std::string, int> pair4{"hola", 3};
//   std::pair<std::string, int> pair5{"hello", 1};
//
//   S21::Map<std::string, int> s21_map;
//
//   std::vector<std::pair<S21::Map<std::string, int>::iterator, bool>> emplace1
//   =
//       s21_map.Emplace(pair1, pair2, pair3, pair4, pair5);
//
//   EXPECT_EQ(emplace1.second, false);
//   EXPECT_EQ(s21_map.Size(), 3U);
// }
//
// TEST(map_emplace, case4) {
//   std::pair<int, double> pair1{9, 1.4};
//
//   S21::Map<int, double> s21_map;
//
//   std::vector<std::pair<S21::Map<std::string, int>::iterator, bool>> emplace1
//   =
//       s21_map.Emplace(pair1);
//
//   EXPECT_EQ(emplace1.first->first, 9);
//   EXPECT_EQ(emplace1.second, true);
//   EXPECT_EQ(s21_map.Size(), 1U);
// }
//
// TEST(map_emplace, case5) {
//   std::pair<double, std::string> pair1{1.4, "hello"};
//
//   S21::Map<double, std::string> s21_map = {pair1};
//
//   std::vector<std::pair<S21::Map<std::string, int>::iterator, bool>> emplace1
//   =
//       s21_map.Emplace(pair1);
//
//   EXPECT_EQ(emplace1.second, false);
//   EXPECT_EQ(s21_map.Size(), 1U);
// }
//
// TEST(map_emplace, case6) {
//   std::pair<std::string, int> pair1{"hello", 1};
//   std::pair<std::string, int> pair2{"hi", 2};
//
//   S21::Map<std::string, int> s21_map = {pair1};
//
//   std::vector<std::pair<S21::Map<std::string, int>::iterator, bool>> emplace1
//   =
//       s21_map.Emplace(pair2);
//
//   EXPECT_EQ(emplace1.first->first, "hi");
//   EXPECT_EQ(emplace1.second, true);
//   EXPECT_EQ(s21_map.Size(), 2U);
// }

TEST(map_at, case1) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{23, 2.77};
  std::pair<int, double> pair3{98, 3.9};
  std::pair<int, double> pair11{78, 3.9};
  std::pair<int, double> pair22{88, 3.9};
  std::pair<int, double> pair33{108, 3.9};

  S21::Map<int, double> s21_map_int{pair1,  pair2,  pair3,
                                    pair11, pair22, pair33};
  EXPECT_EQ(s21_map_int.At(9), 1.4);
  EXPECT_EQ(s21_map_int.At(23), 2.77);
  EXPECT_EQ(s21_map_int.At(98), 3.9);
  EXPECT_EQ(s21_map_int.At(78), 3.9);
  EXPECT_EQ(s21_map_int.At(88), 3.9);
  EXPECT_EQ(s21_map_int.At(108), 3.9);

  std::pair<double, std::string> pair4{1.4, "hello"};
  std::pair<double, std::string> pair5{2.77, "hi"};
  std::pair<double, std::string> pair6{3.9, "hola"};

  S21::Map<double, std::string> s21_map_double{pair4, pair5, pair6};
  EXPECT_EQ(s21_map_double.At(1.4), "hello");
  EXPECT_EQ(s21_map_double.At(2.77), "hi");
  EXPECT_EQ(s21_map_double.At(3.9), "hola");

  std::pair<std::string, int> pair7{"hello", 1};
  std::pair<std::string, int> pair8{"hi", 2};
  std::pair<std::string, int> pair9{"hola", 3};

  S21::Map<std::string, int> s21_map_string{pair7, pair8, pair9};
  EXPECT_EQ(s21_map_string.At("hello"), 1);
  EXPECT_EQ(s21_map_string.At("hi"), 2);
  EXPECT_EQ(s21_map_string.At("hola"), 3);
}

TEST(map_brackets, case1) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{23, 2.77};
  std::pair<int, double> pair3{98, 3.9};
  std::pair<int, double> pair11{78, 3.9};
  std::pair<int, double> pair22{88, 3.9};
  std::pair<int, double> pair33{108, 3.9};

  S21::Map<int, double> s21_map_int{pair1,  pair2,  pair3,
                                    pair11, pair22, pair33};
  EXPECT_EQ(s21_map_int[9], 1.4);
  EXPECT_EQ(s21_map_int[23], 2.77);
  EXPECT_EQ(s21_map_int[98], 3.9);
  EXPECT_EQ(s21_map_int[78], 3.9);
  EXPECT_EQ(s21_map_int[88], 3.9);
  EXPECT_EQ(s21_map_int[108], 3.9);

  std::pair<double, std::string> pair4{1.4, "hello"};
  std::pair<double, std::string> pair5{2.77, "hi"};
  std::pair<double, std::string> pair6{3.9, "hola"};

  S21::Map<double, std::string> s21_map_double{pair4, pair5, pair6};
  EXPECT_EQ(s21_map_double[1.4], "hello");
  EXPECT_EQ(s21_map_double[2.77], "hi");
  EXPECT_EQ(s21_map_double[3.9], "hola");

  std::pair<std::string, int> pair7{"hello", 1};
  std::pair<std::string, int> pair8{"hi", 2};
  std::pair<std::string, int> pair9{"hola", 3};

  S21::Map<std::string, int> s21_map_string{pair7, pair8, pair9};
  EXPECT_EQ(s21_map_string["hello"], 1);
  EXPECT_EQ(s21_map_string["hi"], 2);
  EXPECT_EQ(s21_map_string["hola"], 3);
}

TEST(map_brackets, case2) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{23, 2.77};
  std::pair<int, double> pair3{8, 3.9};

  S21::Map<int, double> s21_map_int = {pair1, pair2, pair3};
  s21_map_int[78] = 78.0;
  s21_map_int[88] = 88.0;
  s21_map_int[108] = 108.0;

  EXPECT_EQ(s21_map_int[9], 1.4);
  EXPECT_EQ(s21_map_int[23], 2.77);
  EXPECT_EQ(s21_map_int[8], 3.9);
  EXPECT_EQ(s21_map_int[78], 78.0);
  EXPECT_EQ(s21_map_int[88], 88.0);
  EXPECT_EQ(s21_map_int[108], 108.0);

  std::pair<double, std::string> pair4{1.4, "hello"};
  std::pair<double, std::string> pair5{2.77, "hi"};
  std::pair<double, std::string> pair6{3.9, "hola"};

  S21::Map<double, std::string> s21_map_double{pair4, pair5};
  s21_map_double[3.9] = "hola";

  EXPECT_EQ(s21_map_double[1.4], "hello");
  EXPECT_EQ(s21_map_double[2.77], "hi");
  EXPECT_EQ(s21_map_double[3.9], "hola");

  std::pair<std::string, int> pair7{"hello", 1};
  std::pair<std::string, int> pair8{"hi", 2};
  std::pair<std::string, int> pair9{"hola", 3};

  S21::Map<std::string, int> s21_map_string{pair7};
  s21_map_string["hi"] = 2;
  s21_map_string["hola"] = 3;

  EXPECT_EQ(s21_map_string["hello"], 1);
  EXPECT_EQ(s21_map_string["hi"], 2);
  EXPECT_EQ(s21_map_string["hola"], 3);
}

TEST(map_merge, case1) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{23, 2.77};
  std::pair<int, double> pair3{98, 3.9};
  std::pair<int, double> pair11{78, 4.59};
  std::pair<int, double> pair22{88, 12.902};
  std::pair<int, double> pair33{108, 56.41};

  S21::Map<int, double> s21_map_int_ref{pair1, pair2, pair3};
  S21::Map<int, double> s21_map_int_res{pair11, pair22, pair33};

  s21_map_int_res.Merge(s21_map_int_ref);

  EXPECT_EQ(s21_map_int_res.Size(), 6U);
}

TEST(map_merge, case2) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{23, 2.77};
  std::pair<int, double> pair3{98, 3.9};

  S21::Map<int, double> s21_map_int_ref{pair1, pair2, pair3};
  S21::Map<int, double> s21_map_int_res;

  s21_map_int_res.Merge(s21_map_int_ref);

  EXPECT_EQ(s21_map_int_res.Size(), 3U);
}

TEST(map_merge, case3) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{23, 2.77};
  std::pair<int, double> pair3{98, 3.9};

  S21::Map<int, double> s21_map_int_ref;
  S21::Map<int, double> s21_map_int_res{pair1, pair2, pair3};

  EXPECT_EQ(s21_map_int_res.Size(), 3U);
}

TEST(map_merge, case4) {
  std::pair<int, double> pair1{9, 1.4};
  std::pair<int, double> pair2{23, 2.77};
  std::pair<int, double> pair3{98, 3.9};
  std::pair<int, double> pair4{1, 22.2};
  std::pair<int, double> pair5{8, 44.48};
  std::pair<int, double> pair6{32, 12.4457};

  S21::Map<int, double> s21_map_int_ref = {pair1, pair2, pair3, pair4};
  S21::Map<int, double> s21_map_int_res = {pair5, pair6};

  s21_map_int_res.Merge(s21_map_int_ref);

  EXPECT_EQ(s21_map_int_res.Size(), 6U);
}
