#include <bits/stdc++.h>
using namespace std;
// kN = #(vertices)
// Dfs(start, -1) => bcc_no[], bcc_cnt
// Init: g, bcc_cnt, in, s
// s/low[v] >= in[u]/low[v] > in[u]/ for bridge-
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
