// Tested
// Maintain range sum
// Lower_bound, Upper_bound
// size = 12n (could be modified to 8n)
template <typename T, int size> struct seg_tree {
	int Lbound, Rbound;
	ll val[size << 2], flag[size << 2], len[size << 2];
	inline void addtag(int n, ll x) {
		flag[n] += x;
		val[n] += x * len[n];
		return ;
	}
	inline void push(int n) {
		if (flag[n]) {
			addtag(n << 1, flag[n]);
			addtag(n << 1 | 1, flag[n]);
			flag[n] = 0;
		}
		return ;
	}
	inline void pull(int n) {
		val[n] = val[n << 1] + val[n << 1 | 1];
		return ;
	}

	void _init(int n, int l, int r) {
		len[n] = r - l + 1;
		if (l < r) {
			int mid = (l + r) >> 1;
			_init(n << 1, l, mid), _init(n << 1 | 1, mid + 1, r);
		}
		return ;
	}
	template <typename T> void _init_arr(int n, int l, int r, T a[]) {
		val[n] = a[l];
		len[n] = r - l + 1;
		if (l < r) {
			int mid = (l + r) >> 1;
			_init_arr(n << 1, l, mid), _init_arr(n << 1 | 1, mid + 1, r);
			pull(n);
		}
		return ;
	}

	void _add_single(int n, int l, int r, int pos, ll x) {
		val[n] += x;
		if (l < r) {
			int mid = (l + r) >> 1;
			push(n);
			if (pos <= mid) _add_single(n << 1, l, mid, pos, x);
			else _add_single(n << 1 | 1, mid + 1, r, pos, x);
		}
		return ;
	}
	void _add(int n, int l, int r, int L, int R, ll x) {
		if (L <= l && r <= R) addtag(n, x);
		else { 
			int mid = (l + r) >> 1;
			push(n);
			if (L <= mid) _add(n << 1, l, mid, L, R, x);
			if (R > mid) _add(n << 1 | 1, mid + 1, r, L, R, x);
			pull(n);
		}
		return ;
	}

	void _set(int n, int l, int r, int pos, ll x) {
		if (l == r) val[n] = x;
		else {
			int mid = (l + r) >> 1;
			push(n);
			if (pos <= mid) _set(n << 1, l, mid, pos, x);
			else _set(n << 1 | 1, mid + 1, r, pos, x);
			pull(n);
		}
		return ;
	}

	ll _ask(int n, int l, int r, int pos) {
		if (l == r) return val[n];
		else {
			int mid = (l + r) >> 1;
			push(n);
			if (pos <= mid) return _ask(n << 1, l, mid, pos);
			else return _ask(n << 1 | 1, mid + 1, r, pos);
		}
	}
	ll _sum(int n, int l, int r, int L, int R) {
		if (L <= l && r <= R) return val[n];
		else {
			int mid = (l + r) >> 1;
			ll ans = 0;
			push(n);
			if (L <= mid) ans += _sum(n << 1, l, mid, L, R);
			if (R > mid) ans += _sum(n << 1 | 1, mid + 1, r, L, R);
			return ans;
		}
	}

	int _lower_bound(int n, int l, int r, ll x) {
		if (l == r) return l;
		else {
			int mid = (l + r) >> 1;
			push(n);
			if (val[n << 1] < x) return _lower_bound(n << 1 | 1, mid + 1, r, x - val[n << 1]);
			else return _lower_bound(n << 1, l, mid, x);
		}
	}
	int _upper_bound(int n, int l, int r, ll x) {
		if (l == r) return l;
		else {
			int mid = (l + r) >> 1;
			push(n);
			if (val[n << 1] <= x) return _upper_bound(n << 1 | 1, mid + 1, r, x - val[n << 1]);
			else return _upper_bound(n << 1, l, mid, x);
		}
	}

	seg_tree() {}

	inline void init(int l, int r) {
		Lbound = l, Rbound = r;
		memset(val, 0, sizeof(ll) * (Rbound - Lbound + 1) << 2);
		memset(flag, 0, sizeof(ll) * (Rbound - Lbound + 1) << 2);
		return _init(1, Lbound, Rbound);
	}
	template <typename T> inline void init_arr(int l, int r, T a[]) {
		Lbound = l, Rbound = r; 
		memset(flag, 0, sizeof(ll) * (Rbound - Lbound + 1) << 2);
		return _init_arr(1, Lbound, Rbound, a);
	}
	
	inline void add_single(int pos, ll x) {return _add_single(1, Lbound, Rbound, pos, x);}
	inline void add(int l, int r, ll x) {return _add(1, Lbound, Rbound, l, r, x);}

	inline void set(int pos, ll x) {return _set(1, Lbound, Rbound, pos, x);}
	
	inline ll sum_all() const {return val[1];}

	inline ll ask(int pos) {return _ask(1, Lbound, Rbound, pos);}
	inline ll sum(int l, int r) {return _sum(1, Lbound, Rbound, l, r);}

	inline int lower_bound(ll x) {
		if (val[1] < x) return Rbound + 1;
		else return _lower_bound(1, Lbound, Rbound, x);
	}
	inline int upper_bound(ll x) {
		if (val[1] <= x) return Rbound + 1;
		else return _upper_bound(1, Lbound, Rbound, x);
	}

	struct _single_token {
		seg_tree *sg;
		int pos;
		_single_token(seg_tree *pointer, int x) {
			sg = pointer;
			pos = x;
		}
		operator ll() const {return sg -> ask(pos);}
		void operator ++ () const {return sg -> add_single(pos, 1);}
		void operator -- () const {return sg -> add_single(pos, -1);}
		void operator ++ (int) const {return sg -> add_single(pos, 1);}
		void operator -- (int) const {return sg -> add_single(pos, -1);}
		void operator += (ll x) const {return sg -> add_single(pos, x);}
		void operator -= (ll x) const {return sg -> add_single(pos, -x);}
		void operator = (ll x) const {return sg -> set(pos, x);}
	};
	_single_token operator [](int pos) {return _single_token(this, pos);}
	_single_token operator ()(int pos) {return _single_token(this, pos);}

	struct _token {
		seg_tree *sg;
		int l, r;
		_token(seg_tree *pointer, int L, int R) {
			sg = pointer;
			l = L;
			r = R;
		}
		operator ll() const {return sg -> sum(l, r);}
		void operator ++ () const {return sg -> add(l, r, 1);}
		void operator -- () const {return sg -> add(l, r, -1);}
		void operator ++ (int) const {return sg -> add(l, r, 1);}
		void operator -- (int) const {return sg -> add(l, r, -1);}
		void operator += (ll x) const {return sg -> add(l, r, x);}
		void operator -= (ll x) const {return sg -> add(l, r, -x);}
	};
	_token operator ()(int l, int r) {return _token(this, l, r);}
};
