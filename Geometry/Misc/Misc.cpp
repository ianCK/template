inline int dcmp(double x) {return fabs(x) < kEps ? 0 : (x < 0 ? -1 : 1);}
inline bool same(double a, double b) {return dcmp(a - b) == 0;}

struct Point {
	double x, y;
	Point() {}
	Point(double xx, double yy) {x = xx, y = yy;}
	Point operator + (const Point &b) const {return Point(x + b.x, y + b.y);}
	Point operator - (const Point &b) const {return Point(x - b.x, y - b.y);}
	Point operator * (const double &b) const {return Point(x * b, y * b);}
	Point operator / (const double &b) const {return Point(x / b, y / b);}
	double operator * (const Point &b) const {return x * b.x + y * b.y;}  // Dot
	double operator ^ (const Point &b) const {return x * b.y - y * b.x;}  // Cross
	bool operator < (const Point &b) const {
		int tmp = dcmp(x - b.x);
		if (tmp == 0) return dcmp(y - b.y) == -1;
		else return tmp == -1;
	}
	bool operator == (const Point &b) const {return same(x, b.x) && same(y, b.y);}
	bool operator != (const Point &b) const {return !(same(x, b.x) && same(y, b.y));}
	Point operator += (const Point &b) {return *this = *this + b;}
	Point operator -= (const Point &b) {return *this = *this - b;}
	Point operator *= (const double &b) {return *this = *this * b;}
	Point operator /= (const double &b) {return *this = *this / b;}
	double abs() const {return hypot(x, y); }
	Point unit() const {return *this / abs(); }
	Point spin(double o) const {
		double c = cos(o), s = sin(o);
		return Point(c * x - s * y, s * x + c * y);
	}
	void in() {
		scanf("%lf%lf", &x, &y);
		return ;
	}
	void out() { // for debug
		printf("Point = (%.20lf, %.20lf)\n", x, y);
		return ;
	}
};

struct Sort_By_Angle {
	bool operator ()(const Point &lhs, const Point &rhs) const {
		return atan2(lhs.y, lhs.x) < atan2(rhs.y, rhs.x);
	}
};

struct Line {
	// ax + by + c = 0
	double a, b, c, theta;
	Point pa, pb;
	Line() {}
	Line(Point npa, Point npb) {
		a = npa.y - npb.y;
		b = npb.x - npa.x;
		c = npa ^ npb;
		theta = atan2(-a, b);
		pa = npa;
		pb = npb;
	}
	Point projection(Point p) {return pa + (pb - pa).unit() * ((pb - pa) * (p - pa) / (pb - pa).abs());}
	Point reflection(Point p) {return p + (projection(p) - p) * 2;}
	double get_ratio(Point p) {return (p - pa) * (pb - pa) / ((pb - pa).abs() * (pb - pa).abs());}
	double dis(Point p) {return ((pb - pa) ^ (p - pa)) / (pb - pa).abs();}  // directed distance
	void out() {
		printf("Line %lf x + %lf y = %lf\n", a, b, -c);
		return ;
	}
};

struct Circle {
	Point c;
	double r;
	Circle() {}
	Circle(Point cc, double rr) {c = cc, r = rr;}
	bool operator == (Circle b) {return c == b.c && same(r, b.r);}
	void operator *= (double b) {r *= b;}
	void operator /= (double b) {r /= b;}
};

bool parallel(Line l1, Line l2) {
	return same(l1.a * l2.b, l1.b * l2.a);
}

// should not parallel
Point line_intersection(Line l1, Line l2) {
	return Point(-l1.b * l2.c + l1.c * l2.b, l1.a * l2.c - l1.c * l2.a) / (-l1.a * l2.b + l1.b * l2.a);
}

Line Perpendicular_Line(Point a, Point b) {
	return Line((a + b) / 2, (a + b) / 2 + (b - a).spin(kPi / 2));
}

int PL_Position(Point p, Line l) {
	// -1 -> left side
	// 0 -> on line
	// 1 -> right side
	return dcmp((p - l.pa) ^ (l.pb - l.pa));
}

