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
