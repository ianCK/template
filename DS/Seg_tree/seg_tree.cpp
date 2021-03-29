// range min
// kInf is needed
template <typename T> struct seg_tree_min {
	int sz;
	T *val;

	private:
	void _push(int n) {}
	void _pull(int n) {
		val[n] = min(val[n << 1], val[n << 1 | 1]);
		return ;
	}
	void _init(int n, int l, int r, T *a) {
		if (l == r) val[n] = a[l];
		else {
			int mid = (l + r) >> 1;
			_init(n << 1, l, mid, a), _init(n << 1 | 1, mid + 1, r, a);
			_pull(n);
		}
		return ;
	}

	void _set(int n, int l, int r, int pos, T x) {
		if (l == r) val[n] = x;
		else {
			int mid = (l + r) >> 1;
			if (pos <= mid) _set(n << 1, l, mid, pos, x);
			else _set(n << 1 | 1, mid + 1, r, pos, x);
			_pull(n);
		}
		return ;
	}

	T _ask(int n, int l, int r, int L, int R) {
		if (L <= l && r <= R) return val[n];
		else if (l > R || L > r) return kInf;
		else {
			int mid = (l + r) >> 1;
			return min(_ask(n << 1, l, mid, L, R), _ask(n << 1 | 1, mid + 1, r, L, R));
		}
	}

	public:
	void init(int size) {
		if (!size) return ;
		delete val; val = new T[((sz = size) + 10) << 2];
		memset(val, 0x3f, sizeof(T) * ((sz + 10) << 2));
		return ;
	}
	void init(int size, T *a) {
		if (!size) return ;
		delete val; val = new T[((sz = size) + 10) << 2];
		return _init(1, 1, sz, a);
	}

	void set(int pos, T x) {return _set(1, 1, sz, pos, x);}
	T ask(int l, int r) {return _ask(1, 1, sz, l, r);}
};

// range max
// set
template <typename T> struct seg_tree_max {
	int sz;
	T *val;

	private:
	void _push(int n) {}
	void _pull(int n) {
		val[n] = max(val[n << 1], val[n << 1 | 1]);
		return ;
	}
	void _init(int n, int l, int r, T *a) {
		if (l == r) val[n] = a[l];
		else {
			int mid = (l + r) >> 1;
			_init(n << 1, l, mid, a), _init(n << 1 | 1, mid + 1, r, a);
			_pull(n);
		}
		return ;
	}

	void _set(int n, int l, int r, int pos, T x) {
		if (l == r) val[n] = x;
		else {
			int mid = (l + r) >> 1;
			if (pos <= mid) _set(n << 1, l, mid, pos, x);
			else _set(n << 1 | 1, mid + 1, r, pos, x);
		}
		return ;
	}

	T _ask(int n, int l, int r, int L, int R) {
		if (L <= l && r <= R) return val[n];
		else if (l > R || L > r) return 0;
		else {
			int mid = (l + r) >> 1;
			return max(_ask(n << 1, l, mid, L, R), _ask(n << 1 | 1, mid + 1, r, L, R));
		}
	}

	public:
	void init(int size) {
		if (!size) return ;
		delete val; val = new T[((sz = size) + 10) << 2];
		memset(val, 0, sizeof(T) * ((sz + 10) << 2));
	}
	void init(int size, T *a) {
		if (!size) return ;
		delete val; val = new T[((sz = size) + 10) << 2];
		return _init(1, 1, sz, a);
	}

	void set(int pos, T x) {return _set(1, 1, sz, pos, x);}
	T ask(int l, int r) {return _ask(1, 1, sz, l, r);}
};

template <typename T> struct seg_tree_set_max {
	int sz;
	T *val;

	private:
	void _set(int n, int l, int r, int pos, T x) {
		if (l == r) val[n] = x;
		else {
			int mid = (l + r) >> 1;
			if (pos <= mid) _set(n << 1, l, mid, pos, x);
			else _set(n << 1 | 1, mid + 1, r, pos, x);
		}
		return ;
	}
	void _fix(int n, int l, int r, int L, int R, T x) {
		if (L <= l && r <= R) val[n] = max(val[n], x);
		else if (!(l > R || L > r)) {
			int mid = (l + r) >> 1;
			_fix(n << 1, l, mid, L, R, x);
			_fix(n << 1 | 1, mid + 1, r, L, R, x);
		}
		return ;
	}
	T _ask(int n, int l, int r, int pos) {
		if (l == r) return val[n];
		else {
			int mid = (l + r) >> 1;
			if (pos <= mid) return max(val[n], _ask(n << 1, l, mid, pos));
			else return max(val[n], _ask(n << 1 | 1, mid + 1, r, pos));
		}
	}

	public:
	void init(int size) {
		if (!size) return ;
		delete val; val = new T[((sz = size) + 10) << 2];
		memset(val, 0, sizeof(T) * ((sz + 10) << 2));
		return ;
	}

	void set(int pos, T x) {return _set(1, 1, sz, pos, x);}
	void fix(int l, int r, T x) {return _fix(1, 1, sz, l, r, x);}
	T ask(int pos) {return _ask(1, 1, sz, pos);}
};
