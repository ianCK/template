constexpr double kEps = 1E-9;
const double kPi = 4 * atan(1);

int dcmp(double x) {return fabs(x) < kEps ? 0 : (x < 0 ? -1 : 1);}
bool same(double a, double b) {return dcmp(a - b) == 0;}

struct Point {
  double x, y;
	Point() {}
  Point(double xx, double yy) {x = xx, y = yy;}
  Point operator + (Point b) const {return Point(x + b.x, y + b.y);}
  Point operator - (Point b) const {return Point(x - b.x, y - b.y);}
  Point operator * (double b) const {return Point(x * b, y * b);}
  Point operator / (double b) const {return Point(x / b, y / b);}
  double operator * (Point b) const {return x * b.x + y * b.y;}  // Dot
  double operator ^ (Point b) const {return x * b.y - y * b.x;}  // Cross
  double abs() const {return hypot(x, y); }
  Point unit() const {return *this / abs(); }
  Point spin(double o) const {
    double c = cos(o), s = sin(o);
    return Point(c * x - s * y, s * x + c * y);
  }
};

struct Line {
  // ax + by + c = 0
  double a, b, c, theta;
  Point pa, pb;
  Line() : a(0), b(0), c(0), theta(0), pa(), pb() {}
  Line(Point pa, Point pb) : a(pa.y - pb.y), b(pb.x - pa.x), c(pa ^ pb), theta(atan2(-a, b)), pa(pa), pb(pb) {}
  Point projection(Point p) {return pa + (pb - pa).unit() * ((pb - pa) * (p - pa) / (pb - pa).abs());}
  Point reflection(Point p) {return p + (projection(p) - p) * 2;}
  double get_ratio(Point p) {return (p - pa) * (pb - pa) / ((pb - pa).abs() * (pb - pa).abs());}
  double dis(Point p) {return ((pb - pa) ^ (p - pa)) / (pb - pa).abs();}  // directed distance
};

struct Circle {
  Point c;
  double r;
	Circle() {}
  Circle(Point cc, double rr) {c = cc, r = rr;}
};

bool OnSegment(Point p, Point a, Point b) {
  return dcmp((a - p) ^ (b - p)) == 0 && dcmp((a - p) * (b - p)) <= 0;
}

// End points are not allowed
// Better not parallel (haven't tested)
bool segment_intersection(Point p1, Point p2, Point p3, Point p4) {  
  return dcmp((p2 - p1) ^ (p3 - p1)) * dcmp((p2 - p1) ^ (p4 - p1)) < 0 &&
    dcmp((p4 - p3) ^ (p1 - p3)) * dcmp((p4 - p3) ^ (p2 - p3)) < 0;
}

bool parallel(Line l1, Line l2) {
  return same(l1.a * l2.b, l1.b * l2.a);
}

Point line_intersection(Line l1, Line l2) {
  return Point(-l1.b * l2.c + l1.c * l2.b, l1.a * l2.c - l1.c * l2.a) / (-l1.a * l2.b + l1.b * l2.a);
}

// The Points should be in (Counter) Clockwise order
// It could be Convex or not
double Area(vector<Point> &p) { 
  double res = 0;
  for (int i = 1; i < int(p.size()) - 1; i++) res += (p[i] - p[0]) ^ (p[i + 1] - p[0]);
  return res * 0.5;
}

vector<Point> Intersect(Circle a, Circle b) { // checked
  if (a.r > b.r) swap(a, b);
  double d = (a.c - b.c).abs();
  vector<Point> ps;
  if (same(a.r + b.r, d)) ps.push_back(a.c + (b.c - a.c).unit() * a.r);
  else if (a.r + b.r > d && d + a.r >= b.r) {
    double o = acos((a.r * a.r + d * d - b.r * b.r) / (2.0 * a.r * d));
    Point t = (b.c - a.c).unit();
    ps.push_back(a.c + t.spin(o) * a.r);
    ps.push_back(a.c + t.spin(-o) * a.r);
  }
  return ps;
}

