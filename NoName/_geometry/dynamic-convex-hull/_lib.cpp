constexpr int kN = 3010;
constexpr double kInf = 1e16;
int64_t dp[kN], tmp[kN], pre[kN];
struct HLine {
  static bool flag;
  int64_t a, b;
  double l, r;
  double operator()(double x) const {
    // MAKE SURE THAT THE PRECISION IS OK
    return double(a) * x + double(b);
  }
  bool operator<(const HLine& rhs) const {
    return flag ?
      a < rhs.a || (a == rhs.a && b < rhs.b) :
      l < rhs.l;
  }
};
double Intersect(HLine p, HLine q) {
  assert(p.a != q.a);
  return double(q.b - p.b) / double(p.a - q.a);
}
bool HLine::flag = 1;
struct ConvexHull {
  set<HLine> lines_;
  ConvexHull() { HLine::flag = 1; }
  void Init() { lines_.clear(); }
  void Insert(int64_t a, int64_t b) {
    HLine now = {a, b, -kInf, kInf};
    if (lines_.empty()) {
      lines_.insert(now);
      return;
    }
    HLine::flag = 1;
    auto it = lines_.lower_bound(now);
    auto prv =
      (it == lines_.begin()) ? it : prev(it);
    if (it != lines_.end()) {
      if (it == lines_.begin() && it->a == now.a)
        return;
      double x = it->l;
      if (it != lines_.begin() &&
        now(x) <= (*it)(x))
        return;
    }
    if (it !=
      lines_.begin()) {  // erase previous lines
      for (; prv != lines_.begin() &&
           (*prv)(prv->l) <= now(prv->l);)
        prv = --lines_.erase(prv);
      if (prv == lines_.begin() && now.a == prv->a)
        lines_.erase(prv);
    }
    if (it !=
      lines_.end()) {  // erase following lines
      while (it != --lines_.end() &&
        (*it)(it->r) <= now(it->r))
        it = lines_.erase(it);
    }
    if (it != lines_.begin()) {
      prv = prev(it);
      double x = Intersect(*prv, now);
      const_cast<HLine*>(&*prv)->r = now.l = x;
    }
    if (it != lines_.end()) {
      double x = Intersect(now, *it);
      const_cast<HLine*>(&*it)->l = now.r = x;
    }
    lines_.insert(now);
  }
  double Query(double a) {
    if (lines_.empty()) return -kInf;
    HLine::flag = 0;
    auto it = --lines_.upper_bound({0, 0, a, 0});
    return (*it)(a);
  }
};
