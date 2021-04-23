#include <bits/stdc++.h>
using namespace std;
constexpr int kN = 1e6, kSigma = 256;
namespace sfxarray {
bool t_glob[kN * 2];
int hi[kN], rev[kN];
int _s[kN * 2], sa_glob[kN * 2], c_glob[kN * 2],
  x[kN], p_glob[kN], q_glob[kN * 2];
// sa[i]: sa[i]-th suffix is the i-th
// lexigraphically smallest suffix. hi[i]: longest
// common prefix of suffix sa[i] and suffix sa[i -
// 1].
void pre(int *sa, int *c, int n, int z) {
  memset(sa, 0, sizeof(int) * n);
  memcpy(x, c, sizeof(int) * z);
}
void induce(int *sa, int *c, const int *s,
  const bool *t, int n, int z) {
  memcpy(x + 1, c, sizeof(int) * (z - 1));
  for (int i = 0; i < n; ++i)
    if (sa[i] && !t[sa[i] - 1])
      sa[x[s[sa[i] - 1]]++] = sa[i] - 1;
  memcpy(x, c, sizeof(int) * z);
  for (int i = n - 1; i >= 0; --i)
    if (sa[i] && t[sa[i] - 1])
      sa[--x[s[sa[i] - 1]]] = sa[i] - 1;
}
void sais(int *s, int *sa, int *p, int *q, bool *t,
  int *c, int n, int z) {
  bool uniq = t[n - 1] = true;
  int nn = 0, nmxz = -1, *nsa = sa + n,
      *ns = s + n, last = -1;
  memset(c, 0, sizeof(int) * z);
  for (int i = 0; i < n; ++i)
    uniq &= ++c[s[i]] < 2;
  for (int i = 0; i < z - 1; ++i) c[i + 1] += c[i];
  if (uniq) {
    for (int i = 0; i < n; ++i) sa[--c[s[i]]] = i;
    return;
  }
  for (int i = n - 2; i >= 0; --i)
    t[i] = (s[i] == s[i + 1] ? t[i + 1] :
                               s[i] < s[i + 1]);
  pre(sa, c, n, z);
  for (int i = 1; i <= n - 1; ++i)
    if (t[i] && !t[i - 1])
      sa[--x[s[i]]] = p[q[i] = nn++] = i;
  induce(sa, c, s, t, n, z);
  for (int i = 0; i < n; ++i)
    if (sa[i] && t[sa[i]] && !t[sa[i] - 1]) {
      bool neq = last < 0 ||
        memcmp(s + sa[i], s + last,
          (p[q[sa[i]] + 1] - sa[i]) *
            sizeof(int)) != 0;
      ns[q[last = sa[i]]] = nmxz += neq;
    }
  sais(ns, nsa, p + nn, q + n, t + n, c + z, nn,
    nmxz + 1);
  pre(sa, c, n, z);
  for (int i = nn - 1; i >= 0; --i)
    sa[--x[s[p[nsa[i]]]]] = p[nsa[i]];
  induce(sa, c, s, t, n, z);
}
void build(const string &s) {
  for (int i = 0; i < int(s.size()); ++i)
    _s[i] = uint8_t(s[i]);
  _s[s.size()] = 0;  // s shouldn't contain 0
  sais(_s, sa_glob, p_glob, q_glob, t_glob, c_glob,
    int(s.size()) + 1, kSigma);
  for (int i = 0; i < int(s.size()); ++i)
    sa_glob[i] = sa_glob[i + 1];
  for (int i = 0; i < int(s.size()); ++i)
    rev[sa_glob[i]] = i;
  int ind = 0;
  hi[0] = 0;
  for (int i = 0; i < int(s.size()); ++i) {
    if (!rev[i]) {
      ind = 0;
      continue;
    }
    while (i + ind < int(s.size()) &&
      s[i + ind] == s[sa_glob[rev[i] - 1] + ind])
      ++ind;
    hi[rev[i]] = ind ? ind-- : 0;
  }
}
}  // namespace sfxarray
