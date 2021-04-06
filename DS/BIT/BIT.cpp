template <typename T> struct BIT {
	int sz; // n + 1
	T* val;
	T tot;

	void init(int n) {
		delete [] val; val = new T[sz = n + 1];
		memset(val + 1, 0, sizeof(T) * n);
		tot = 0;
		return ;
	}

	void init(int n, T *a) {
		delete [] val; val = new T[sz = n + 1];
		memcpy(val + 1, a + 1, sizeof(T) * n);
		for (int i = 1; i <= n; i++) if (i + (i & -i) <= n) val[i + (i & -i)] += val[i];
		for (int i = 1; i <= n; i++) tot += a[i];
		return ;
	}

	void add(int pos, T x) {
		tot += x;
		for (int i = pos; i < sz; i += i & -i) val[i] += x;
		return ;
	}

	T ask(int pos) {
		T ans = 0;
		for (int i = pos; i; i ^= i & -i) ans += val[i];
		return ans;
	}
	T ask(int l, int r) const {return ask(r) - ask(l - 1);}

	int lower_bound(T x) const {
		int ans = 0;
		for (int i = 1 << __lg(sz - 1); i > 0; i >>= 1) 
			if (ans + i < sz && val[ans + i] < x) x -= val[ans += i];
		return ans + 1;
	}

	int upper_bound(T x) const {
		int ans = 0;
		for (int i = 1 << __lg(sz - 1); i > 0; i >>= 1) 
			if (ans + i < sz && val[ans + i] <= x) x -= val[ans += i];
		return ans + 1;
	}

	void clear() {memset(val + 1, 0, sizeof(T) * (sz - 1));}
	void clear(int pos) {for (int i = pos; i < sz; i += i & -i) val[i] = 0;}
};

template <typename T> struct BIT_max {
	int sz; // n + 1
	T* val;

	void init(int n) {
		delete val; val = new T[sz = n + 1];
		memset(val + 1, 0, sizeof(T) * n);
		return ;
	}

	void init(int n, T *a) {
		delete val; val = new T[sz = n + 1];
		memcpy(val + 1, a + 1, sizeof(T) * n);
		for (int i = 1; i <= n; i++) if (i + (i & -i) <= n) chmax(val[i + (i & -i)], val[i]);
		return ;
	}

	void fix(int pos, T x) {for (int i = pos; i < sz; i += i & -i) chmax(val[i], x);}

	T ask(int pos) const {
		T ans = 0;
		for (int i = pos; i; i ^= i & -i) chmax(ans, val[i]);
		return ans;
	}

	void clear() {memset(val + 1, 0, sizeof(T) * (sz - 1));}
};

template <typename T> struct BIT_2D {
	int sz;
	vector<vector<T>> val;

	void init(int size) {
		sz = size + 1;
		val.resize(sz);
		for (int i = 0; i < sz; i++) val[i].resize(sz);
		for (int i = 0; i < sz; i++) for (int j = 0; j < sz; j++) val[i][j] = 0;
		//delete val; val = new T[sz][sz];
		//memset(val, 0, sizeof(T) * sz * sz);
		return ;
	}

	void add(int x, int y, T v) {
		while (x < sz) {
			int ty = y;
			while (ty < sz) {
				val[x][ty] += v;
				ty += ty & -ty;
			}
			x += x & -x;
		}
		return ;
	}

	T ask(int x, int y) const {
		T ans = 0;
		while (x) {
			int ty = y;
			while (ty) {
				ans += val[x][ty];
				ty ^= ty & -ty;
			}
			x ^= x & -x;
		}
		return ans;
	}
	T ask(int x1, int y1, int x2, int y2) const {return ask(x2, y2) - ask(x1 - 1, y2) - ask(x2, y1 - 1) + ask(x1 - 1, y1 - 1);}

	void clear() {
		memset(val, 0, sizeof(T) * sz);
		return ;
	}

	void clear(int x, int y) {
		while (x < sz) {
			int ty = y;
			while (ty < sz) {
				val[x][ty] = 0;
				ty += ty & -ty;
			}
			x += x & -x;
		}
		return ;
	}
};

