#include <bits/stdc++.h>
using namespace std;
constexpr double kEps = 1E-10;
const double kPi = 4 * atan(1);
int dcmp(double x) {
  if (fabs(x) < kEps) return 0;
  return x < 0 ? -1 : 1;
}
bool same(double a, double b) {
  return dcmp(a - b) == 0;
}
struct P {
  double x, y;
  P(double x = 0, double y = 0) : x(x), y(y) {}
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
  P dis(P p) {
    return ((pb - pa) ^ (p - pa)) /
      (pb - pa).abs();
  }  // directed distance
};
struct Circle {
  P c;
  double r;
  Circle(P c, double r = 0) : c(c), r(r) {}
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
double Area(vector<P> &p) {
  double res = 0;
  for (int i = 1; i < int(p.size()) - 1; i++)
    res += (p[i] - p[0]) ^ (p[i + 1] - p[0]);
  return res * 0.5;
}
// p should be sorted increasingly according
// to the x-coordinates.
double Dis(P a, P b) { return (a - b).abs(); }
double ClosestPair(P *p, int l, int r) {
  if (l == r) return 1E9;
  if (r - l == 1) return Dis(p[l], p[r]);
  int m = (l + r) >> 1;
  double d = min(ClosestPair(p, l, m),
    ClosestPair(p, m + 1, r));
  vector<int> vec;
  for (int i = m;
       i >= l && abs(p[m].x - p[i].x) < d; i--)
    vec.push_back(i);
  for (int i = m + 1;
       i <= r && abs(p[m].x - p[i].x) < d; i++)
    vec.push_back(i);
  sort(vec.begin(), vec.end(),
    [&](int a, int b) { return p[a].y < p[b].y; });
  for (int i = 0; i < int(vec.size()); ++i) {
    for (int j = i + 1; j < int(vec.size()) &&
         abs(p[vec[j]].y - p[vec[i]].y) < d;
         ++j) {
      d = min(d, Dis(p[vec[i]], p[vec[j]]));
    }
  }
  return d;
}
int main() {
  cin.tie(nullptr),
    ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<P> p(n);
  for (int i = 0; i < n; i++)
    cin >> p[i].x >> p[i].y;
  sort(p.begin(), p.end(),
    [&](auto a, auto b) { return a.x < b.x; });
  cout << fixed << setprecision(10)
       << ClosestPair(p.data(), 0, n - 1) << '\n';
}
