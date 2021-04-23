constexpr int kN = 100000;
int sa[kN], tmp[2][kN], cnt[kN], hi[kN], r[kN];
// sa[i]: sa[i]-th suffix is the i-th smallest
// suffix hi[i]: LCP of suffix sa[i] and suffix
// sa[i - 1]
void build(string s) {
  int *rnk = tmp[0], *rkn = tmp[1];
  int sigma = 256;
  int n = int(s.length());
  for (int i = 0; i < 256; i++) cnt[i] = 0;
  for (int i = 0; i < n; i++) cnt[rnk[i] = s[i]]++;
  for (int i = 1; i < 256; i++)
    cnt[i] += cnt[i - 1];
  for (int i = n - 1; i >= 0; i--)
    sa[--cnt[uint8_t(s[i])]] = i;
  for (int k = 1; k < n; k <<= 1) {
    for (int i = 0; i < sigma; i++) cnt[i] = 0;
    for (int i = 0; i < n; i++) cnt[rnk[i]]++;
    for (int i = 1; i < sigma; i++)
      cnt[i] += cnt[i - 1];
    int *sa2 = rkn;
    int p = 0;
    for (int i = n - k; i < n; i++) sa2[p++] = i;
    for (int i = 0; i < n; i++) {
      if (sa[i] >= k) sa2[p++] = sa[i] - k;
    }
    static int ttmp[kN], ttmp2[kN];
#pragma GCC ivdep
    for (int i = 0; i < n; i++)
      ttmp[i] = rnk[sa2[i]];
    for (int i = n - 1; i >= 0; i--)
      ttmp2[i] = --cnt[ttmp[i]];
    for (int i = n - 1; i >= 0; i--)
      sa[ttmp2[i]] = sa2[i];
#pragma GCC ivdep
    for (int i = 0; i < n; i++) {
      ttmp[i] = rnk[sa[i]];
      if (sa[i] + k < n) ttmp2[i] = rnk[sa[i] + k];
      else
        ttmp2[i] = -i;
    }
    rkn[sa[0]] = p = 0;
    for (int i = 1; i < n; i++) {
      if (!(ttmp[i - 1] == ttmp[i] &&
            ttmp2[i - 1] == ttmp2[i]))
        p++;
      rkn[sa[i]] = p;
    }
    swap(rnk, rkn);
    if (p == n - 1) break;
    sigma = p + 1;
  }
  for (int i = 0; i < n; i++) r[sa[i]] = i;
  int id = 0;
  hi[0] = 0;
  for (int i = 0; i < n; i++) {
    if (!r[i]) {
      id = 0;
      continue;
    }
    while (i + id < n &&
      s[i + id] == s[sa[r[i] - 1] + id])
      id++;
    hi[r[i]] = id ? id-- : 0;
  }
}
