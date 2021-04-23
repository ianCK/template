constexpr int kN = int(1E5 + 10);
using Pii = pair<int, int>;
vector<pair<int, int>> g[kN];
bool vis[kN];
int sz[kN], mx[kN], cen_fa[kN], cen_sz[kN],
  dep[kN];
vector<int> now;
void GetCen(int u) {
  now.push_back(u);
  sz[u] = 1, mx[u] = 0, vis[u] = 1;
  for (Pii v : g[u])
    if (!vis[v.first]) {
      GetCen(v.first);
      sz[u] += sz[v.first];
      mx[u] = max(mx[u], sz[v.first]);
    }
}
vector<int64_t> dis[kN], dis2[kN];
int64_t dd[20][kN];
void GetDis(int u, int64_t d, vector<int64_t> &vec,
  int depth) {
  vis[u] = 1;
  now.push_back(u);
  vec.push_back(d);
  if (depth != -1) dd[depth][u] = d;
  for (Pii v : g[u])
    if (!vis[v.first]) {
      GetDis(v.first, d + v.second, vec, depth);
    }
}
int Dfs(int u, int fa, int d) {
  int cen = -1;
  now.clear();
  GetCen(u);
  int s = int(now.size());
  for (int w : now) {
    if (max(mx[w], s - sz[w]) * 2 <= s) cen = w;
    vis[w] = 0;
  }
  now.clear();
  GetDis(cen, 0, dis[cen], d);
  for (int w : now) vis[w] = 0;
  sort(dis[cen].begin(), dis[cen].end());
  cen_sz[cen] = s;
  dep[cen] = d;
  vis[cen] = 1;
  for (Pii v : g[cen])
    if (!vis[v.first]) {
      vector<int64_t> tmp;
      now.clear();
      GetDis(v.first, v.second, tmp, -1);
      for (int w : now) vis[w] = 0;
      int ch = Dfs(v.first, cen, d + 1);
      cen_fa[ch] = cen;
      dis2[ch] = tmp;
      sort(dis2[ch].begin(), dis2[ch].end());
    }
  return cen;
}
int Query(int u, int64_t d) {
  int res = int(
    upper_bound(dis[u].begin(), dis[u].end(), d) -
    dis[u].begin());
  int cur = u;
  while (cen_fa[cur] != 0) {
    int fa = cen_fa[cur];
    int64_t ddis = dd[dep[fa]][u];
    res += upper_bound(dis[fa].begin(),
             dis[fa].end(), d - ddis) -
      dis[fa].begin();
    res -= upper_bound(dis2[cur].begin(),
             dis2[cur].end(), d - ddis) -
      dis2[cur].begin();
    cur = fa;
  }
  return res;
}
