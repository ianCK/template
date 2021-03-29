// 0-base
struct DSU {
	int *p;
	int size;
	
	DSU() {p = nullptr;}
	
	void init(int n) {
		size = n;
		delete [] p; p = new int[n];
		memset(p, -1, sizeof(int) * n);
		return ;
	}

	int Find(int n) {return p[n] < 0 ? n : p[n] = Find(p[n]);}

	inline int union_size(int n) const {return -p[n];}
	inline bool same(int l, int r) {return Find(l) == Find(r);}

	bool Merge(int l, int r) {
		l = Find(l), r = Find(r);
		if (l != r) {
			if (p[l] > p[r]) swap(l, r);
			p[l] += p[r];
			p[r] = l;
			return true;
		}
		else return false;
	}
};
