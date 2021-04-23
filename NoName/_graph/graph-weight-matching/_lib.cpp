// MaxN: #(vertices)
// make sure to set mat[u][v] = edge(u, v, 0)
// MaxWeightMatch() -> n_matches, tot_weight, mate
constexpr int kInf = 2147483647;
constexpr int kN = 1000;
constexpr int kNX = kN + kN;
template <class T>
inline void Tension(T &a, const T &b) {
  if (b < a) a = b;
}
template <class T>
inline void Relax(T &a, const T &b) {
  if (b > a) a = b;
}
template <class T> inline int Size(const T &a) {
  return int(a.size());
}
struct Edge {
  int v, u, w;
  Edge() = default;
  Edge(const int &_v, const int &_u, const int &_w)
      : v(_v), u(_u), w(_w) {}
};
int n, m;
Edge mat[kNX + 1][kNX + 1];
int n_matches;
int64_t tot_weight;
int mate[kNX + 1];
int lab[kNX + 1];
int q_n, q[kN];
int fa[kNX + 1], col[kNX + 1];
int slackv[kNX + 1];
int n_x;
int bel[kNX + 1], blofrom[kNX + 1][kN + 1];
vector<int> bloch[kNX + 1];
inline int EDelta(
  const Edge &e)  // does not work inside blossoms
{
  return lab[e.v] + lab[e.u] - mat[e.v][e.u].w * 2;
}
inline void UpdateSlackV(int v, int x) {
  if (!slackv[x] ||
    EDelta(mat[v][x]) < EDelta(mat[slackv[x]][x]))
    slackv[x] = v;
}
inline void CalcSlackV(int x) {
  slackv[x] = 0;
  for (int v = 1; v <= n; v++)
    if (mat[v][x].w > 0 && bel[v] != x &&
      col[bel[v]] == 0)
      UpdateSlackV(v, x);
}
inline void QPush(int x) {
  if (x <= n) {
    q[q_n++] = x;
  } else {
    for (int i = 0; i < Size(bloch[x]); i++)
      QPush(bloch[x][i]);
  }
}
inline void SetMate(int xv, int xu) {
  mate[xv] = mat[xv][xu].u;
  if (xv > n) {
    Edge e = mat[xv][xu];
    int xr = blofrom[xv][e.v];
    int pr = int(find(bloch[xv].begin(),
                   bloch[xv].end(), xr) -
      bloch[xv].begin());
    if (pr % 2 == 1) {
      reverse(
        bloch[xv].begin() + 1, bloch[xv].end());
      pr = Size(bloch[xv]) - pr;
    }
    for (int i = 0; i < pr; i++)
      SetMate(bloch[xv][i], bloch[xv][i ^ 1]);
    SetMate(xr, xu);
    rotate(bloch[xv].begin(),
      bloch[xv].begin() + pr, bloch[xv].end());
  }
}
inline void SetBel(int x, int b) {
  bel[x] = b;
  if (x > n) {
    for (int i = 0; i < Size(bloch[x]); i++)
      SetBel(bloch[x][i], b);
  }
}
inline void Augment(int xv, int xu) {
  while (true) {
    int xnu = bel[mate[xv]];
    SetMate(xv, xu);
    if (!xnu) return;
    SetMate(xnu, bel[fa[xnu]]);
    xv = bel[fa[xnu]], xu = xnu;
  }
}
inline int GetLca(int xv, int xu) {
  static bool book[kNX + 1];
  for (int x = 1; x <= n_x; x++) book[x] = false;
  while (xv || xu) {
    if (xv) {
      if (book[xv]) return xv;
      book[xv] = true;
      xv = bel[mate[xv]];
      if (xv) xv = bel[fa[xv]];
    }
    swap(xv, xu);
  }
  return 0;
}
inline void AddBlossom(int xv, int xa, int xu) {
  int b = n + 1;
  while (b <= n_x && bel[b]) b++;
  if (b > n_x) n_x++;
  lab[b] = 0;
  col[b] = 0;
  mate[b] = mate[xa];
  bloch[b].clear();
  bloch[b].push_back(xa);
  for (int x = xv; x != xa;
       x = bel[fa[bel[mate[x]]]])
    bloch[b].push_back(x),
      bloch[b].push_back(bel[mate[x]]),
      QPush(bel[mate[x]]);
  reverse(bloch[b].begin() + 1, bloch[b].end());
  for (int x = xu; x != xa;
       x = bel[fa[bel[mate[x]]]])
    bloch[b].push_back(x),
      bloch[b].push_back(bel[mate[x]]),
      QPush(bel[mate[x]]);
  SetBel(b, b);
  for (int x = 1; x <= n_x; x++) {
    mat[b][x].w = mat[x][b].w = 0;
    blofrom[b][x] = 0;
  }
  for (int i = 0; i < Size(bloch[b]); i++) {
    int xs = bloch[b][i];
    for (int x = 1; x <= n_x; x++)
      if (mat[b][x].w == 0 ||
        EDelta(mat[xs][x]) < EDelta(mat[b][x]))
        mat[b][x] = mat[xs][x],
        mat[x][b] = mat[x][xs];
    for (int x = 1; x <= n_x; x++)
      if (blofrom[xs][x]) blofrom[b][x] = xs;
  }
  CalcSlackV(b);
}
inline void ExpandBlossom1(int b)  // lab[b] == 1
{
  for (int i = 0; i < Size(bloch[b]); i++)
    SetBel(bloch[b][i], bloch[b][i]);
  int xr = blofrom[b][mat[b][fa[b]].v];
  int pr = int(
    find(bloch[b].begin(), bloch[b].end(), xr) -
    bloch[b].begin());
  if (pr % 2 == 1) {
    reverse(bloch[b].begin() + 1, bloch[b].end());
    pr = Size(bloch[b]) - pr;
  }
  for (int i = 0; i < pr; i += 2) {
    int xs = bloch[b][i], xns = bloch[b][i + 1];
    fa[xs] = mat[xns][xs].v;
    col[xs] = 1, col[xns] = 0;
    slackv[xs] = 0, CalcSlackV(xns);
    QPush(xns);
  }
  col[xr] = 1;
  fa[xr] = fa[b];
  for (int i = pr + 1; i < Size(bloch[b]); i++) {
    int xs = bloch[b][i];
    col[xs] = -1;
    CalcSlackV(xs);
  }
  bel[b] = 0;
}
inline void ExpandBlossomFinal(
  int b)  // at the final stage
{
  for (int i = 0; i < Size(bloch[b]); i++) {
    if (bloch[b][i] > n && lab[bloch[b][i]] == 0)
      ExpandBlossomFinal(bloch[b][i]);
    else
      SetBel(bloch[b][i], bloch[b][i]);
  }
  bel[b] = 0;
}
inline bool OnFoundEdge(const Edge &e) {
  int xv = bel[e.v], xu = bel[e.u];
  if (col[xu] == -1) {
    int nv = bel[mate[xu]];
    fa[xu] = e.v;
    col[xu] = 1, col[nv] = 0;
    slackv[xu] = slackv[nv] = 0;
    QPush(nv);
  } else if (col[xu] == 0) {
    int xa = GetLca(xv, xu);
    if (!xa) {
      Augment(xv, xu), Augment(xu, xv);
      for (int b = n + 1; b <= n_x; b++)
        if (bel[b] == b && lab[b] == 0)
          ExpandBlossomFinal(b);
      return true;
    }
    AddBlossom(xv, xa, xu);
  }
  return false;
}
bool Match() {
  for (int x = 1; x <= n_x; x++)
    col[x] = -1, slackv[x] = 0;
  q_n = 0;
  for (int x = 1; x <= n_x; x++)
    if (bel[x] == x && !mate[x])
      fa[x] = 0, col[x] = 0, slackv[x] = 0,
      QPush(x);
  if (q_n == 0) return false;
  while (true) {
    for (int i = 0; i < q_n; i++) {
      int v = q[i];
      for (int u = 1; u <= n; u++)
        if (mat[v][u].w > 0 && bel[v] != bel[u]) {
          int d = EDelta(mat[v][u]);
          if (d == 0) {
            if (OnFoundEdge(mat[v][u]))
              return true;
          } else if (col[bel[u]] == -1 ||
            col[bel[u]] == 0) {
            UpdateSlackV(v, bel[u]);
          }
        }
    }
    int d = kInf;
    for (int v = 1; v <= n; v++)
      if (col[bel[v]] == 0) Tension(d, lab[v]);
    for (int b = n + 1; b <= n_x; b++)
      if (bel[b] == b && col[b] == 1)
        Tension(d, lab[b] / 2);
    for (int x = 1; x <= n_x; x++)
      if (bel[x] == x && slackv[x]) {
        if (col[x] == -1)
          Tension(d, EDelta(mat[slackv[x]][x]));
        else if (col[x] == 0)
          Tension(
            d, EDelta(mat[slackv[x]][x]) / 2);
      }
    for (int v = 1; v <= n; v++) {
      if (col[bel[v]] == 0) lab[v] -= d;
      else if (col[bel[v]] == 1)
        lab[v] += d;
    }
    for (int b = n + 1; b <= n_x; b++)
      if (bel[b] == b) {
        if (col[bel[b]] == 0) lab[b] += d * 2;
        else if (col[bel[b]] == 1)
          lab[b] -= d * 2;
      }
    q_n = 0;
    for (int v = 1; v <= n; v++)
      if (lab[v] == 0)  // all unmatched vertices'
                        // labels are zero! cheers!
        return false;
    for (int x = 1; x <= n_x; x++)
      if (bel[x] == x && slackv[x] &&
        bel[slackv[x]] != x &&
        EDelta(mat[slackv[x]][x]) == 0) {
        if (OnFoundEdge(mat[slackv[x]][x]))
          return true;
      }
    for (int b = n + 1; b <= n_x; b++)
      if (bel[b] == b && col[b] == 1 &&
        lab[b] == 0)
        ExpandBlossom1(b);
  }
}
void MaxWeightMatch() {
  for (int v = 1; v <= n; v++) mate[v] = 0;
  n_x = n;
  n_matches = 0;
  tot_weight = 0;
  bel[0] = 0;
  for (int v = 1; v <= n; v++)
    bel[v] = v, bloch[v].clear();
  for (int v = 1; v <= n; v++)
    for (int u = 1; u <= n; u++)
      blofrom[v][u] = v == u ? v : 0;
  int w_max = 0;
  for (int v = 1; v <= n; v++)
    for (int u = 1; u <= n; u++)
      Relax(w_max, mat[v][u].w);
  for (int v = 1; v <= n; v++) lab[v] = w_max;
  while (Match()) n_matches++;
  for (int v = 1; v <= n; v++)
    if (mate[v] && mate[v] < v)
      tot_weight += mat[v][mate[v]].w;
}
