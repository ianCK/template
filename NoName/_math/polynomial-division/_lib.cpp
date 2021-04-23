// First n elements
void ntt(vector<int> &vec, int n);
void intt(vector<int> &vec, int n);
vector<int> convolution(
  vector<int> &a, vector<int> &b);
vector<int> inverse(const vector<int> &v, int n) {
  vector<int> q(1, int(PowMod(v[0], kMod - 2)));
  for (int i = 2; i <= n; i <<= 1) {
    vector<int> fv(v.begin(), v.begin() + i);
    vector<int> fq(q.begin(), q.end());
    fv.resize(2 * i), fq.resize(2 * i);
    ntt(fq, 2 * i), ntt(fv, 2 * i);
    for (int j = 0; j < 2 * i; ++j) {
      fv[j] = fv[j] * 1LL * fq[j] % kMod * 1LL *
        fq[j] % kMod;
    }
    intt(fv, 2 * i);
    vector<int> res(i);
    for (int j = 0; j < i; ++j) {
      res[j] = kMod - fv[j];
      if (j < (i >> 1))
        (res[j] += 2 * q[j] % kMod) %= kMod;
    }
    q = res;
  }
  return q;
}
vector<int> divide(
  const vector<int> &a, const vector<int> &b) {
  // leading zero should be trimmed
  int n = int(a.size()), m = int(b.size());
  int k = 2;
  while (k < n - m + 1) k <<= 1;
  vector<int> ra(k), rb(k);
  for (int i = 0; i < min(n, k); ++i)
    ra[i] = a[n - i - 1];
  for (int i = 0; i < min(m, k); ++i)
    rb[i] = b[m - i - 1];
  vector<int> rbi = inverse(rb, k);
  vector<int> res = convolution(rbi, ra);
  res.resize(n - m + 1);
  reverse(res.begin(), res.end());
  return res;
}
constexpr int kInv2 = PowMod(2, kMod - 2);
vector<int> sqrt(vector<int> b, int n) {
  if (n == 1) return {int(sqrt(b[0]))};
  vector<int> h = sqrt(b, n >> 1);
  h.resize(n);
  vector<int> c = inverse(h, n);
  h.resize(n << 1);
  c.resize(n << 1);
  vector<int> res(n << 1);
  ntt(h, n << 1);
  for (int i = n; i < (n << 1); ++i) b[i] = 0;
  ntt(b, n << 1);
  ntt(c, n << 1);
  for (int i = 0; i < (n << 1); ++i)
    res[i] = 1LL *
      (h[i] + 1LL * c[i] * b[i] % kMod) % kMod *
      kInv2 % kMod;
  intt(res, n << 1);
  for (int i = n; i < (n << 1); ++i) res[i] = 0;
  return res;
}
