// kN = #(0.5 pool size)
// NewNode, DelNode, everything below "Public"
constexpr int kN = 200000, kInf = 1 << 30;
struct Info {
  int mx, mn, sum, sz;
  Info() : mx(-kInf), mn(kInf), sum(0), sz(0) {}
  Info(int mx, int mn, int sum, int sz)
      : mx(mx), mn(mn), sum(sum), sz(sz) {}
};
struct Flag {
  int mul, add;
  Flag() : mul(1), add(0) {}
  Flag(int mul, int add) : mul(mul), add(add) {}
  bool empty() { return mul == 1 && add == 0; }
};
Info operator+(const Info &a, const Flag &b) {
  return a.sz ?
    Info(a.mx * b.mul + b.add,
      a.mn * b.mul + b.add,
      a.sum * b.mul + b.add * a.sz, a.sz) :
    a;
}
Info operator+(const Info &a, const Info &b) {
  return Info(max(a.mx, b.mx), min(a.mn, b.mn),
    a.sum + b.sum, a.sz + b.sz);
}
Flag operator+(const Flag &a, const Flag &b) {
  return Flag(
    a.mul * b.mul, a.add * b.mul + b.add);
}
struct Node {
  Node *c[4], *par;
  Flag f_chain, f_all;
  Info chain, sub, all;
  bool rev, inner;
  int val;
  void Rev() {
    rev ^= 1;
    swap(c[0], c[1]);
  }
  void UpdChain(const Flag &a) {
    f_chain = f_chain + a;
    chain = chain + a;
    val = val * a.mul + a.add;
    all = chain + sub;
  }
  void UpdSub(const Flag &a, bool cha = true) {
    f_all = f_all + a;
    all = all + a;
    sub = sub + a;
    if (cha) UpdChain(a);
  }
  void Pull() {
    chain = all = sub = Info();
    if (!inner)
      all = chain = Info(val, val, val, 1);
    for (int i = 0; i < 2; i++) {
      if (c[i])
        chain = chain + c[i]->chain,
        sub = sub + c[i]->sub;
    }
    for (int i = 0; i < 4; i++) {
      if (c[i]) all = all + c[i]->all;
    }
    if (c[2]) sub = sub + c[2]->all;
    if (c[3]) sub = sub + c[3]->all;
  }
  void Push() {
    if (rev) {
      if (c[0]) c[0]->Rev();
      if (c[1]) c[1]->Rev();
      rev = false;
    }
    if (!f_all.empty()) {
      for (int i = 0; i < 4; i++) {
        if (c[i]) c[i]->UpdSub(f_all, i >= 2);
      }
      f_all = Flag();
    }
    if (!f_chain.empty()) {
      if (c[0]) c[0]->UpdChain(f_chain);
      if (c[1]) c[1]->UpdChain(f_chain);
      f_chain = Flag();
    }
  }
  Node *GetCh(int i) {
    Push();
    if (c[i]) c[i]->Push();
    return c[i];
  }
  bool IsParDir(int typ) {
    return par->c[typ + 1] == this;
  }
  int ParDir() {
    for (int i = 0; i < 4; i++) {
      if (par->c[i] == this) return i;
    }
    assert(0);
  }
  void SetCh(Node *x, int d) {
    if (x) x->par = this;
    c[d] = x;
  }
  bool IsRoot(int typ) {
    if (typ == 0)
      return !par ||
        (par->c[0] != this && par->c[1] != this);
    else
      return !par || !par->inner || !inner;
  }
} pool[kN * 2], *pool_cur = pool + kN, *trash[kN],
                **trash_cur = trash;
