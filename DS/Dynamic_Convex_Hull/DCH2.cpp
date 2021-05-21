struct HLine {
	static bool flag;
	long long int a, b;
	double l, r;
	double operator ()(double x) const {return double(a) * x + double(b);}
	bool operator < (const HLine& rhs) const {return flag ? a < rhs.a : l < rhs.l;}
};

double Intersect(HLine p, HLine q) {return double(q.b - p.b) / double(p.a - q.a);}
bool HLine::flag = true;

struct DCH {
	constexpr static double kInf = 1e16;
	set<HLine> lines_;
	DCH() {HLine::flag = true;}
	void init() {lines_.clear();}
	void insert(long long int a, long long int b) {
		HLine now = {a, b, -kInf, kInf};
		if (lines_.empty()) {
			lines_.insert(now);
			return ;
		}
		HLine::flag = true;
		auto it = lines_.lower_bound(now);
		auto prv = (it == lines_.begin()) ? it : prev(it);
		if (it != lines_.end()) {
			if (it == lines_.begin() && it -> a == now.a) {
				if (it -> b >= now.b) return ;
				else it = lines_.erase(it);
			}
			double x = it -> l;
			if (it != lines_.begin() && now(x) <= (*it)(x)) return ;
		}
		if (it != lines_.begin()) {
			for (; prv != lines_.begin() && (*prv)(prv -> l) <= now(prv -> l);)
				prv = --lines_.erase(prv);
		}
		if (it != lines_.end()) {
			while (it != --lines_.end() && (*it)(it -> r) <= now(it -> r)) it = lines_.erase(it);
		}
		if (it != lines_.begin()) {
			prv = prev(it);
			double x = Intersect(*prv, now);
			const_cast<HLine*>(&*prv) -> r = now.l = x;
		}
		if (it != lines_.end()) {
			double x = Intersect(now, *it);
			const_cast<HLine*>(&*it) -> l = now.r = x;
		}
		lines_.insert(now);
	}
	long long int operator ()(double a) {
		if (lines_.empty()) return -kInf;
		HLine::flag = 0;
		auto it = --lines_.upper_bound({0, 0, a, 0});
		return (long long int)((*it)(a));
	}
};
