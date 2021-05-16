// range add, max
template <typename T> struct seg_tree_max {
	static constexpr T kInf = numeric_limits<T>::max() / 2 - 10;
	private :
	int _size;
	T *val, *flag;

	void addtag(int n, T x) {
		val[n] += x;
		flag[n] += x;
		return ;
	}
	void push(int n) {
		if (flag[n]) {
			addtag(n << 1, flag[n]);
			addtag(n << 1 | 1, flag[n]);
			flag[n] = 0;
		}
		return ;
	}
	void pull(int n) {
		val[n] = max(val[n << 1], val[n << 1 | 1]);
		return ;
	}

	void init(int n, int l, int r) {
		val[n] = -kInf;
		flag[n] = 0;
		if (l < r) {
			int mid = (l + r) >> 1;
			init(n << 1, l, mid);
			init(n << 1 | 1, mid + 1, r);
		}
		return ;
	}

	void init(int n, int l, int r, T *v) {
		flag[n] = 0;
		if (l == r) val[n] = v[l];
		else {
			int mid = (l + r) >> 1;
			init(n << 1, l, mid, v);
			init(n << 1 | 1, mid + 1, r, v);
			pull(n);
		}
		return ;
	}

	void set(int n, int l, int r, int pos, T x) {
		if (l == r) val[n] = x;
		else {
			int mid = (l + r) >> 1;
			push(n);
			if (pos <= mid) set(n << 1, l, mid, pos, x);
			else set(n << 1 | 1, mid + 1, r, pos, x);
			pull(n);
		}
		return ;
	}
	void add(int n, int l, int r, int L, int R, T x) {
		if (L <= l && r <= R) addtag(n, x);
		else if (!(L > r || l > R)) {
			int mid = (l + r) >> 1;
			push(n);
			add(n << 1, l, mid, L, R, x);
			add(n << 1 | 1, mid + 1, r, L, R, x);
			pull(n);
		}
		return ;
	}
	void fix(int n, int l, int r, int pos, T x) {
		chmax(val[n], x);
		if (l < r) {
			int mid = (l + r) >> 1;
			push(n);
			if (pos <= mid) fix(n << 1, l, mid, pos, x);
			else fix(n << 1 | 1, mid + 1, r, pos, x);
		}
		return ;
	}

	T ask(int n, int l, int r, int pos) {
		if (l == r) return val[n];
		else {
			int mid = (l + r) >> 1;
			push(n);
			if (pos <= mid) return ask(n << 1, l, mid, pos);
			else return ask(n << 1 | 1, mid + 1, r, pos);
		}
	}
	T ask(int n, int l, int r, int L, int R) {
		if (L <= l && r <= R) return val[n];
		else if (l > R || L > r) return -kInf;
		else {
			int mid = (l + r) >> 1;
			push(n);
			return max(ask(n << 1, l, mid, L, R), ask(n << 1 | 1, mid + 1, r, L, R));
		}
	}

	public:
	seg_tree_max() : _size(0), val(nullptr), flag(nullptr) {}
	void init(int n) {
		delete [] val; val = new T [n << 2];
		delete [] flag; flag = new T [n << 2];
		return init(1, 1, _size = n);
	}
	void init(int n, T *v) {
		delete [] val; val = new T [n << 2];
		delete [] flag; flag = new T [n << 2];
		return init(1, 1, _size = n, v);
	}
	void set(int pos, T x) {return set(1, 1, _size, pos, x);}
	void add(int L, int R, T x) {return add(1, 1, _size, L, R, x);}
	void fix(int pos, T x) {return fix(1, 1, _size, pos, x);}
	T ask(int pos) {return ask(1, 1, _size, pos);}
	T ask(int L, int R) {return ask(1, 1, _size, L, R);}
	T top() const {return val[1];}
};

