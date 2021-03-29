template <typename T> Segment_Tree {
	vector<T> val;
	int sz;
	void init(int n) {
		sz = n;
		val.resize(sz << 2);
		return ;
	}
	void addtag(int n, T x) {
	}
	void push(int n) {
	}
	void pull(int n) {
	}
	void range_add(int n, int l, int r, int L, int R, T x) {
	
	}
	T range_sum(int n, int l, int r, int L, int R, T x) {
	
	}

	
	void add(int L, int R, T x) {
		range_add(1, 1, sz, L, R, x);
		return ;
	}
	T ask(int L, int R) {
		return range_sum(1, 1, sz, L, R);
	}
};
