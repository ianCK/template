// 0-based
struct Undoable_DSU {
	vector<pair<int, int>> opers;
	int *p;
	int size; 

	Undoable_DSU() {p = nullptr; size = 0;}

	void init(int n) {
		size = n;
		delete [] p; p = new int[size];
		memset(p, -1, sizeof(int) * size);
		opers.clear();
		return ;
	}

	int Find(int n) {
		if (p[n] < 0) return n;
		else {
			opers.push_back(make_pair(n, p[n]));
			return p[n] = Find(p[n]);
		}
	}

	inline int union_size(int n) const {return -p[n];}
	inline bool same(int l, int r) {return Find(l) == Find(r);}

	bool Merge(int l, int r) {
		l = Find(l), r = Find(r);
		if (l != r) {
			if (p[l] > p[r]) swap(l, r);
			opers.push_back(make_pair(l, p[l]));
			opers.push_back(make_pair(r, p[r]));
			p[l] += p[r];
			p[r] = l;
			return true;
		}
		else return false;
	}

	inline int cur_time() const {return int(opers.size());}
	void Undo_to_time(int t) {
		int _cur_time = cur_time();
		while (_cur_time-- > t) p[opers[_cur_time].F] = opers[_cur_time].S;
		opers.resize(t);
		return ;
	}
};
