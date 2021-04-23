constexpr int kN = 1023, kInf = 1e9;
struct Edge {
  int to, rev, cost, flow;
};
vector<Edge> graph[kN];
pair<int, int> dis[kN];
int from[kN];
void AddEdge(int u, int v, int c, int f) {
  graph[u].push_back(
    {v, int(graph[v].size()), c, f});
  graph[v].push_back(
    {u, int(graph[u].size()) - 1, -c, 0});
  return;
}
pair<int, int> Mcmf(int s, int t) {
  priority_queue<pair<int, int>,
    vector<pair<int, int>>,
    greater<pair<int, int>>>
    pq;
  pair<int, int> nxt;
  int now, flow;
  for (int i = 0; i < kN; i++)
    dis[i] = {
      kInf, 0};  // don't necessarily need kN
  dis[s] = {0, kInf};
  pq.emplace(dis[s].first, s);
  while (!pq.empty()) {
    nxt = pq.top();
    pq.pop();
    if (nxt.first > dis[nxt.second].first)
      continue;
    for (Edge i : graph[nxt.second])
      if (i.flow > 0 &&
        i.cost + nxt.first < dis[i.to].first) {
        dis[i.to] = {nxt.first + i.cost,
          min(dis[nxt.second].second, i.flow)};
        from[i.to] = i.rev;
        pq.emplace(dis[i.to].first, i.to);
      }
  }
  if (dis[t].first >= kInf) return dis[t];
  flow = dis[t].second;
  now = t;
  while (now != s) {
    graph[now][from[now]].flow += flow;
    graph[graph[now][from[now]].to]
         [graph[now][from[now]].rev]
           .flow -= flow;
    now = graph[now][from[now]].to;
  }
  return dis[t];
}
