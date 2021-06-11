// range set, add, max
template <typename T> struct seg_tree_max {
	static constexpr T kInf = numeric_limits<T>::max() / 2 - 10;
	private :
	int _size;
	T *_val, *_set_flag, *_add_flag;
	vector<bool> _has_set_flag;

	void addtag(int n, T x) {
		_val[n] += x;
		_add_flag[n] += x;
		return ;
	}
	void settag(int n, T x) {
		_val[n] = x;
		_set_flag[n] = x;
		_add_flag[n] = 0;
		_has_set_flag[n] = true;
		return ;
	}
	void push(int n) {
		if (_has_set_flag[n]) {
			settag(n << 1, flag[n]);
			settag(n << 1 | 1, flag[n]);
			has_flag[n] = false;
		}
		if (_add_flag[n]) {
			addtag(n << 1, flag[n]);
			addtag(n << 1 | 1, flag[n]);
			_add_flag[n] = 0;
		}
		return ;
	}
	void pull(int n) {
		_val[n] = max(_val[n << 1], _val[n << 1 | 1]);
		return ;
	}

	void init(int n, int l, int r) {
		_val[n] = -kInf;
		_has_set_flag[n] = false;
		_add_flag[n] = 0;
		if (l < r) {
			int mid = (l + r) >> 1;
			init(n << 1, l, mid);
			init(n << 1 | 1, mid + 1, r);
		}
		return ;
	}

	void init(int n, int l, int r, T *v) {
		_has_set_flag[n] = false;
		_add_flag[n] = 0;
		if (l == r) _val[n] = v[l];
		else {
			int mid = (l + r) >> 1;
			init(n << 1, l, mid, v);
			init(n << 1 | 1, mid + 1, r, v);
			pull(n);
		}
		return ;
	}

	void set(int n, int l, int r, int pos, T x) {
		if (l == r) _val[n] = x;
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
		if (L <= l && r <= R) settag(n, x);
		else if (!(l > R || L > r)) {
			int mid = (l + r) >> 1;
			push(n);
			set(n << 1, l, mid, L, R, x);
			set(n << 1 | 1, mid + 1, r, L, R, x);
			pull(n);
		}
		return ;
	}

	void add(int n, int l, int r, int pos, T x) {
		if (l == r) _val[n] += x;
		else {
			int mid = (l + r) >> 1;
			push(n);
			if (pos <= mid) add(n << 1, l, mid, pos, x);
			else add(n << 1 | 1, mid + 1, r, pos, x);
			pull(n);
		}
		return ;
	}
	void add(int n, int l, int r, int L, int R, T x) {
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
		if (l == r) return _val[n];
		else {
			int mid = (l + r) >> 1;
			push(n);
			if (pos <= mid) return ask(n << 1, l, mid, pos);
			else return ask(n << 1 | 1, mid + 1, r, pos);
		}
	}
	T ask(int n, int l, int r, int L, int R) {
		if (L <= l && r <= R) return _val[n];
		else if (l > R || L > r) return -kInf;
		else {
			int mid = (l + r) >> 1;
			push(n);
			return max(ask(n << 1, l, mid, L, R), ask(n << 1 | 1, mid + 1, r, L, R));
		}
	}

	public:
	seg_tree_max() : _size(0), _val(nullptr), _add_flag(nullptr), _set_flag(nullptr) {}
	void init(int n) {
		delete [] _val; _val = new T [n << 2];
		delete [] _add_flag; _add_flag = new T [n << 2];
		delete [] _set_flag; _set_flag = new T [n << 2];
		_has_set_flag.resize(n << 2);
		return init(1, 1, _size = n);
	}
	void init(int n, T *v) {
		delete [] _val; _val = new T [n << 2];
		delete [] _add_flag; _add_flag = new T [n << 2];
		delete [] _set_flag; _set_flag = new T [n << 2];
		_has_set_flag.resize(n << 2);
		return init(1, 1, _size = n, v);
	}
	void set(int pos, T x) {return set(1, 1, _size, pos, x);}
	void set(int L, int R, T x) {return set(1, 1, _size, L, R, x);}
	void add(int pos, T x) {return add(1, 1, _size, pos, x);}
	void add(int L, int R, T x) {return add(1, 1, _size, L, R, x);}
	T ask(int pos) {return ask(1, 1, _size, pos);}
	T ask(int L, int R) {return ask(1, 1, _size, L, R);}
	T top() const {return val[1];}
};

