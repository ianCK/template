// Replace hypot with sqrt for better performance
// but worse accuracy
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
  P() = default;
  P(double x_, double y_) : x(x_), y(y_) {}
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
  double a = 0, b = 0, c = 0, theta = 0;
  P pa{}, pb{};
  Line() = default;
  Line(P pa_, P pb_)
      : a(pa_.y - pb_.y), b(pb_.x - pa_.x),
        c(pa_ ^ pb_), theta(atan2(-a, b)), pa(pa_),
        pb(pb_) {}
  P projection(P p) const {
    return pa +
      (pb - pa).unit() *
      ((pb - pa) * (p - pa) / (pb - pa).abs());
  }
  P reflection(P p) const {
    return p + (projection(p) - p) * 2;
  }
  double get_ratio(P p) const {
    return (p - pa) * (pb - pa) /
      ((pb - pa).abs() * (pb - pa).abs());
  }
  double dis(P p) const {
    return ((pb - pa) ^ (p - pa)) /
      (pb - pa).abs();
  }  // directed distance
};
struct Circle {
  P c{};
  double r{};
  Circle() = default;
  Circle(P c_, double r_) : c(c_), r(r_) {}
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
double Area(const vector<P> &p) {
  double res = 0;
  for (int i = 1; i < int(p.size()) - 1; i++)
    res += (p[i] - p[0]) ^ (p[i + 1] - p[0]);
  return res * 0.5;
}
