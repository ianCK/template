#include <bits/stdc++.h>
using namespace std;
#include "../000-misc/_lib.cpp"
#include "_lib.cpp"
int main() {
  cin.tie(nullptr),
    ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<Line> ls;
  for (int i = 0; i < n; i++) {
    int m;
    cin >> m;
    P first{}, last{};
    for (int j = 0; j < m; j++) {
      double x, y;
      cin >> x >> y;
      if (!j) first = {x, y};
      else
        ls.emplace_back(last, P(x, y));
      last = {x, y};
    }
    ls.emplace_back(last, first);
  }
  auto v = Hpi(ls);
  cout << fixed << setprecision(3) << Area(v)
       << '\n';
}
