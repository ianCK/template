// kN = #(vertices)
// AddEdge, Dinic(source, sink) => flow
// Init: graph
// 0-based
constexpr int kN = 210, kInf = int(1E9 + 10);
struct Edge {
  int to, rev, cap;
};
vector<Edge> graph[kN];
int dep[kN], iter[kN], went[kN];
void AddEdge(int u, int v, int c) {
  graph[u].push_back({v, int(graph[v].size()), c});
  graph[v].push_back(
    {u, int(graph[u].size()) - 1, 0});
}
void Bfs(int s, int t) {
  queue<int> q;
  went[s] = t;
  iter[s] = dep[s] = 0;
  q.push(s);
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (Edge i : graph[now]) {
      if (i.cap > 0 && went[i.to] != t) {
        went[i.to] = t;
        dep[i.to] = dep[now] + 1;
        iter[i.to] = 0;
        q.push(i.to);
      }
    }
  }
}
int Dfs(int u, int t, int nv) {
  int temp;
  if (u == t) return nv;
  for (int &i = iter[u]; i < int(graph[u].size());
       i++) {
    Edge &nxt = graph[u][i];
    if (nxt.cap > 0 && dep[nxt.to] > dep[u]) {
      temp = Dfs(nxt.to, t, min(nxt.cap, nv));
      if (temp > 0) {
        nxt.cap -= temp;
        graph[nxt.to][nxt.rev].cap += temp;
        return temp;
      }
    }
  }
  return 0;
}
int Dinic(int s, int t) {
  int cnt = 0, ans = 0;
  fill_n(went, kN, cnt);
  while (true) {
    Bfs(s, ++cnt);
    if (went[s] != went[t]) break;
    int f = 0;
    while ((f = Dfs(s, t, kInf)) > 0) ans += f;
  }
  return ans;
}
