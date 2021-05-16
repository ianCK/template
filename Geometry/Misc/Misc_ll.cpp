using ll = long long int;
struct Point {
	ll x, y;
	Point() {}
	Point(ll xx, ll yy) {x = xx, y = yy;}
	Point operator + (const Point &b) const {return Point(x + b.x, y + b.y);}
	Point operator - (const Point &b) const {return Point(x - b.x, y - b.y);}
	Point operator * (const ll &b) const {return Point(x * b, y * b);}
	ll operator * (const Point &b) const {return x * b.x + y * b.y;}  // Dot
	ll operator ^ (const Point &b) const {return x * b.y - y * b.x;}  // Cross
	bool operator < (const Point &b) const {return x < b.x || (x == b.x && y < b.y);}
	bool operator == (const Point &b) const {return x == b.x && y == b.y;} 
	bool operator != (const Point &b) const {return x != b.x || y != b.y;}
	Point operator += (const Point &b) {return *this = *this + b;}
	Point operator -= (const Point &b) {return *this = *this - b;}
	Point operator *= (const ll &b) {return *this = *this * b;}
	void in() {
		scanf("%lld%lld", &x, &y);
		return ;
	}
	void out() { // for debug
		printf("Point = (%lld, %lld)\n", x, y);
		return ;
	}
};

struct Sort_By_Angle {
	bool operator ()(const Point &lhs, const Point &rhs) const {
		return atan2(lhs.y, lhs.x) < atan2(rhs.y, rhs.x);
	}
};

/*
struct Line {
	// ax + by + c = 0
	ll a, b, c, theta;
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
	ll get_ratio(Point p) {return (p - pa) * (pb - pa) / ((pb - pa).abs() * (pb - pa).abs());}
	ll dis(Point p) {return ((pb - pa) ^ (p - pa)) / (pb - pa).abs();}  // directed distance
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
*/
ll integral_points_online(Point pa, Point pb) {
	Point diff = pa - pb;
	return gcd(ll(diff.x), ll(diff.y));
}
