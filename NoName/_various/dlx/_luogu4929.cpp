#include <bits/stdc++.h>
using namespace std;
#include "_lib.cpp"
int main() {
  cin.tie(nullptr),
    ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  solver.Init(m);
  for (int i = 0; i < n; i++) {
    vector<int> col;
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      if (x) col.push_back(j + 1);
    }
    solver.AddRow(i + 1, col);
  }
  if (!solver.Solve()) {
    cout << "No Solution!\n";
  } else {
    for (int i = 0; i < solver.ansd; i++) {
      cout << (i ? " " : "") << solver.ans[i];
    }
    cout << '\n';
  }
}
