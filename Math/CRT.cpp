#include <bits/stdc++.h>
using namespace std;
constexpr int kN = int(1E5 + 10);
template <typename T>
tuple<T, T, T> ExtGcd(T a, T b) {
  // (d, x, y): ax + by = d, d = gcd(a, b)
  if (!b) return make_tuple(a, 1, 0);
  T d, x, y;
  tie(d, x, y) = ExtGcd(b, a % b);
  return make_tuple(d, y, x - (a / b) * y);
}

int64_t Crt(int n, int64_t *m, int64_t *a) {
  int64_t mod = 1, x = 0;
  for (int i = 1; i <= n; i++) mod *= m[i];
  for (int i = 1; i <= n; i++) {
    int64_t w = mod / m[i];
    auto t = ExtGcd(m[i], w);
    x = (x + get<2>(t) * w * a[i]) % mod;
  }
  return (x + mod) % mod;
}

int64_t a[kN], b[kN];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld%lld", &a[i], &b[i]);
	printf("%lld\n", Crt(n, a, b));
}
