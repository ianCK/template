// kN = #(vertices)
// MCMF.{Init, AddEdge, MincostMaxflow}
// MincostMaxflow(source, sink, flow_limit, &cost)
//   => flow
// 0-based
using Pii = pair<int, int>;
constexpr int kInf = 0x3f3f3f3f, kN = 500;
struct Edge {
  int from, to, cap, flow, cost;
  Edge() = default;
  Edge(int u, int v, int c, int f, int co)
      : from(u), to(v), cap(c), flow(f), cost(co) {
  }
};
vector<Edge> edges;
vector<int> graph[kN];
struct MCMF {
  int n, m, s, t;
  // Larger range for relabeling
  int64_t dis[kN], h[kN];
  int p[kN];
  void Init(int nn) {
    this->n = nn;
    for (int i = 0; i < n; i++) graph[i].clear();
    edges.clear();
  }
  void AddEdge(
    int from, int to, int cap, int cost) {
    edges.emplace_back(from, to, cap, 0, cost);
    edges.emplace_back(to, from, 0, 0, -cost);
    m = int(edges.size());
    graph[from].push_back(m - 2);
    graph[to].push_back(m - 1);
  }
  bool Dijkstra(int &max_flow, int64_t &cost) {
    priority_queue<Pii, vector<Pii>, greater<>> pq;
    for (int i = 0; i < n; i++) dis[i] = kInf;
    dis[s] = 0;
    pq.push(Pii(0, s));
    while (!pq.empty()) {
      Pii u = pq.top();
      pq.pop();
      int v = u.second;
      if (dis[v] < u.first) continue;
      for (int e_id : graph[v]) {
        Edge &e = edges[e_id];
        auto new_dis =
          dis[v] + e.cost + h[v] - h[e.to];
        if (e.cap > e.flow &&
          dis[e.to] > new_dis) {
          dis[e.to] = new_dis;
          p[e.to] = e_id;
          pq.push(Pii(dis[e.to], e.to));
        }
      }
    }
    if (dis[t] == kInf) return false;
    for (int i = 0; i < n; i++) h[i] += dis[i];
    int d = max_flow;
    for (int u = t; u != s; u = edges[p[u]].from)
      d =
        min(d, edges[p[u]].cap - edges[p[u]].flow);
    max_flow -= d;
    cost += int64_t(d) * h[t];
    for (int u = t; u != s; u = edges[p[u]].from) {
      edges[p[u]].flow += d;
      edges[p[u] ^ 1].flow -= d;
    }
    return true;
  }
  int MincostMaxflow(
    int ss, int tt, int max_flow, int64_t &cost) {
    this->s = ss, this->t = tt;
    cost = 0;
    for (int i = 0; i < n; i++) h[i] = 0;
    auto orig_max_flow = max_flow;
    while (Dijkstra(max_flow, cost) && max_flow) {}
    return orig_max_flow - max_flow;
  }
};
