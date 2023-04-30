#include <iostream>
using namespace std;

template <int MOD> class ModInt {
  long long val;

public:
  constexpr ModInt(long long v = 0) noexcept : val(v % MOD) {
    if (val < 0) {
      val += MOD;
    }
  }
  constexpr int getmod() { return MOD; }
  constexpr ModInt operator-() const noexcept { return val ? MOD - val : 0; }
  constexpr ModInt operator+(const ModInt &r) const noexcept {
    return ModInt(*this) += r;
  }
  constexpr ModInt operator-(const ModInt &r) const noexcept {
    return ModInt(*this) -= r;
  }
  constexpr ModInt operator*(const ModInt &r) const noexcept {
    return ModInt(*this) *= r;
  }
  constexpr ModInt operator/(const ModInt &r) const noexcept {
    return ModInt(*this) /= r;
  }
  constexpr ModInt &operator+=(const ModInt &r) noexcept {
    val += r.val;
    if (val >= MOD) {
      val -= MOD;
    }
    return *this;
  }
  constexpr ModInt &operator-=(const ModInt &r) noexcept {
    val -= r.val;
    if (val < 0) {
      val += MOD;
    }
    return *this;
  }
  constexpr ModInt &operator*=(const ModInt &r) noexcept {
    val = val * r.val % MOD;
    return *this;
  }
  constexpr ModInt &operator/=(const ModInt &r) noexcept {
    long long a = r.val, b = MOD, u = 1, v = 0;
    while (b) {
      long long t = a / b;
      a -= t * b;
      swap(a, b);
      u -= t * v;
      swap(u, v);
    }
    val = val * u % MOD;
    if (val < 0) {
      val += MOD;
    }
    return *this;
  }
  constexpr bool operator==(const ModInt &r) const noexcept {
    return this->val == r.val;
  }
  constexpr bool operator!=(const ModInt &r) const noexcept {
    return this->val != r.val;
  }
  friend constexpr ostream &operator<<(ostream &os,
                                       const ModInt<MOD> &x) noexcept {
    return os << x.val;
  }
  friend constexpr ModInt<MOD> modpow(const ModInt<MOD> &a,
                                      long long n) noexcept {
    if (n == 0) {
      return 1;
    }
    auto t = modpow(a, n / 2);
    t = t * t;
    if (n & 1) {
      t = t * a;
    }
    return t;
  }
};
