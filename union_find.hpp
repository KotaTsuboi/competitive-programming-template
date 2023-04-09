class UnionFind {
private:
  int parent[100009];
  int size[100009];

  int root(int x) {
    while (true) {
      if (parent[x] == -1) {
        break;
      }
      x = parent[x];
    }

    return x;
  }

public:
  UnionFind(int n) {
    for (int i = 1; i <= n; i++) {
      parent[i] = -1;
      size[i] = 1;
    }
  }

  void unite(int u, int v) {
    int root_u = root(u);
    int root_v = root(v);
    if (root_u == root_v) {
      return;
    }
    if (size[root_u] < size[root_v]) {
      parent[root_u] = root_v;
      size[root_v] += size[root_u];
    } else {
      parent[root_v] = root_u;
      size[root_u] += size[root_v];
    }
  }

  bool is_same(int u, int v) { return root(u) == root(v); }
};
