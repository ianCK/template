#include <bits/stdc++.h>
using namespace std;
#include "_lib.cpp"
int main() {
  cin.tie(nullptr),
    ios_base::sync_with_stdio(false);
  memset(head, -1, sizeof(head));
  int n, m;
  cin >> n >> m;
  vector<string> field(n, string(m, '\0'));
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> field[i][j];
      if (field[i][j] == '2') ++ans;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (field[i][j - 1] == '*' ||
        field[i][j] == '*')
        continue;
      if (field[i][j - 1] == '2' ||
        field[i][j] == '2')
        continue;
      assert(isdigit(field[i][j - 1]));
      assert(isdigit(field[i][j]));
      if ((field[i][j - 1] - '0') +
          (field[i][j] - '0') ==
        4) {
        if ((i + j) % 2 == 0)
          AddEdge(i * m + j, i * m + j - 1);
        else
          AddEdge(i * m + j - 1, i * m + j);
      }
    }
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (field[i - 1][j] == '*' ||
        field[i][j] == '*')
        continue;
      if (field[i - 1][j] == '2' ||
        field[i][j] == '2')
        continue;
      assert(isdigit(field[i - 1][j]));
      assert(isdigit(field[i][j]));
      if ((field[i - 1][j] - '0') +
          (field[i][j] - '0') ==
        4) {
        if ((i + j) % 2 == 0)
          AddEdge(i * m + j, (i - 1) * m + j);
        else
          AddEdge((i - 1) * m + j, i * m + j);
      }
    }
  }
  ans += MaxMatch(n * m);
  cout << ans << '\n';
}
