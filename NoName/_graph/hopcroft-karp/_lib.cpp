// kN = #(left vertices), kM = #(right vertices)
// memset(head, -1, sizeof(head));
// AddEdge(left_vertex, right_vertex)
// MaxMatch(#(left vertices)) -> matchx, matchy
// 0-based
constexpr int kN = 1e5, kM = 1e5;
constexpr int kInf = 0x3f3f3f3f;
struct Edge {
  int ed, next;
};
vector<Edge> edge;
int head[kN], disx[kN], disy[kM], matchx[kN],
  matchy[kM], bfs_dis;
bool vis[kM];
void AddEdge(int a, int b) {
  edge.push_back({b, head[a]});
  head[a] = int(edge.size()) - 1;
}
bool Bfs(int v) {
  queue<int> que;
  bfs_dis = kInf;
  memset(disx, -1, sizeof(disx));
  memset(disy, -1, sizeof(disy));
  for (int i = 0; i < v; ++i) {
    if (matchx[i] < 0) {
      disx[i] = 0;
      que.push(i);
    }
  }
  while (!que.empty()) {
    int x = que.front();
    que.pop();
    if (disx[x] > bfs_dis) break;
    for (int i = head[x]; i >= 0;
         i = edge[i].next) {
      int y = edge[i].ed;
      if (disy[y] < 0) {
        disy[y] = disx[x] + 1;
        if (matchy[y] < 0) {
          bfs_dis = disy[y];
        } else {
          disx[matchy[y]] = disy[y] + 1;
          que.push(matchy[y]);
        }
      }
    }
  }
  return bfs_dis < kInf;
}
bool Dfs(int x) {
  for (int i = head[x]; i >= 0; i = edge[i].next) {
    int y = edge[i].ed;
    if (!vis[y] && disy[y] == disx[x] + 1) {
      vis[y] = true;
      if (matchy[y] >= 0 && disy[y] == bfs_dis)
        continue;
      if (matchy[y] < 0 || Dfs(matchy[y])) {
        matchx[x] = y;
        matchy[y] = x;
        return true;
      }
    }
  }
  return false;
}
int MaxMatch(int v) {
  int ret = 0;
  memset(matchx, -1, sizeof(matchx));
  memset(matchy, -1, sizeof(matchy));
  while (Bfs(v)) {
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < v; ++i) {
      if (matchx[i] < 0 && Dfs(i)) ++ret;
    }
  }
  return ret;
}
