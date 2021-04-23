#define ll long long
#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define vi vector<int>
#define pii pair<int, int>
#define rep(i, a, b) \
  for (int i = (a); i < (b); i++)
template <typename T>
using minpq =
  priority_queue<T, vector<T>, greater<T>>;
typedef long double ftype;
struct pt3 {
  ftype x, y, z;
  pt3(ftype x = 0, ftype y = 0, ftype z = 0)
      : x(x), y(y), z(z) {}
  pt3 operator-(const pt3 &o) const {
    return pt3(x - o.x, y - o.y, z - o.z);
  }
  pt3 cross(const pt3 &o) const {
    return pt3(y * o.z - z * o.y,
      z * o.x - x * o.z, x * o.y - y * o.x);
  }
  ftype dot(const pt3 &o) const {
    return x * o.x + y * o.y + z * o.z;
  }
  ftype abs() const { return sqrt(dot(*this)); }
};
struct edge;
struct face {
  int a, b, c;
  pt3 q;
  edge *e1, *e2, *e3;
  vi points;
  int dead = 1e9;
  face(int a, int b, int c, pt3 q)
      : a(a), b(b), c(c), q(q) {
    e1 = e2 = e3 = NULL;
  }
};
struct edge {
  edge *rev;
  face *f;
};
void glue(
  face *F1, face *F2, edge *&e1, edge *&e2) {
  e1 = new edge;
  e2 = new edge;
  e1->rev = e2;
  e2->rev = e1;
  e1->f = F2;
  e2->f = F1;
};
const ftype EPS = 1e-9;
mt19937 rng;
void prepare(vector<pt3> &p) {
  int n = sz(p);
  shuffle(all(p), rng);
  vi ve;
  ve.push_back(0);
  rep(i, 1, n) {
    if (sz(ve) == 1) {
      if ((p[ve[0]] - p[i]).abs() > EPS)
        ve.push_back(i);
    } else if (sz(ve) == 2) {
      if ((p[ve[1]] - p[ve[0]])
            .cross(p[i] - p[ve[0]])
            .abs() > EPS)
        ve.push_back(i);
    } else if (abs((p[i] - p[ve[0]])
                     .dot((p[ve[1]] - p[ve[0]])
                            .cross(p[ve[2]] -
                              p[ve[0]]))) > EPS) {
      ve.push_back(i);
      break;
    }
  }
  assert(sz(ve) == 4);
  vector<pt3> ve2;
  for (int i : ve) ve2.push_back(p[i]);
  reverse(all(ve));
  for (int i : ve) p.erase(p.begin() + i);
  p.insert(p.begin(), all(ve2));
}
vector<face *> hull3(vector<pt3> &p) {
  int n = sz(p);
  prepare(p);
  vector<face *> f, new_face(n, NULL);
  vector<vector<face *>> conflict(n);
  auto add_face = [&](int a, int b, int c) {
    face *F = new face(
      a, b, c, (p[b] - p[a]).cross(p[c] - p[a]));
    f.push_back(F);
    return F;
  };
  face *F1 = add_face(0, 1, 2);
  face *F2 = add_face(0, 2, 1);
  glue(F1, F2, F1->e1, F2->e3);
  glue(F1, F2, F1->e2, F2->e2);
  glue(F1, F2, F1->e3, F2->e1);
  rep(i, 3, n) {
    for (face *F : {F1, F2}) {
      ftype Q = (p[i] - p[F->a]).dot(F->q);
      if (Q > EPS) conflict[i].push_back(F);
      if (Q >= -EPS) F->points.push_back(i);
    }
  }
  rep(i, 3, n) {
    for (face *F : conflict[i])
      F->dead = min(F->dead, i);
    int v = -1;
    for (face *F : conflict[i]) {
      if (F->dead != i) continue;
      int parr[3] = {F->a, F->b, F->c};
      edge *earr[3] = {F->e1, F->e2, F->e3};
      rep(j, 0, 3) {
        int j2 = (j + 1);
        if (j2 >= 3) j2 -= 3;
        if (earr[j]->f->dead > i) {
          face *Fn = new_face[parr[j]] =
            add_face(parr[j], parr[j2], i);
          set_union(all(F->points),
            all(earr[j]->f->points),
            back_inserter(Fn->points));
          Fn->points.erase(
            stable_partition(all(Fn->points),
              [&](int k) {
                return k > i &&
                  (p[k] - p[Fn->a]).dot(Fn->q) >
                  EPS;
              }),
            Fn->points.end());
          for (int k : Fn->points) {
            conflict[k].push_back(Fn);
          }
          earr[j]->rev->f = Fn;
          Fn->e1 = earr[j];
          v = parr[j];
        }
      }
    }
    if (v == -1) continue;
    while (new_face[v]->e2 == NULL) {
      int u = new_face[v]->b;
      glue(new_face[v], new_face[u],
        new_face[v]->e2, new_face[u]->e3);
      v = u;
    }
  }
  f.erase(remove_if(all(f),
            [&](face *F) { return F->dead < n; }),
    f.end());
  return f;
}
