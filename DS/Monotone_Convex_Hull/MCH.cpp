struct MCH {
	static constexpr long long int kInf = 0x3f3f3f3f3f3f3f3f;
	struct Line {
		long long int a, b, l;
		Line() {}
		Line(long long int _a, long long int _b, long long int _l = -kInf) : a(_a), b(_b), l(_l) {}
		Line(const Line &rhs) : a(rhs.a), b(rhs.b), l(rhs.l) {}
		bool operator < (const Line &rhs) {return a < rhs.a;}
		long long int operator () (long long int x) const {return a * x + b;}
	};

	static inline long long int intersect(const Line &l, const Line &r) {return (long long int)floor(double(l.b - r.b) / (r.a - l.a));}

	int _size;
	vector<Line> lines;
	MCH() {}
	void init() {return lines.clear();}
	void insert(Line l) {return lines.push_back(l);}
	void insert(long long int a, long long int b) {return insert(Line(a, b));}
	void build() {
		_size = int(lines.size());
		vector<Line> tmp;
		swap(tmp, lines);

		bool is_sorted = true;
		for (int i = 1; i < _size; i++) if (!(tmp[i - 1] < tmp[i])) {
			is_sorted = false;
			break;
		}

		if (!is_sorted) sort(tmp.begin(), tmp.end());

		lines.PB(tmp[0]);
		int cur_size = 1;
		for (int i = 1; i < _size; i++) {
			while (cur_size >= 2) {
				long long int x = intersect(lines[cur_size - 1], tmp[i]);
				if (x < lines[cur_size - 1].l) {
					lines.pop_back();
					cur_size--;
				}
				else break;
			}

			long long int x = intersect(lines[cur_size - 1], tmp[i]);
			tmp[i].l = x + 1;
			lines.PB(tmp[i]);
			cur_size++;
		}

		_size = cur_size;
		return ;
	}
	int size() const {return _size;}
	// void Monotone_Query() {}
	long long int Query(long long int x) const {
		int l = 0, r = _size;
		while (r - l > 1) {
			int mid = (l + r) >> 1;
			if (lines[mid].l <= x) l = mid;
			else r = mid;
		}
		return lines[l](x);
	}
	long long int operator () (long long int x) const {
		return Query(x);
	}
};

MCH Merge(const MCH &lhs, const MCH &rhs) {
	MCH ans;
	ans.lines.resize(lhs.size() + rhs.size());
	merge(lhs.lines.begin(), lhs.lines.end(), rhs.lines.begin(), rhs.lines.end(), ans.lines.begin());

	return ans;
}
