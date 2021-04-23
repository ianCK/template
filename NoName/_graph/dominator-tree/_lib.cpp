constexpr int kN = 3e5;
struct DominatorTree {
  int n;
  vector<int> g[kN], rev_g[kN];
  int p[kN], in[kN], id[kN], dfs_clock;
  int sdom[kN], idom[kN], best[kN];
  vector<int> tree[kN];
  void Init(int _n) {
    n = _n;
    for (int i = 1; i <= n; i++)
      g[i].clear(), rev_g[i].clear();
  }
  void AddEdge(int u, int v) {
    g[u].push_back(v);
    rev_g[v].push_back(u);
  }
  void Dfs(int u) {
    id[in[u] = ++dfs_clock] = u;
    for (int v : g[u])
      if (!in[v]) { Dfs(v), p[in[v]] = in[u]; }
  }
  int Find(int y, int x) {
    if (y <= x) return y;
    int tmp = Find(p[y], x);
    if (sdom[best[y]] > sdom[best[p[y]]])
      best[y] = best[p[y]];
    return p[y] = tmp;
  }
  void Tarjan(int root) {
    dfs_clock = 0;
    for (int i = 1; i <= n; i++) {
      in[i] = idom[i] = 0;
      tree[i].clear();
      best[i] = sdom[i] = i;
    }
    Dfs(root);
    for (int i = n; i >= 1; i--) {
      int u = id[i];
      for (int v : rev_g[u]) {
        v = in[v];
        if (!v) continue;
        Find(v, i);
        sdom[i] = min(sdom[i], sdom[best[v]]);
      }
      if (i != 1) tree[sdom[i]].push_back(i);
      for (int v : tree[p[i]]) {
        Find(v, p[i]);
        idom[v] =
          sdom[best[v]] == p[i] ? p[i] : best[v];
      }
      tree[p[i]].clear();
    }
    for (int i = 2; i <= dfs_clock; i++) {
      if (idom[i] != sdom[i])
        idom[i] = idom[idom[i]];
      tree[id[idom[i]]].push_back(id[i]);
    }
  }
} dt;
