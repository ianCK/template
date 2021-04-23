#include <bits/stdc++.h>
using namespace std;
#include "_lib.cpp"
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  MCMF mcmf;
  mcmf.Init(n + 1);
  for (int i = 0; i < m; i++) {
    int s, t, c, w;
    cin >> s >> t >> c >> w;
    mcmf.AddEdge(s, t, c, w);
  }
  int64_t cost = 0;
  int flow = mcmf.MincostMaxflow(1, n, 1e9, cost);
  cout << flow << ' ' << cost << '\n';
}
