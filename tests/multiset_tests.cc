#include <gtest/gtest.h>

#include "../multiset/s21_multiset.h"

TEST(multiset, allcase) {
  S21::MultiSet<int> my_multiset;
  my_multiset.Insert(10);
  my_multiset.Insert(10);
  my_multiset.Insert(10);
  my_multiset.Insert(10);
  my_multiset.Insert(10);
  my_multiset.Insert(10);
  my_multiset.Insert(10);
  my_multiset.Insert(10);
  my_multiset.Insert(10);
  my_multiset.Insert(10);
  EXPECT_EQ(my_multiset.Size(), 10U);
  auto it = my_multiset.Begin();
  my_multiset.Erase(it);
  EXPECT_EQ(my_multiset.Size(), 9U);
  it = my_multiset.Begin();
  EXPECT_EQ(*it, 10);
  my_multiset.Erase(it);
  EXPECT_EQ(my_multiset.Size(), 8U);
}
