using F = double;
Circle GetCircle(
  const P &a, const P &b, const P &c) {
  F a1, a2, b1, b2, c1, c2;
  Circle ret({});
  a1 = 2 * (a.x - b.x);
  a2 = 2 * (a.x - c.x);
  b1 = 2 * (a.y - b.y);
  b2 = 2 * (a.y - c.y);
  c1 =
    a.x * a.x - b.x * b.x + a.y * a.y - b.y * b.y;
  c2 =
    a.x * a.x - c.x * c.x + a.y * a.y - c.y * c.y;
  ret.c.x = (P(c1, b1) ^ P(c2, b2)) /
    (P(a1, b1) ^ P(a2, b2));
  ret.c.y = (P(a1, c1) ^ P(a2, c2)) /
    (P(a1, b1) ^ P(a2, b2));
  ret.r = (ret.c - a).abs();
  return ret;
}
Circle Update(const P *ps, int k) {
  int i, j;
  Circle ret({});
  ret.c = P((ps[k - 1].x + ps[k].x) / 2,
    (ps[k - 1].y + ps[k].y) / 2);
  ret.r = (ps[k - 1] - ps[k]).abs() / 2;
  for (i = k - 2; i >= 0; --i) {
    if (dcmp((ret.c - ps[i]).abs() - ret.r) > 0) {
      ret.c = P((ps[i].x + ps[k].x) / 2,
        (ps[i].y + ps[k].y) / 2);
      ret.r = (ps[i] - ps[k]).abs() / 2;
      for (j = i + 1; j < k; ++j) {
        if ((ps[i] - ps[j]) * (ps[k] - ps[j]) <
          kEps)
          continue;
        if (dcmp((ps[j] - ret.c).abs() - ret.r) >
          0) {
          ret = GetCircle(ps[i], ps[j], ps[k]);
        }
      }
    }
  }
  return ret;
}
Circle Solve(P *ps, int n) {
  int i;
  Circle ret({});
  if (n == 1) {
    ret.c = ps[0];
    ret.r = 0;
    return ret;
  }
  random_shuffle(ps, ps + n);
  ret.c = P((ps[0].x + ps[1].x) / 2,
    (ps[0].y + ps[1].y) / 2);
  ret.r = (ps[0] - ps[1]).abs() / 2;
  for (i = 2; i < n; ++i) {
    if (dcmp((ps[i] - ret.c).abs() - ret.r) > 0)
      ret = Update(ps, i);
  }
  return ret;
}
