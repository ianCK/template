// range set, max
template <typename T> struct rs_min {
	static constexpr T kInf = numeric_limits<T>::max() / 2 - 10;
	private :
	int _size;
	T *val, *flag;
	vector<bool> has_flag;

	void addtag(int n, T x) {
		val[n] = x;
		flag[n] = x;
		has_flag[n] = true;
		return ;
	}
	void push(int n) {
		if (has_flag[n]) {
			addtag(n << 1, flag[n]);
			addtag(n << 1 | 1, flag[n]);
			has_flag[n] = false;
		}
		return ;
	}
	void pull(int n) {
		val[n] = min(val[n << 1], val[n << 1 | 1]);
		return ;
	}

	void init(int n, int l, int r) {
		val[n] = kInf;
		has_flag[n] = false;
		if (l < r) {
			int mid = (l + r) >> 1;
			init(n << 1, l, mid);
			init(n << 1 | 1, mid + 1, r);
		}
		return ;
	}

	void init(int n, int l, int r, T *v) {
		has_flag[n] = false;
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

	void set(int n, int l, int r, int L, int R, T x) {
		if (L <= l && r <= R) addtag(n, x);
		else if (!(l > R || L > r)) {
			int mid = (l + r) >> 1;
			push(n);
			set(n << 1, l, mid, L, R, x);
			set(n << 1 | 1, mid + 1, r, L, R, x);
			pull(n);
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
		else if (l > R || L > r) return kInf;
		else {
			int mid = (l + r) >> 1;
			push(n);
			return min(ask(n << 1, l, mid, L, R), ask(n << 1 | 1, mid + 1, r, L, R));
		}
	}

	static int need_id(int n, int l, int r) {
		if (l < r) {
			int mid = (l + r) >> 1;
			return max(need_id(n << 1, l, mid), need_id(n << 1 | 1, mid + 1, r));
		}
		else return n;
	}

	public:
	rs_min() : _size(0), val(nullptr), flag(nullptr) {}
	void init(int n) {
		int need = need_id(1, 1, n);
		delete [] val; val = new T [need + 1];
		delete [] flag; flag = new T [need + 1];
		has_flag.resize(need + 1);
		return init(1, 1, _size = n);
	}
	void init(int n, T *v) {
		int need = need_id(1, 1, n);
		delete [] val; val = new T [need + 1];
		delete [] flag; flag = new T [need + 1];
		has_flag.resize(need + 1);
		return init(1, 1, _size = n, v);
	}
	void set(int pos, T x) {return set(1, 1, _size, pos, x);}
	void set(int L, int R, T x) {return set(1, 1, _size, L, R, x);}
	T ask(int pos) {return ask(1, 1, _size, pos);}
	T ask(int L, int R) {return ask(1, 1, _size, L, R);}
	T top() const {return val[1];}
};