Node *NewNode() {
  Node *x = (trash_cur == trash) ? pool_cur++ :
                                   *(--trash_cur);
  for (int i = 0; i < 4; i++) x->c[i] = nullptr;
  x->par = nullptr;
  x->f_all = x->f_chain = Flag();
  x->all = x->chain = Info();
  x->inner = 1, x->rev = false, x->val = 0;
  return x;
}
void DelNode(Node *x) { *(trash_cur++) = x; }
void Rotate(Node *x, int typ) {
  Node *p = x->par;
  int d = x->IsParDir(typ);
  if (!p->par) x->par = nullptr;
  else
    p->par->SetCh(x, p->ParDir());
  p->SetCh(x->c[!d + typ], d + typ);
  x->SetCh(p, !d + typ);
  p->Pull();
}
void PushFromRoot(Node *x, int typ = 0) {
  if (!x->IsRoot(typ)) PushFromRoot(x->par, typ);
  x->Push();
}
void Splay(Node *x, int typ = 0) {
  // Need PushFromRoot if not called via access
  while (!x->IsRoot(typ)) {
    if (x->par->IsRoot(typ)) Rotate(x, typ);
    else if (x->IsParDir(typ) ==
      x->par->IsParDir(typ))
      Rotate(x->par, typ), Rotate(x, typ);
    else
      Rotate(x, typ), Rotate(x, typ);
  }
  x->Pull();
}
void AddVirt(Node *u, Node *w) {
  w->Push();
  for (int i = 2; i < 4; i++) {
    if (!w->c[i]) {
      w->SetCh(u, i);
      return;
    }
  }
  Node *x = NewNode(), *v;
  for (v = w; v->c[2]->inner; v = v->GetCh(2)) {}
  x->SetCh(v->c[2], 2);
  x->SetCh(u, 3);
  v->SetCh(x, 2);
  Splay(x, 2);
}
void DelVirt(Node *u) {
  if (u->par->inner) {
    u->par->par->SetCh(u->par->c[5 - u->ParDir()],
      u->par->ParDir());
    DelNode(u->par);
    Splay(u->par->par, 2);
  } else {
    u->par->SetCh(nullptr, u->ParDir());
  }
  u->par = nullptr;
}
// === Public ===
Node *Access(Node *x) {
  static Node *sta[kN];
  static int top = 0;
  Node *v = x, *u;
  for (u = x; u; u = u->par) sta[top++] = u;
  while (top) sta[--top]->Push();
  Splay(x);
  if (x->c[1])
    u = x->c[1], x->c[1] = nullptr, AddVirt(u, x),
    x->Pull();
  while (x->par) {
    for (u = x->par; u->inner; u = u->par) {}
    Splay(u);
    if (u->c[1])
      x->par->SetCh(u->c[1], x->ParDir()),
        Splay(x->par, 2);
    else
      DelVirt(x);
    u->SetCh(x, 1);
    (x = u)->Pull();
  }
  Splay(v);
  return x;
}
void MakeRoot(Node *x) {
  Access(x);
  x->Rev();
}
Node *FindPar(Node *x) {
  Access(x);
  if (!x->GetCh(0)) return nullptr;
  x = x->GetCh(0);
  while (x && x->c[1]) x = x->GetCh(1);
  Splay(x);
  return x;
}
Node *FindRoot(Node *x) {
  Access(x);
  while (x->c[0]) x = x->GetCh(0);
  Splay(x);
  return x;
}
Node *Cut(Node *u) {
  Node *v = FindPar(u);
  if (v) Access(v), DelVirt(u), v->Pull();
  return v;
}
void Link(Node *u, Node *v) {
  Node *p = Cut(u);
  if (FindRoot(u) != FindRoot(v)) p = v;
  if (p) Access(p), AddVirt(u, p), p->Pull();
}
Info QueryLca(Node *u, Node *v) {
  Access(u);
  Node *lca = Access(v);
  Splay(lca);
  PushFromRoot(u);
  Splay(u);
  Info info =
    Info(lca->val, lca->val, lca->val, 1);
  return info +
    (lca->c[1] ? lca->c[1]->chain : Info()) +
    (u == lca ? Info() : u->chain);
}