double IntersectArea(Circle a, Circle b) { // checked
  if (a.r > b.r) swap(a, b);
  double d = (a.c - b.c).abs();
  if (d >= a.r + b.r - kEps) return 0;
  if (d + a.r <= b.r + kEps) return a.r * a.r * acos(-1);
  double p = acos((a.r * a.r + d * d - b.r * b.r) / (2.0 * a.r * d));
  double q = acos((b.r * b.r + d * d - a.r * a.r) / (2.0 * b.r * d));
  return p * a.r * a.r - sin(p) * cos(p) * a.r * a.r + q * b.r * b.r - sin(q) * cos(q) * b.r * b.r;
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

// checked
// 0: 2 intersections, 1: 1 intersection, 2: no intersections
int CLPosition(Circle c, Line l) {  
  double d = abs(l.dis(c.c));
  return dcmp(d - c.r) + 1;
}

vector<Line> PCTangent(Circle c, Point p) { // checked
  double d = (p - c.c).abs();
  vector<Line> res;
  if (dcmp(d - c.r) == -1) return res;
  if (dcmp(d - c.r) == 0) {
    Point i = (p - c.c).unit().spin(kPi / 2.0);
    res.push_back(Line(p, p + i));
  } 
	else {
    double theta = acos(c.r / d);
    Point i = (p - c.c).unit(),
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
      Point i = (c2.c - c1.c).unit().spin(kPi / 2);
      res.push_back(Line(c1.c + i * r, c2.c + i * r));
      res.push_back(Line(c1.c - i * r, c2.c - i * r));
    } else {
      double x = (c1.r * c2.c.x - c2.r * c1.c.x) / (c1.r - c2.r);
      double y = (c1.r * c2.c.y - c2.r * c1.c.y) / (c1.r - c2.r);
      Point p(x, y);
      vector<Line> tmp = PCTangent(c1, p);
      for (Line l : tmp) res.push_back(l);
    }
  }
  if (pos > 2) {
    double x = (c1.r * c2.c.x + c2.r * c1.c.x) / (c1.r + c2.r);
    double y = (c1.r * c2.c.y + c2.r * c1.c.y) / (c1.r + c2.r);
    Point p(x, y);
    vector<Line> tmp = PCTangent(c1, p);
    for (Line l : tmp) res.push_back(l);
  }
  return res;
}

vector<Point> CLIntersection(Circle c, Line l) { // checked
  int pos = CLPosition(c, l);
	vector<Point> res;
  if (pos == 2) return res;
  else if (pos == 1) res.push_back(l.projection(c.c));
  else {
    double d = fabs(l.dis(c.c));
		if (dcmp(d) == 0) {
			Point p = (l.pa - l.pb) / (l.pa - l.pb).abs() * c.r;
			res.push_back(c.c + p);
			res.push_back(c.c - p);
		}
		else {
			double theta = acos(d / c.r);
			Point p = l.projection(c.c);
			Point i = (p - c.c).unit(),
				j = i.spin(theta) * c.r,
				k = i.spin(-theta) * c.r;
			res.push_back(c.c + j), res.push_back(c.c + k);
		}
	}
	return res;
}

double SCDistance(Point p, Point q, Circle c) {
  Line l(p, q);
  Point r = l.projection(c.c);
  if (OnSegment(r, p, q)) return fabs(l.dis(c.c));
  else return min((c.c - p).abs(), (c.c - q).abs());
}

vector<Point> ConvexHull(vector<Point> ps) {
  vector<Point> p;
  for (int i = 0; i < int(ps.size()); i++) {
    while (p.size() >= 2 && ((ps[i] - p[p.size() - 2]) ^ (p[p.size() - 1] - p[p.size() - 2])) > 0)
      p.pop_back();
    p.push_back(ps[i]);
  }
  int t = int(p.size());
  for (int i = int(ps.size()) - 2; i >= 0; i--) {
    while (int(p.size()) > t && ((ps[i] - p[p.size() - 2]) ^ (p[p.size() - 1] - p[p.size() - 2])) > 0)
      p.pop_back();
    p.push_back(ps[i]);
  }
  p.pop_back();
  return p;
}

// Strictly inside
bool InPolygon(Point p, vector<Point> &v) {
  bool f = false;
  int n = int(v.size());
  for (int i = 0, j = n - 1; i < n; j = i++)
    if ((dcmp(v[i].y - p.y) > 0 != dcmp(v[j].y - p.y) > 0) &&
      dcmp(p.x - (p.y - v[i].y) * (v[i].x - v[j].x) / (v[i].y - v[j].y) - v[i].x) < 0) f = !f;
  return f;
}

bool OnPolygon(Point p, vector<Point> &v) {
	int n = int(v.size());
	for (int i = 1; i < n; i++) if (onsegment(p, v[i - 1], v[i])) return true;
	return onsegment(p, v[0], v[n - 1]);
}
