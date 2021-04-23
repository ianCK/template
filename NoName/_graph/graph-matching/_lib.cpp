constexpr int kN = 514;
namespace matching {
int par[kN], pre[kN], match[kN], s[kN], vis[kN];
vector<int> g[kN];
queue<int> q;
void Init(int n) {
  for (int i = 0; i <= n; ++i)
    match[i] = pre[i] = n;
  for (int i = 0; i < n; ++i) g[i].clear();
}
void AddEdge(int u, int v) {
  g[u].push_back(v), g[v].push_back(u);
}
int Find(int u) {
  return u == par[u] ? u : par[u] = Find(par[u]);
}
int Lca(int x, int y, int n) {
  static int tk = 0;
  ++tk;
  x = Find(x), y = Find(y);
  for (;; swap(x, y)) {
    if (x != n) {
      if (vis[x] == tk) return x;
      vis[x] = tk;
      x = Find(pre[match[x]]);
    }
  }
}
void Blossom(int x, int y, int l) {
  while (Find(x) != l) {
    pre[x] = y;
    y = match[x];
    if (s[y] == 1) {
      q.push(y);
      s[y] = 0;
    }
    if (par[x] == x) par[x] = l;
    if (par[y] == y) par[y] = l;
    x = pre[y];
  }
}
bool Bfs(int r, int n) {
  for (int i = 0; i <= n; ++i) {
    par[i] = i, s[i] = -1;
  }
  queue<int>({r}).swap(q);
  s[r] = 0;
  while (q.size()) {
    int x = q.front();
    q.pop();
    for (int u : g[x]) {
      if (s[u] == -1) {
        pre[u] = x;
        s[u] = 1;
        if (match[u] == n) {
          for (int a = u, b = x, last; b != n;
               a = last, b = pre[a])
            last = match[b], match[b] = a,
            match[a] = b;
          return true;
        }
        q.push(match[u]);
        s[match[u]] = 0;
      } else if (!s[u] && Find(u) != Find(x)) {
        int l = Lca(u, x, n);
        Blossom(x, u, l);
        Blossom(u, x, l);
      }
    }
  }
  return false;
}
int Solve(int n) {
  int res = 0;
  for (int x = 0; x < n; ++x) {
    if (match[x] == n) res += Bfs(x, n);
  }
  return res;
}
}  // namespace matching
