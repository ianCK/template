constexpr int kN = 150;
struct MaxClique {  // Maximum Clique
  bitset<kN> a[kN], cs[kN];
  int ans, sol[kN], q, cur[kN], d[kN], n;
  void init(int _n) {
    n = _n;
    for (int i = 0; i < n; i++) a[i].reset();
  }
  void addEdge(int u, int v) {
    a[u][v] = a[v][u] = 1;
  }
  void csort(vector<int> &r, vector<int> &c) {
    int mx = 1, km = max(ans - q + 1, 1), t = 0,
        m = int(r.size());
    cs[1].reset();
    cs[2].reset();
    for (int i = 0; i < m; i++) {
      int p = r[i], k = 1;
      while ((cs[k] & a[p]).count()) k++;
      if (k > mx) {
        mx++;
        cs[mx + 1].reset();
      }
      cs[k][p] = 1;
      if (k < km) r[t++] = p;
    }
    c.resize(m);
    if (t) c[t - 1] = 0;
    for (int k = km; k <= mx; k++) {
      for (int p = int(cs[k]._Find_first());
           p < kN; p = int(cs[k]._Find_next(p))) {
        r[t] = p;
        c[t] = k;
        t++;
      }
    }
  }
  void dfs(vector<int> &r, vector<int> &c, int l,
    bitset<kN> mask) {
    while (!r.empty()) {
      int p = r.back();
      r.pop_back();
      mask[p] = 0;
      if (q + c.back() <= ans) return;
      cur[q++] = p;
      vector<int> nr, nc;
      bitset<kN> nmask = mask & a[p];
      for (int i : r)
        if (a[p][i]) nr.push_back(i);
      if (!nr.empty()) {
        if (l < 4) {
          for (int i : nr)
            d[i] = int((a[i] & nmask).count());
          sort(nr.begin(), nr.end(),
            [&](int x, int y) {
              return d[x] > d[y];
            });
        }
        csort(nr, nc);
        dfs(nr, nc, l + 1, nmask);
      } else if (q > ans) {
        ans = q;
        copy(cur, cur + q, sol);
      }
      c.pop_back();
      q--;
    }
  }
  int solve(bitset<kN> mask) {  // vertex mask
    vector<int> r, c;
    for (int i = 0; i < n; i++)
      if (mask[i]) r.push_back(i);
    for (int i = 0; i < n; i++)
      d[i] = int((a[i] & mask).count());
    sort(r.begin(), r.end(),
      [&](int i, int j) { return d[i] > d[j]; });
    csort(r, c);
    dfs(r, c, 1, mask);
    return ans;  // sol[0 ~ ans-1]
  }
} graph;
// --- Enumerate maximal cliques ---
using BS = bitset<kN>;
int ans = 0, n;
BS neighbor[kN];  // Complement
void Dfs(BS r, BS p, BS x) {
  if (p.none() && x.none()) {
    ans = max(ans, int(r.count()));
  } else {
    if (int(p.count()) + int(r.count()) < ans)
      return;
    int pivot = 0;
    for (; !p[pivot] && !x[pivot] && pivot < n;
         pivot++) {}
    for (int i = 0; i < n; i++) {
      if (!neighbor[pivot][i] && p[i]) {
        r[i] = true;
        Dfs(r, p & neighbor[i], x & neighbor[i]);
        r[i] = p[i] = false;
        x[i] = true;
      }
    }
  }
}
