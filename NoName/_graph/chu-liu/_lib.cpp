constexpr int kN = 1000, kInf = 1 << 30;
template <typename T> struct DMST {
  bool vis[kN], flag[kN];
  int n;
  T w[kN][kN];
  int pre[kN];
  void Init(int nn) {
    this->n = nn;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++) w[i][j] = kInf;
    memset(vis, 0, sizeof(vis));
    memset(flag, 0, sizeof(flag));
  }
  void AddEdge(int u, int v, T d) {
    w[u][v] = min(w[u][v], d);
  }
  T DirectedMst(int u) {
    T ans = 0;
    memset(vis, 0, sizeof(vis));
    while (1) {
      for (int i = 1; i <= n; i++)
        if (i != u && !flag[i]) {
          w[i][i] = kInf, pre[i] = i;
          for (int j = 1; j <= n; j++)
            if (!flag[j] && w[j][i] < w[pre[i]][i])
              pre[i] = j;
          if (pre[i] == i) return -1;
        }
      int i;
      for (i = 1; i <= n; i++)
        if (i != u && !flag[i]) {
          int j = i, cnt = 0;
          while (j != u && pre[j] != i && cnt <= n)
            j = pre[j], cnt++;
          if (j == u || cnt > n) continue;
          break;
        }
      if (i > n) {
        for (int j = 1; j <= n; j++)
          if (j != u && !flag[j])
            ans += w[pre[j]][j];
        return ans;
      }
      int now = i;
      memset(vis, 0, sizeof(vis));
      do {
        ans += w[pre[now]][now],
          now = pre[now], vis[now] = flag[now] = 1;
      } while (now != i);
      flag[i] = 0;
      for (int k = 1; k <= n; k++)
        if (vis[k]) {
          for (int j = 1; j <= n; j++)
            if (!vis[j]) {
              if (w[i][j] > w[k][j])
                w[i][j] = w[k][j];
              if (w[j][k] < kInf &&
                w[j][k] - w[pre[k]][k] < w[j][i])
                w[j][i] = w[j][k] - w[pre[k]][k];
            }
        }
    }
    return ans;
  }
};
