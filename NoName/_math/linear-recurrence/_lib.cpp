constexpr int kN = 1E5;
int64_t n, m, dp[kN + kN];
// dp[n] = \Sum_{i=0}^{m-1} A_i * dp[n - i - 1]
void PreDp(const vector<int64_t> &A) {
  dp[0] = 1;
  int64_t bdr = min(m + m, n);
  for (int64_t i = 1; i <= bdr; i++) {
    dp[i] = 0;
    for (int64_t j = i - 1;
         j >= max(int64_t(0), i - m); j--)
      dp[i] =
        AddMod(dp[i], MulMod(dp[j], A[i - j - 1]));
  }
}
vector<int64_t> Mul(
  vector<int64_t> &v1, vector<int64_t> &v2) {
  int _sz1 = int(v1.size()), _sz2 = int(v2.size());
  assert(_sz1 == m), assert(_sz2 == m);
  vector<int64_t> _v(m + m);
  for (int i = 0; i < m + m; i++) _v[i] = 0;
  // expand
  for (int i = 0; i < _sz1; i++)
    for (int j = 0; j < _sz2; j++)
      _v[i + j + 1] = AddMod(
        _v[i + j + 1], MulMod(v1[i], v2[j]));
  // shrink
  for (int i = 0; i < m; i++)
    for (int j = 1; j <= m; j++)
      _v[i + j] = AddMod(_v[i + j], _v[i]);
  for (int i = 0; i < m; i++) _v[i] = _v[i + m];
  _v.resize(m);
  return _v;
}
vector<int64_t> v_i, v_a;
int64_t solve() {  // v_a should be filled
  PreDp(v_a);
  if (n <= m + m) return dp[n];
  v_i.resize(m);
  for (int i = 0; i < m; i++) v_i[i] = 1;
  int64_t dlt = (n - m) / m, rdlt = dlt * m;
  while (dlt) {
    if (dlt & 1LL) v_i = Mul(v_i, v_a);
    v_a = Mul(v_a, v_a);
    dlt >>= 1;
  }
  int64_t ans = 0;
  for (int i = 0; i < m; i++)
    ans = AddMod(
      ans, MulMod(v_i[i], dp[n - i - 1 - rdlt]));
  return ans;
}
