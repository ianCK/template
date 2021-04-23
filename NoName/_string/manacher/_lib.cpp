constexpr int kN = 1000000;
int zz[kN * 2];
int zzz[kN], zzzz[kN];
void Manacher(const string &s) {
  string t = ".";
  for (int i = 0; i < int(s.length()); ++i)
    t += s[i], t += '.';
  int l = 0, r = 0;
  for (int i = 1; i < int(t.length()); ++i) {
    zz[i] =
      (r > i ? min(zz[2 * l - i], r - i) : 1);
    while (i - zz[i] >= 0 &&
      i + zz[i] < int(t.length()) &&
      t[i - zz[i]] == t[i + zz[i]])
      ++zz[i];
    if (i + zz[i] > r) r = i + zz[i], l = i;
  }
  for (int i = 1; i <= int(s.length()); i++) {
    zzz[i] = zz[2 * i - 1] / 2;
    zzzz[i] = zz[2 * i] / 2;
  }
}
