struct DCH {
	static constexpr long long int kInf = 0x3f3f3f3f3f3f3f3f;
	struct Line {
		static bool flag;
		long long int a, b;
		mutable long long int l;
		Line() {}
		Line(long long int _a, long long int _b, long long int _l = -kInf) : a(_a), b(_b), l(_l) {}
		Line(const Line &rhs) : a(rhs.a), b(rhs.b), l(rhs.l) {}
		bool operator < (const Line &rhs) const {return flag ? a < rhs.a : l < rhs.l;}
		long long int operator () (long long int x) const {return a * x + b;}
	};

	static inline long long int intersect(const Line &l, const Line &r) {return (long long int)floor(double(l.b - r.b) / (r.a - l.a));}

	set<Line> lines;
	DCH() {}
	void init() {return lines.clear();}

	void insert(Line l) {
		Line::flag = true;
		set<Line>::iterator u = lines.lower_bound(l);

		for (; u != lines.end(); u = lines.lower_bound(l)) {
			long long int x = intersect(l, *u);

			if (x < u -> l) break;
			else if (next(u) == lines.end() || x + 1 < next(u) -> l) {
				u -> l = x + 1;
				break;
			}
			else lines.erase(u);
		}

		for (; u != lines.begin(); u = lines.lower_bound(l)) {
			u = prev(u);

			long long int x = intersect(*u, l);

			if (x < u -> l) lines.erase(u);
			else {
				l.l = x + 1;
				u = next(u);
				break;
			}
		}

		if (u == lines.end() || l.l < u -> l) lines.insert(l);
		return ;
	}

	void insert(long long int a, long long int b) {return insert(Line(a, b));}

	long long int operator () (long long int x) {
		Line::flag = false;
		return (*prev(lines.upper_bound(Line(kInf, kInf, x))))(x);
	}
};
bool DCH::Line::flag = false;
