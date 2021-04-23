int64_t Crt(int n, int64_t *m, int *a) {
  int64_t mod = 1, x = 0;
  for (int i = 0; i < n; i++) mod *= m[i];
  for (int i = 0; i < n; i++) {
    int64_t w = mod / m[i];
    auto t = ExtGcd(m[i], w);
    x = (x + get<2>(t) * w * a[i]) % mod;
  }
  return (x + mod) % mod;
}
