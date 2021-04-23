// max{cx} subject to {Ax<=b,x>=0}
// Solve(xs) -> results stored in xs
// INF -> unbounded; NAN -> infeasible
using Float = double;
Float Abs(Float x) { return x > 0 ? x : -x; }
struct LPSolver {
  int m, n;
  vector<int> ns, bs;
  vector<vector<Float>> dss;
  LPSolver(const vector<vector<double>> &ass,
    const vector<double> &b,
    const vector<double> &c)
      : m(int(b.size())), n(int(c.size())),
        ns(n + 1), bs(m),
        dss(m + 2, vector<Float>(n + 2)) {
    for (int i = 0; i < m; i++)
      for (int j = 0; j < n; j++)
        dss[i][j] = ass[i][j];
    for (int i = 0; i < m; i++) {
      bs[i] = n + i;
      dss[i][n] = -1;
      dss[i][n + 1] = b[i];
    }
    for (int j = 0; j < n; j++) {
      ns[j] = j;
      dss[m][j] = -c[j];
    }
    ns[n] = -1;
    dss[m + 1][n] = 1;
  }
  void Pivot(int r, int s) {
    Float *a = dss[r].data(), inv = 1 / a[s];
    for (int i = 0; i < m + 2; i++)
      if (i != r && Abs(dss[i][s]) > kEps) {
        Float *b = dss[i].data(),
              inv2 = b[s] * inv;
        for (int j = 0; j < n + 2; j++)
          b[j] -= a[j] * inv2;
        b[s] = a[s] * inv2;
      }
    for (int j = 0; j < n + 2; j++)
      if (j != s) dss[r][j] *= inv;
    for (int i = 0; i < m + 2; i++)
      if (i != r) dss[i][s] *= -inv;
    dss[r][s] = inv;
    swap(bs[r], ns[s]);
  }
#define MP make_pair
#define LTJ(X) \
  if (s == -1 || \
    MP(X[j], ns[j]) < MP(X[s], ns[s])) \
  s = j
  bool Simplex(int phase) {
    int x = m + phase - 1;
    for (;;) {
      int s = -1;
      for (int j = 0; j < n + 1; j++)
        if (ns[j] != -phase) LTJ(dss[x]);
      if (dss[x][s] >= -kEps) return true;
      int r = -1;
      for (int i = 0; i < m; i++) {
        if (dss[i][s] <= kEps) continue;
        if (r == -1 ||
          MP(dss[i][n + 1] / dss[i][s], bs[i]) <
            MP(dss[r][n + 1] / dss[r][s], bs[r]))
          r = i;
      }
      if (r == -1) return false;
      Pivot(r, s);
    }
  }
  Float Solve(vector<double> &x) {
    int r = 0;
    for (int i = 1; i < m; i++)
      if (dss[i][n + 1] < dss[r][n + 1]) r = i;
    if (dss[r][n + 1] < -kEps) {
      Pivot(r, n);
      if (!Simplex(2) || dss[m + 1][n + 1] < -kEps)
        return Float(NAN);
      for (int i = 0; i < m; i++)
        if (bs[i] == -1) {
          int s = 0;
          for (int j = 1; j < n + 1; j++)
            LTJ(dss[i]);
          Pivot(i, s);
        }
    }
    bool ok = Simplex(1);
    for (int i = 0; i < m; i++)
      if (bs[i] < n) x[bs[i]] = dss[i][n + 1];
    return ok ? dss[m][n + 1] : Float(INFINITY);
  }
#undef LTJ
#undef MP
};
