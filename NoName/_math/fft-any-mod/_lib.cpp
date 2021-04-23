const double pi = acos(-1);
typedef complex<double> cp;
const int maxn = 131072;
struct FFT {
  int n, rev[maxn];
  cp omega[maxn], iomega[maxn];
  void init(int n_) {
    this->n = n_;
    for (int i = 0; i < n_; i++) {
      omega[i] = cp(cos(2 * pi / n_ * i),
        sin(2 * pi / n_ * i));
      iomega[i] = conj(omega[i]);
    }
    int k = __lg(n_);
    for (int i = 0; i < n_; i++) {
      int t = 0;
      for (int j = 0; j < k; j++)
        if (i & (1 << j)) t |= (1 << (k - j - 1));
      rev[i] = t;
    }
  }
  void transform(vector<cp>& a, cp* xomega) {
    for (int i = 0; i < n; i++)
      if (i < rev[i]) swap(a[i], a[rev[i]]);
    for (int len = 2; len <= n; len <<= 1) {
      int mid = len >> 1;
      int r = n / len;
      for (int j = 0; j < n; j += len)
        for (int i = 0; i < mid; i++) {
          cp t = xomega[r * i] * a[j + mid + i];
          a[j + mid + i] = a[j + i] - t;
          a[j + i] += t;
        }
    }
  }
  void fft(vector<cp>& a) { transform(a, omega); }
  void ifft(vector<cp>& a) {
    transform(a, iomega);
    for (int i = 0; i < n; i++) a[i] /= n;
  }
};
vector<int> conv(const vector<int>& a,
  const vector<int>& b, int p) {
  int sz = 1;
  while (sz < int(a.size()) + int(b.size()) - 1)
    sz <<= 1;
  vector<cp> fa(sz), fb(sz);
  for (int i = 0; i < int(a.size()); ++i)
    fa[i] = cp(a[i] & ((1 << 15) - 1), a[i] >> 15);
  for (int i = 0; i < int(b.size()); ++i)
    fb[i] = cp(b[i] & ((1 << 15) - 1), b[i] >> 15);
  FFT solver;
  solver.init(sz);
  solver.fft(fa), solver.fft(fb);
  double r = 0.25 / sz;
  cp r2(0, -1), r3(r, 0), r4(0, -r), r5(0, 1);
  for (int i = 0; i <= (sz >> 1); ++i) {
    int j = (sz - i) & (sz - 1);
    cp a1 = (fa[i] + conj(fa[j]));
    cp a2 = (fa[i] - conj(fa[j])) * r2;
    cp b1 = (fb[i] + conj(fb[j])) * r3;
    cp b2 = (fb[i] - conj(fb[j])) * r4;
    if (i != j) {
      cp c1 = (fa[j] + conj(fa[i]));
      cp c2 = (fa[j] - conj(fa[i])) * r2;
      cp d1 = (fb[j] + conj(fb[i])) * r3;
      cp d2 = (fb[j] - conj(fb[i])) * r4;
      fa[i] = c1 * d1 + c2 * d2 * r5;
      fb[i] = c1 * d2 + c2 * d1;
    }
    fa[j] = a1 * b1 + a2 * b2 * r5;
    fb[j] = a1 * b2 + a2 * b1;
  }
  solver.fft(fa), solver.fft(fb);
  vector<int> res(sz);
  for (int i = 0; i < sz; ++i) {
    auto x = int64_t(round(fa[i].real()));
    auto y = int64_t(round(fb[i].real()));
    auto z = int64_t(round(fa[i].imag()));
    res[i] =
      (x + ((y % p) << 15) + ((z % p) << 30)) % p;
  }
  return res;
}
vector<int64_t> mul(
  vector<int64_t> a, vector<int64_t> b) {
  int n = 1;
  int n1 = int(a.size()), n2 = int(b.size());
  while (n < n1 + n2) n <<= 1;
  vector<cp> tmp_a(n), tmp_b(n);
  // MAKE SURE THAT THE PRECISION IS OK
  for (int i = 0; i < n1; i++)
    tmp_a[i] = cp(double(a[i]), 0);
  for (int i = 0; i < n2; i++)
    tmp_b[i] = cp(double(b[i]), 0);
  FFT solver;
  solver.init(n);
  solver.fft(tmp_a), solver.fft(tmp_b);
  for (int i = 0; i < n; i++) tmp_a[i] *= tmp_b[i];
  solver.ifft(tmp_a);
  vector<int64_t> ans(n);
  for (int i = 0; i < n; i++)
    ans[i] = int64_t(round(tmp_a[i].real()));
  return ans;
}
