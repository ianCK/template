#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
using namespace std;
// kN = #(vertices)
// Dfs(start, -1) => bcc_no[], bcc_cnt
// Init: g, bcc_cnt, low, in
constexpr int kN = 100000;
int low[kN], in[kN], bcc_no[kN], dfs_clock,
  bcc_cnt;
vector<int> g[kN];
stack<int> s;
int Dfs(int u, int fa) {
  s.push(u);
  low[u] = in[u] = ++dfs_clock;
  for (auto v : g[u]) {
    if (v != fa) {
      if (!in[v]) {
        low[u] = min(low[u], Dfs(v, u));
        if (low[v] >= in[u]) {
          bcc_cnt++;
          vector<int> tmp;
          int x;
          do {
            x = s.top();
            s.pop();
            tmp.push_back(x);
            bcc_no[x] = bcc_cnt;
          } while (x != v);
          tmp.push_back(u);
          // nodes in tmp is a vertex-bcc
        }
      } else {
        low[u] = min(low[u], in[v]);
      }
    }
  }
  return low[u];
}
int main() {
  int m, n;
  while (cin >> m >> n) {
    while (!s.empty()) s.pop();
    for (int i = 0; i <= m; i++) g[i].clear();
    bcc_cnt = 0;
    memset(low, 0, sizeof(low));
    memset(in, 0, sizeof(in));
    dfs_clock = 0;
    memset(bcc_no, 0, sizeof(bcc_no));
    for (int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;
      g[a].push_back(b);
      g[b].push_back(a);
    }
    Dfs(1, 1);
    cout << bcc_cnt - 1 << '\n';
  }
}
