#include <bits/stdc++.h>
using namespace std;
constexpr int kN = int(6E2 + 10),
              kInf = int(1E9 + 10);
bitset<kN> went;
int edge[kN][kN];
int Merge(int n, int &s, int &t) {
  vector<int> v;
  bitset<kN> used;
  int dis[kN], tot, ans;
  used.reset();
  for (int i = 0; i < n; i++)
    if (!went[i]) v.push_back(i);
  tot = int(v.size());
  dis[0] = 0;
  for (int i = 1; i < tot; i++)
    dis[i] = edge[v[0]][v[i]];
  used[0] = true;
  for (int i = 2; i < tot; i++) {
    s = 0;
    for (int j = 1; j < tot; j++)
      if (!used[j])
        if (dis[j] > dis[s]) s = j;
    for (int j = 1; j < tot; j++)
      dis[j] += edge[v[s]][v[j]];
    used[s] = true;
  }
  for (int i = 0; i < tot; i++) {
    if (!used[i]) {
      t = i;
      break;
    }
  }
  ans = dis[t];
  s = v[s];
  t = v[t];
  return ans;
}
int Solve(int n, int m) {
  int c, l, r, s = -1, t = -1, ans = kInf;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) edge[i][j] = 0;
  while (m--) {
    scanf("%d%d%d", &l, &r, &c);
		l--, r--;
    edge[l][r] += c;
    edge[r][l] += c;
  }
  went.reset();
	for (int i = 3; i <= n; i++) {
    ans = min(ans, Merge(n, s, t));
    went[t] = true;
    for (int i = 0; i < n; i++) {
      edge[s][i] += edge[t][i];
      edge[i][s] += edge[i][t];
      edge[t][i] = edge[i][t] = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    if (!went[i]) {
      s = i;
      break;
    }
  }
  for (int i = s + 1; i < n; i++) {
    if (!went[i]) {
      t = i;
      break;
    }
  }
  return min(ans, edge[s][t]);
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	printf("%d\n", Solve(n, m));
}
