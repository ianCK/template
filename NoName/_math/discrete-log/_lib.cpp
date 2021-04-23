int LogMod(int a, int b, int n) {
  int m, v, e = 1;
  m = int(sqrt(n + 0.5));
  v = int(Inv(PowMod(a, m, n), n));
  unordered_map<int, int> x;
  x[1] = 0;
  for (int i = 1; i < m; i++) {
    e = int(MulMod(e, a, n));
    if (!x.count(e)) x[e] = i;
  }
  for (int i = 0; i < m; i++) {
    if (x.count(b)) return i * m + x[b];
    b = int(MulMod(b, v, n));
  }
  return -1;
}
