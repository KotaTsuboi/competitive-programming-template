#include <cmath>
#include <limits>
#include <vector>

using namespace std;

template <typename T> class RangeMaximumQueries {
private:
  int size;
  vector<T> data;

public:
  RangeMaximumQueries(int n, T default_value) {
    size = pow(2, ceil(log(n) / log(2)));

    for (int i = 0; i < 2 * size; i++) {
      data.push_back(default_value);
    }
  }

  void update(int i, T value) {
    int pos = size + i - 1;
    data[pos] = value;

    while (pos > 1) {
      pos /= 2;
      data[pos] = max(data[2 * pos], data[2 * pos + 1]);
    }
  }

  T query(int l, int r) { return query(l, r, 1, size + 1, 1); }

private:
  T query(int l, int r, int a, int b, int pos) {
    if (b <= l || r <= a) {
      return numeric_limits<T>::min();
    }

    if (l <= a && b <= r) {
      return data[pos];
    }

    int m = (a + b) / 2;

    T left = query(l, r, a, m, 2 * pos);
    T right = query(l, r, m, b, 2 * pos + 1);

    return max(left, right);
  }
};

template <typename T> class RangeMinimumQueries {
private:
  int size;
  vector<T> data;

public:
  RangeMinimumQueries(int n, T default_value) {
    size = pow(2, ceil(log(n) / log(2)));

    for (int i = 0; i < 2 * size; i++) {
      data.push_back(default_value);
    }
  }

  void update(int i, T value) {
    int pos = size + i - 1;
    data[pos] = value;

    while (pos > 1) {
      pos /= 2;
      data[pos] = min(data[2 * pos], data[2 * pos + 1]);
    }
  }

  T query(int l, int r) { return query(l, r, 1, size + 1, 1); }

private:
  T query(int l, int r, int a, int b, int pos) {
    if (b <= l || r <= a) {
      return numeric_limits<T>::max();
    }

    if (l <= a && b <= r) {
      return data[pos];
    }

    int m = (a + b) / 2;

    T left = query(l, r, a, m, 2 * pos);
    T right = query(l, r, m, b, 2 * pos + 1);

    return min(left, right);
  }
};
