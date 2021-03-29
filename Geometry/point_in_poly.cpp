#include <bits/stdc++.h>
using namespace std;
constexpr int kN = int(1E5 + 10);
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

bool InPolygon(P p, vector<P> &v) {
  bool f = false;
  int n = int(v.size());
  for (int i = 0, j = n - 1; i < n; j = i++)
    if ((dcmp(v[i].y - p.y) > 0 !=
          dcmp(v[j].y - p.y) > 0) &&
      dcmp(p.x -
        (p.y - v[i].y) * (v[i].x - v[j].x) /
          (v[i].y - v[j].y) -
        v[i].x) < 0)
      f = !f;
  return f;
}

bool OnPolygon(P p, vector<P> &v) {
	int n = int(v.size());
	for (int i = 1; i < n; i++) if (onsegment(p, v[i - 1], v[i])) return true;
	return onsegment(p, v[0], v[n - 1]);
}

int main() {
	int n, x, y, q;
	vector<P> v;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &x, &y);
		v.push_back(P(x, y));
	}
	scanf("%d", &q);
	for (int i = 1; i <= q; i++) {
		scanf("%d%d", &x, &y);
		if (OnPolygon(P(x, y), v)) printf("1\n");
		else if (InPolygon(P(x, y), v)) printf("2\n");
		else printf("0\n");
	}
}
