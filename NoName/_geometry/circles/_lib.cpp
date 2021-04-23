int CCPosition(Circle c1, Circle c2) {
  double d = (c1.c - c2.c).abs();
  if (dcmp(c1.r - c2.r) == -1) swap(c1, c2);
  if (dcmp((c2.r + d) - c1.r) == -1) return 0;
  if (dcmp((c2.r + d) - c1.r) == 0) return 1;
  if (dcmp((c1.r + c2.r) - d) == 1) return 2;
  if (dcmp((c1.r + c2.r) - d) == 0) return 3;
  return 4;
}
int CLPosition(
  Circle c, Line l) {  // 0: 2 intersections, 1: 1
  // intersection, 2: no intersections
  double d = abs(l.dis(c.c));
  return dcmp(d - c.r) + 1;
}
vector<Line> PCTangent(Circle c, P p) {
  double d = (p - c.c).abs();
  if (dcmp(d - c.r) == -1) return {};
  vector<Line> res;
  if (dcmp(d - c.r) == 0) {
    P i = (p - c.c).unit().spin(kPi / 2.0);
    res.push_back(Line(p, p + i));
  } else {
    double theta = acos(c.r / d);
    P i = (p - c.c).unit(),
      j = i.spin(theta) * c.r,
      k = i.spin(-theta) * c.r;
    res.push_back(Line(p, c.c + j));
    res.push_back(Line(p, c.c + k));
  }
  return res;
}
vector<Line> CCTangent(Circle c1, Circle c2) {
  if (dcmp(c1.r - c2.r) == -1) swap(c1, c2);
  int pos = CCPosition(c1, c2);
  vector<Line> res;
  if (pos > 0) {
    if (dcmp(c1.r - c2.r) == 0) {
      double r = c1.r;
      P i = (c2.c - c1.c).unit().spin(kPi / 2);
      res.push_back(
        Line(c1.c + i * r, c2.c + i * r));
      res.push_back(
        Line(c1.c - i * r, c2.c - i * r));
    } else {
      double x = (c1.r * c2.c.x - c2.r * c1.c.x) /
        (c1.r - c2.r);
      double y = (c1.r * c2.c.y - c2.r * c1.c.y) /
        (c1.r - c2.r);
      P p(x, y);
      auto tmp = PCTangent(c1, p);
      for (auto l : tmp) res.push_back(l);
    }
  }
  if (pos > 2) {
    double x = (c1.r * c2.c.x + c2.r * c1.c.x) /
      (c1.r + c2.r);
    double y = (c1.r * c2.c.y + c2.r * c1.c.y) /
      (c1.r + c2.r);
    P p(x, y);
    auto tmp = PCTangent(c1, p);
    for (auto l : tmp) res.push_back(l);
  }
  return res;
}
vector<P> CLIntersection(Circle c, Line l) {
  int pos = CLPosition(c, l);
  if (pos == 2) return {};
  else if (pos == 1) {
    return {l.projection(c.c)};
  } else {
    double d = fabs(l.dis(c.c));
    vector<P> res;
    if (dcmp(d) == 0) {
      P p =
        (l.pa - l.pb) / (l.pa - l.pb).abs() * c.r;
      res.push_back(c.c + p);
      res.push_back(c.c - p);
    } else {
      double theta = acos(d / c.r);
      P p = l.projection(c.c);
      P i = (p - c.c).unit(),
        j = i.spin(theta) * c.r,
        k = i.spin(-theta) * c.r;
      res.push_back(c.c + j),
        res.push_back(c.c + k);
    }
    return res;
  }
}
bool OnSegment(P p, P a, P b) {
  return dcmp((a - p) ^ (b - p)) == 0 &&
    dcmp((a - p) * (b - p)) <= 0;
}
double SCDistance(P p, P q, Circle c) {
  Line l(p, q);
  P r = l.projection(c.c);
  if (OnSegment(r, p, q)) return fabs(l.dis(c.c));
  else
    return min((c.c - p).abs(), (c.c - q).abs());
}
