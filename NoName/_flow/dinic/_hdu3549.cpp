#include <bits/stdc++.h>
using namespace std;
#include "_lib.cpp"
int main() {
  int t;
  cin >> t;
  int cases = 0;
  while (t--) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= n; i++) graph[i].clear();
    for (int i = 0; i < m; i++) {
      int x, y, c;
      cin >> x >> y >> c;
      AddEdge(x, y, c);
    }
    cout << "Case " << ++cases << ": "
         << Dinic(1, n) << '\n';
  }
}
