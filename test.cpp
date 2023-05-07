#include "mod_int.hpp"
#include "segment_tree/rmq.hpp"
#include "segment_tree/rsq.hpp"
#include "union_find.hpp"
#include <gtest/gtest.h>

TEST(union_find_test, tessoku_example) {
  int n = 3;
  UnionFind uf = UnionFind(n);
  uf.unite(1, 2);
  EXPECT_FALSE(uf.is_same(1, 3));
  uf.unite(2, 3);
  EXPECT_TRUE(uf.is_same(2, 3));
}

TEST(mod_int_test, drken_example) {
  const int MOD = 1000000007;
  using mint = ModInt<MOD>;
  mint a = 423343;
  mint b = 74324;
  mint c = 13231;
  mint d = 8432455;
  EXPECT_EQ((a * b + c) / d, 79639022);
}

TEST(rmq_test, tessoku_example) {
  RangeMaximumQueries<int> rmq(8, 0);
  rmq.update(3, 16);
  EXPECT_EQ(rmq.query(4, 7), 0);
  rmq.update(5, 13);
  EXPECT_EQ(rmq.query(4, 7), 13);
}

TEST(rsq_test, tessoku_example) {
  RangeSumQueries<int> rsq(8, 0);
  rsq.update(3, 16);
  rsq.update(6, 24);
  EXPECT_EQ(rsq.query(4, 8), 24);
  EXPECT_EQ(rsq.query(1, 7), 40);
}
