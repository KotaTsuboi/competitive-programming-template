#include "mod_int.hpp"
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
