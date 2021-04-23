#include <bits/stdc++.h>
using namespace std;
#include "_lib.cpp"
int main() {
  cin.tie(nullptr),
    ios_base::sync_with_stdio(false);
  int m, n, t;
  cin >> m >> n >> t;
  vector<vector<double>> ass(n, vector<double>(m));
  vector<double> bs(n), cs(m), xs(m);
  for (int i = 0; i < m; i++) cin >> cs[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) cin >> ass[i][j];
    cin >> bs[i];
  }
  vector<int> perm(n);
  iota(perm.begin(), perm.end(), 0);
  mt19937 rng;
  shuffle(perm.begin(), perm.end(), rng);
  auto tmpa = ass;
  for (int i = 0; i < n; i++)
    tmpa[i] = ass[perm[i]];
  ass = tmpa;
  auto tmpb = bs;
  for (int i = 0; i < n; i++)
    tmpb[i] = bs[perm[i]];
  bs = tmpb;
  vector<int> permm(m);
  iota(permm.begin(), permm.end(), 0);
  shuffle(permm.begin(), permm.end(), rng);
  for (int i = 0; i < n; i++) {
    auto tmpas = ass[i];
    for (int j = 0; j < m; j++)
      tmpas[permm[j]] = ass[i][j];
    ass[i] = tmpas;
  }
  auto tmpcs = cs;
  for (int j = 0; j < m; j++)
    tmpcs[permm[j]] = cs[j];
  cs = tmpcs;
  auto solver = LPSolver(ass, bs, cs);
  double res = solver.Solve(xs);
  cout.setf(ios::fixed);
  cout.precision(12);
  if (std::isinf(res)) cout << "Unbounded\n";
  else if (std::isnan(res))
    cout << "Infeasible\n";
  else {
    cout << res << '\n';
    if (t) {
      for (int i = 0; i < m; i++)
        cout << xs[permm[i]] << ' ';
      cout << '\n';
    }
  }
}
