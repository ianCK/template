template <typename T> struct BIT_min {
	static constexpr T kInf = numeric_limits<T>::max() / 2 - 10;
	int _size; // n + 1
	T* val;

	BIT_min() : _size(0), val(nullptr) {}
	int size() const {return _size;}

	void init(int n) {
		delete val; val = new T[_size = n + 1];
		for (int i = 1; i <= n; i++) val[i] = kInf;
		return ;
	}

	void init(int n, T *a) {
		delete val; val = new T[_size = n + 1];
		memcpy(val + 1, a + 1, sizeof(T) * n);
		for (int i = 1; i <= n; i++) if (i + (i & -i) <= n) chmin(val[i + (i & -i)], val[i]);
		return ;
	}

	void fix(int pos, T x) {for (int i = pos; i < _size; i += i & -i) chmin(val[i], x); return ;}

	T ask(int pos) const {
		T ans = kInf;
		for (int i = pos; i; i ^= i & -i) chmin(ans, val[i]);
		return ans;
	}

	void clear() {
		for (int i = 1; i < _size; i++) val[i] = kInf;
		return ;
	}
};
