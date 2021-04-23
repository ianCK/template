#include "_flow/dinic/_lib.cpp"
vector<pair<int, int>> gomory_tree[kN];
// output saved in vector<pair<int, int>>
// gomory_tree[kN] AddEdge -> bidirectional Cut(u,
// v) = min edge in path(u, v)
void Gomory(vector<int> &v, int n, int rep = 1) {
  if (v.size() <= 1) return;
  int cut, s = v[0], t = v[1];
  vector<int> l, r;
  for (int i = 1; i <= n; i++)
    for (Edge &j : graph[i])
      j.cap = graph[j.to][j.rev].cap =
        (j.cap + graph[j.to][j.rev].cap) >> 1;
  cut = Dinic(s, t);
  for (int i : v)
    if (went[i] == went[s]) l.push_back(i);
    else
      r.push_back(i);
  gomory_tree[s].push_back({t, cut});
  gomory_tree[t].push_back({s, cut});
  Gomory(l, n, t);
  Gomory(r, n, s);
}
void Build(int n) {
  vector<int> all;
  for (int i = 1; i <= n; i++) all.push_back(i);
  Gomory(all, n);
}
