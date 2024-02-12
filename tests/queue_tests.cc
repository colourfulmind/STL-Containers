#include <gtest/gtest.h>

#include <queue>

#include "../queue/s21_queue.h"

template <typename value_type>
bool CheckEq(S21::Queue<value_type> m_queue,
             std::queue<value_type> orig_queue) {
  bool result = true;
  if (m_queue.Size() == orig_queue.size()) {
    while (!m_queue.Empty() && !orig_queue.empty()) {
      if (m_queue.Front() != orig_queue.front()) {
        result = false;
        break;
      }
      m_queue.Pop();
      orig_queue.pop();
    }
  } else {
    result = false;
  }
  return result;
}

TEST(Queue_test, construct_def_empty) {
  S21::Queue<int> lol_my;
  EXPECT_THROW(lol_my.Back(), std::logic_error);

  S21::Queue<int> lol_my1;
  lol_my1.Push(1);
  lol_my1.Push(2);
  lol_my1.Push(3);
  lol_my1.Push(4);

  std::queue<int> lol_orig;
  lol_orig.push(1);
  lol_orig.push(2);
  lol_orig.push(3);
  lol_orig.push(4);

  int kek = lol_my1.Front();
  int kek_orig = lol_orig.front();
  int kek_back = lol_my1.Back();
  int kek_orig_back = lol_orig.back();
  EXPECT_EQ(lol_my1.Size(), 4);
  EXPECT_EQ(kek, kek_orig);
  EXPECT_EQ(kek_back, kek_orig_back);
}

TEST(Queue_test, lol) {
  S21::Queue<int> lol_my;
  S21::Queue<int> lol_my1;
  lol_my.Push(1);
  lol_my.Push(2);
  lol_my.Push(3);
  lol_my1.Push(1);
  lol_my1.Push(2);
  lol_my1.Push(3);
  lol_my.Pop();
  lol_my.Pop();
  lol_my.Front();
  lol_my.Back();
  lol_my = lol_my1;
}

TEST(Queue_test, Front) {
  S21::Queue<int> lol_my;
  EXPECT_THROW(lol_my.Front(), std::logic_error);
}

TEST(Queue_test, empty) {
  S21::Queue<int> lol_my1;
  std::queue<int> lol_orig;
  EXPECT_EQ(lol_my1.Empty(), lol_orig.empty());
}

TEST(Queue_test, swap) {
  S21::Queue<int> kek = {1, 2, 3, 5, 6, 7};
  S21::Queue<int> kek2 = {55, 22, 53, 8342, 5643, 422};
  kek.Swap(kek2);
  EXPECT_EQ(kek.Back(), 422);
  EXPECT_EQ(kek.Front(), 55);
}

TEST(Queue_test, not_eq_length) {
  S21::Queue<int> kek = {1, 2, 3, 5, 6, 7};
  S21::Queue<int> kek2 = {55, 22, 53, 8342, 5643, 422, 44, 76, 33};
  kek.Swap(kek2);
  EXPECT_EQ(kek.Back(), 33);
  EXPECT_EQ(kek.Front(), 55);
}

TEST(Queue_test, empty_swap) {
  S21::Queue<int> kek;
  S21::Queue<int> kek2;
  kek.Swap(kek2);
  EXPECT_THROW(kek.Back(), std::logic_error);
  EXPECT_THROW(kek.Front(), std::logic_error);
}

TEST(Queue_test, CompareQueues) {
  S21::Queue<int> my_queue{1, 3, 10, -5, 20};
  std::queue<int> std_queue;
  std_queue.push(1);
  std_queue.push(3);
  std_queue.push(10);
  std_queue.push(-5);
  std_queue.push(20);
  EXPECT_TRUE(CheckEq(my_queue, std_queue));
  std_queue.push(20);
  EXPECT_FALSE(CheckEq(my_queue, std_queue));
}

TEST(Queue_test, Pop) {
  S21::Queue<int> lol{1, 3, 10, -5, 20, 21};
  std::queue<int> lol_orig;
  lol_orig.push(1);
  lol_orig.push(3);
  lol_orig.push(10);
  lol_orig.push(-5);
  lol_orig.push(20);
  lol_orig.push(21);
  lol.Pop();
  lol.Pop();
  lol_orig.pop();
  lol_orig.pop();
  EXPECT_TRUE(CheckEq(lol, lol_orig));
  EXPECT_EQ(lol.Front(), 10);

  S21::Queue<int> empty_kek;
  EXPECT_THROW(empty_kek.Back(), std::logic_error);
  ;
  EXPECT_THROW(empty_kek.Pop(), std::logic_error);
  EXPECT_THROW(empty_kek.Front(), std::logic_error);
}

TEST(Queue_test, InitializerqueueConstructor_2) {
  std::initializer_list<int> b;
  S21::Queue<int> lol{b};
  std::queue<int> lol_orig{b};
  EXPECT_TRUE(CheckEq(lol, lol_orig));
}

TEST(Queue_test, MoveConstructor) {
  std::queue<int> lol_orig;
  lol_orig.push(1);
  lol_orig.push(3);
  lol_orig.push(10);
  lol_orig.push(-5);
  lol_orig.push(20);
  lol_orig.push(21);

  S21::Queue<int> lol_my;
  lol_my.Push(1);
  lol_my.Push(3);
  lol_my.Push(10);
  lol_my.Push(-5);
  lol_my.Push(20);
  lol_my.Push(21);
  EXPECT_TRUE(CheckEq(lol_my, lol_orig));
}
