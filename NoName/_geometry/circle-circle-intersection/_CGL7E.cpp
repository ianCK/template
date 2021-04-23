#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-6;
int dcmp(long double x) {
  if (fabs(x) < eps) return 0;
  return x < 0 ? -1 : 1;
}
bool same(long double a, long double b) {
  return dcmp(a - b) == 0;
}
#define Vector P
struct P {
  long double x, y;
  P(long double x = 0, long double y = 0)
      : x(x), y(y) {}
  P operator+(P b) { return P(x + b.x, y + b.y); }
  P operator-(P b) { return P(x - b.x, y - b.y); }
  P operator*(long double b) {
    return P(x * b, y * b);
  }
  P operator/(long double b) {
    return P(x / b, y / b);
  }
  long double operator*(P b) {
    return x * b.x + y * b.y;
  }  // Dot
  long double operator^(P b) {
    return x * b.y - y * b.x;
  }  // Cross
  long double abs() { return hypot(x, y); }
  P unit() { return *this / abs(); }
  P spin(long double o) {
    long double c = cos(o), s = sin(o);
    return P(c * x - s * y, s * x + c * y);
  }
};
struct Line {
  // ax + by + c = 0
  long double a, b, c, theta;
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
  long double get_ratio(P p) {
    return (p - pa) * (pb - pa) /
      ((pb - pa).abs() * (pb - pa).abs());
  }
  P dis(P p) {
    return ((pb - pa) ^ (p - pa)) /
      (pb - pa).abs();
  }  // directed distance
};
struct Circle {
  P c;
  long double r;
  Circle(P c, long double r = 0) : c(c), r(r) {}
};
bool onsegment(P p, P a, P b) {
  return dcmp((a - p) ^ (b - p)) == 0 &&
    dcmp((a - p) * (b - p)) <= 0;
}
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
long double Area(vector<P> &p) {
  long double res = 0;
  for (int i = 1; i < (int)p.size() - 1; i++)
    res += (p[i] - p[0]) ^ (p[i + 1] - p[0]);
  return res * 0.5;
}
vector<P> Intersect(Circle a, Circle b) {
  if (a.r > b.r) swap(a, b);
  long double d = (a.c - b.c).abs();
  vector<P> ps;
  if (same(a.r + b.r, d))
    ps.push_back(a.c + (b.c - a.c).unit() * a.r);
  else if (a.r + b.r > d && d + a.r >= b.r) {
    long double o =
      acos((a.r * a.r + d * d - b.r * b.r) /
        (2.0 * a.r * d));
    P t = (b.c - a.c).unit();
    ps.push_back(a.c + t.spin(o) * a.r);
    ps.push_back(a.c + t.spin(-o) * a.r);
  }
  return ps;
}
long double IntersectArea(Circle a, Circle b) {
  if (a.r > b.r) swap(a, b);
  long double d = (a.c - b.c).abs();
  if (d >= a.r + b.r - eps) return 0;
  if (d + a.r <= b.r + eps)
    return a.r * a.r * acos(-1);
  long double p =
    acos((a.r * a.r + d * d - b.r * b.r) /
      (2.0 * a.r * d));
  long double q =
    acos((b.r * b.r + d * d - a.r * a.r) /
      (2.0 * b.r * d));
  return p * a.r * a.r -
    sin(p) * cos(p) * a.r * a.r + q * b.r * b.r -
    sin(q) * cos(q) * b.r * b.r;
}
int main() {
  long double x1, y1, r1, x2, y2, r2;
  while (cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2) {
    Circle c1(P(x1, y1), r1);
    Circle c2(P(x2, y2), r2);
    auto v = Intersect(c1, c2);
    if (v.size() == 1) v.push_back(v[0]);
    if (dcmp(v[0].x - v[1].x) == 1 ||
      (dcmp(v[0].x - v[1].x) == 0 &&
        v[0].y > v[1].y))
      swap(v[0], v[1]);
    cout << fixed << setprecision(30);
    cout << v[0].x << ' ' << v[0].y << ' '
         << v[1].x << ' ' << v[1].y << '\n';
  }
}
