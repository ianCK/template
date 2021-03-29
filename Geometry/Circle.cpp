constexpr double kEps = 1E-9;
const double kPi = 4 * atan(1);
int dcmp(double x) { // checked
  if (fabs(x) < kEps) return 0;
  return x < 0 ? -1 : 1;
}
bool same(double a, double b) {
  return dcmp(a - b) == 0;
}
struct P {
  double x, y;
	P() {}
  P(double x, double y) : x(x), y(y) {}
  P operator+(P b) const {
    return P(x + b.x, y + b.y);
  }
  P operator-(P b) const {
    return P(x - b.x, y - b.y);
  }
  P operator*(double b) const {
    return P(x * b, y * b);
  }
  P operator/(double b) const {
    return P(x / b, y / b);
  }
  double operator*(P b) const {
    return x * b.x + y * b.y;
  }  // Dot
  double operator^(P b) const {
    return x * b.y - y * b.x;
  }  // Cross
  double abs() const { return hypot(x, y); }
  P unit() const { return *this / abs(); }
  P spin(double o) const {
    double c = cos(o), s = sin(o);
    return P(c * x - s * y, s * x + c * y);
  }
};
using Vector = P;
struct Line {
  // ax + by + c = 0
  double a, b, c, theta;
  P pa, pb;
  Line()
      : a(0), b(0), c(0), theta(0), pa(), pb() {}
  Line(P pa, P pb)
      : a(pa.y - pb.y), b(pb.x - pa.x), c(pa ^ pb),
        theta(atan2(-a, b)), pa(pa), pb(pb) {}
  P projection(P p) {
    return pa +
      (pb - pa).unit() *
      ((pb - pa) * (p - pa) / (pb - pa).abs());
  }
  P reflection(P p) {
    return p + (projection(p) - p) * 2;
  }
  double get_ratio(P p) {
    return (p - pa) * (pb - pa) /
      ((pb - pa).abs() * (pb - pa).abs());
  }
  double dis(P p) {
    return ((pb - pa) ^ (p - pa)) /
      (pb - pa).abs();
  }  // directed distance
};
struct Circle {
  P c;
  double r;
	Circle() {}
  Circle(P c, double r) : c(c), r(r) {}
};
bool segment_intersection(P p1, P p2, P p3,
  P p4) {  // end points are not allowed
  return dcmp((p2 - p1) ^ (p3 - p1)) *
      dcmp((p2 - p1) ^ (p4 - p1)) <
    0 &&
    dcmp((p4 - p3) ^ (p1 - p3)) *
      dcmp((p4 - p3) ^ (p2 - p3)) <
    0;
}
bool parallel(Line l1, Line l2) {
  return same(l1.a * l2.b, l1.b * l2.a);
}
P line_intersection(Line l1, Line l2) {
  return P(-l1.b * l2.c + l1.c * l2.b,
           l1.a * l2.c - l1.c * l2.a) /
    (-l1.a * l2.b + l1.b * l2.a);
}
double Area(vector<P> &p) { // checked
  double res = 0;
  for (int i = 1; i < int(p.size()) - 1; i++)
    res += (p[i] - p[0]) ^ (p[i + 1] - p[0]);
  return res * 0.5;
}

vector<P> Intersect(Circle a, Circle b) { // checked
  if (a.r > b.r) swap(a, b);
  double d = (a.c - b.c).abs();
  vector<P> ps;
  if (same(a.r + b.r, d))
    ps.push_back(a.c + (b.c - a.c).unit() * a.r);
  else if (a.r + b.r > d && d + a.r >= b.r) {
    double o =
      acos((a.r * a.r + d * d - b.r * b.r) /
        (2.0 * a.r * d));
    P t = (b.c - a.c).unit();
    ps.push_back(a.c + t.spin(o) * a.r);
    ps.push_back(a.c + t.spin(-o) * a.r);
  }
  return ps;
}
double IntersectArea(Circle a, Circle b) { // checked
  if (a.r > b.r) swap(a, b);
  double d = (a.c - b.c).abs();
  if (d >= a.r + b.r - kEps) return 0;
  if (d + a.r <= b.r + kEps)
    return a.r * a.r * acos(-1);
  double p = acos((a.r * a.r + d * d - b.r * b.r) /
    (2.0 * a.r * d));
  double q = acos((b.r * b.r + d * d - a.r * a.r) /
    (2.0 * b.r * d));
  return p * a.r * a.r -
    sin(p) * cos(p) * a.r * a.r + q * b.r * b.r -
    sin(q) * cos(q) * b.r * b.r;
}

int CCPosition(Circle c1, Circle c2) { // checked
  double d = (c1.c - c2.c).abs();
  if (dcmp(c1.r - c2.r) == -1) swap(c1, c2);
  if (dcmp((c2.r + d) - c1.r) == -1) return 0;
  if (dcmp((c2.r + d) - c1.r) == 0) return 1;
  if (dcmp((c1.r + c2.r) - d) == 1) return 2;
  if (dcmp((c1.r + c2.r) - d) == 0) return 3;
  return 4;
}
int CLPosition( // checked
  Circle c, Line l) {  // 0: 2 intersections, 1: 1
  // intersection, 2: no intersections
  double d = abs(l.dis(c.c));
  return dcmp(d - c.r) + 1;
}
vector<Line> PCTangent(Circle c, P p) { // checked
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
vector<Line> CCTangent(Circle c1, Circle c2) { //checked
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
vector<P> CLIntersection(Circle c, Line l) { // checked
  int pos = CLPosition(c, l);
  if (pos == 2) return {};
  else if (pos == 1) {
    return {l.projection(c.c)};
  } else {
    double d = fabs(l.dis(c.c));
		vector<P> res;
		if (dcmp(d) == 0) {
			P p = (l.pa - l.pb) / (l.pa - l.pb).abs() * c.r;
			res.push_back(c.c + p);
			res.push_back(c.c - p);
		}
		else {
			double theta = acos(d / c.r);
			P p = l.projection(c.c);
			P i = (p - c.c).unit(),
				j = i.spin(theta) * c.r,
				k = i.spin(-theta) * c.r;
			res.push_back(c.c + j), res.push_back(c.c + k);
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
