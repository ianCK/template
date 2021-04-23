// kN = #(vertices), kTimes = #(shuffle iterations)
// g = weight matrix, n = #(vertices)
// MaxWeightMatch() -> weight, match[]
// 1-based
constexpr int kN = 510, kTimes = 15;
int perm[kN], match[kN], stk[kN], stk_top, vis[kN],
  dis[kN];
int g[kN][kN], n;
bool Spfa(int u) {
  stk[stk_top++] = u;
  if (vis[u]) return true;
  vis[u] = true;
  for (int i = 1; i <= n; i++) {
    if (i != u && i != match[u] && !vis[i]) {
      int v = match[i];
      if (dis[v] < dis[u] + g[u][i] - g[i][v]) {
        dis[v] = dis[u] + g[u][i] - g[i][v];
        if (Spfa(v)) return true;
      }
    }
  }
  --stk_top;
  vis[u] = false;
  return false;
}
int MaxWeightMatch() {
  iota(perm + 1, perm + 1 + n, 1);
  for (int i = 1; i <= n; i += 2)
    match[i] = i + 1, match[i + 1] = i;
  for (int times = 0, modified = false;
       times < kTimes;) {
    memset(dis, 0, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    stk_top = 0;
    modified = false;
    for (int i = 1; i <= n; i++) {
      if (Spfa(perm[i])) {
        modified = 1;
        int t = match[stk[stk_top - 1]],
            j = stk_top - 2;
        while (stk[j] != stk[stk_top - 1]) {
          match[t] = stk[j];
          swap(t, match[stk[j]]);
          j--;
        }
        match[t] = stk[j];
        match[stk[j]] = t;
        break;
      }
    }
    if (!modified) {
      ++times;
      random_shuffle(perm + 1, perm + 1 + n);
    }
  }
  int ret = 0;
  for (int i = 1; i <= n; i++) {
    if (i < match[i]) ret += g[i][match[i]];
  }
  return ret;
}