/*
	 template <typename T> struct BIT_MIN {
	 constexpr static bool reverse = false;
	 constexpr static T I = numeric_limits<T>::max();
	 constexpr static bool compare = true;
	 static T op(T a, T b) {return min(a, b);}
	 static bool lower(T a, T b) {return a > b;}
	 }

	 template <typename T> struct BIT_MAX {
	 constexpr static bool reverse = false;
	 constexpr static T I = numeric_limits<T>::min();
	 constexpr static bool compare = true;
	 static T op(T a, T b) {return max(a, b);}
	 static bool lower(T a, T b) {return a < b;}
	 }

	 template <typename T> struct BIT_ADD {
	 constexpr static bool reverse = true;
	 constexpr static T I = 0;
	 constexpr static bool compare = true;
	 static T op(T a, T b) {return a + b;}
	 static T rev(T a, T b) {return a - b;}
	 static bool lower(T a, T b) {return a < b;}
	 };

	 template <typename T> struct BIT_MUL {
	 constexpr static bool reverse = true;
	 constexpr static T I = 1;
	 constexpr static bool compare = true;
	 static T op(T a, T b) {return a * b;}
	 static T rev(T a, T b) {return a / b;}
	 static bool lower(T a, T b) {return a < b;}
	 }

	 template <typename T> struct BIT_XOR {
	 constexpr static bool reverse = true;
	 constexpr static T I = 0;
	 constexpr static bool compare = false;
	 static T op(T a, T b) {return a ^ b;}
	 static T rev(T a, T b) {return a ^ b;}
	 };

	 template <typename T> struct BIT_AND {
	 constexpr static bool reverse = false;
	 constexpr static T I = ~0;
	 constexpr static bool compare = true;
	 static T op(T a, T b) {return a & b;}
	 static bool lower(T a, T b) {return a > b;}
	 };

	 template <typename T> struct BIT_OR {
	 constexpr static bool reverse = false;
	 constexpr static T I = 0;
	 constexpr static bool compare = true;
	 static T op(T a, T b) {return a | b;}
	 static bool lower(T a, T b) {return a < b;}
	 };

	 template <typename T, typename Op> struct BIT {
	 int sz;
	 vector<T> val;

	 void init(int n) {
	 val.clear();
	 val.resize(sz = n + 1, Op::I);
	 return ;
	 }

	 void init(int n, T *a) {
	 val.clear();
val.resize(sz = n + 1);
for (int i = 1; i < sz; i++) val[i] = a[i]; 
for (int i = 1; i < sz; i++) if (i + (i & -i) < sz) val[i + (i & -i)] = Op::op(val[i + (i & -i)], val[i]); 
return ;
}

void add(int pos, const T &x) {
	while (pos < sz) {
		val[pos] = Op::op(val[pos], x);
		pos += pos & -pos;
	}
	return ;
}

T ask(int pos) const {
	T ans = Op::I;
	while (pos) {
		ans = Op::op(ans, val[pos]);
		pos ^= pos & -pos;
	}
	return ans;
}

T ask(int l, int r) const {
	static_assert(Op::reverse);
	return Op::rev(ask(r), ask(l - 1));
}

int lower_bound(const T &x) const {
	static_assert(Op::compare);
}
int upper_bound(const T &x) const {
	static_assert(OP:compare);
}

struct _token{
	BIT *bit;
	int pos;
	_token(BIT *b, int x) {bit = b; pos = x;}

	operator T() const {return bit -> ask(pos);}
	void operator ++ () const {return bit -> add(pos, 1);}
	void operator -- () const {return bit -> add(pos, -1);}
	void operator ++ (int) const {return bit -> add(pos, 1);}
	void operator -- (int) const {return bit -> add(pos, -1);}
	void operator += (int x) const {return bit -> add(pos, x);}
	void operator -= (int x) const {return bit -> add(pos, -x);}
};

//_token operator [](int x) {return _token(this, x);}
};

template <typename T, T (*Op)(T, T)> struct BIT_2D {};
template <typename T, T (*Op)(T, T)> struct BIT_3D {};
*/
