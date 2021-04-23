constexpr int kSigma = 26;
constexpr char kBase = 'a';
struct BurrowsWheeler {
  vector<int> v[kSigma];
  void BWT(char *ori, char *res) {
    // make ori -> ori + ori
    // then build suffix array
  }
  void IBWT(char *ori, char *res) {
    for (int i = 0; i < kSigma; i++) v[i].clear();
    int len = int(strlen(ori));
    for (int i = 0; i < len; i++)
      v[ori[i] - kBase].push_back(i);
    vector<int> a;
    for (int i = 0, ptr = 0; i < kSigma; i++)
      for (auto j : v[i]) {
        a.push_back(j);
        ori[ptr++] = char(kBase + i);
      }
    for (int i = 0, ptr = 0; i < len; i++) {
      res[i] = ori[a[ptr]];
      ptr = a[ptr];
    }
    res[len] = 0;
  }
};
