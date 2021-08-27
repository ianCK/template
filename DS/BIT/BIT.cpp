template <typename T> struct BIT {
	int _size; // n + 1
	T* val;
	T _sum;

	BIT() : _size(0), val(nullptr), _sum(0) {}
	~BIT() {delete [] val;}

	inline int size() const {return _size;}
	inline T sum() const {return _sum;}

	void init(int n) {
		delete [] val; val = new T[_size = n + 1];
		memset(val + 1, 0, sizeof(T) * n);
		_sum = 0;
		return ;
	}

	void init(int n, T *a) {
		delete [] val; val = new T[_size = n + 1];
		memcpy(val + 1, a + 1, sizeof(T) * n);
		for (int i = 1; i <= n; i++) if (i + (i & -i) <= n) val[i + (i & -i)] += val[i];
		for (int i = 1; i <= n; i++) _sum += a[i];
		return ;
	}

	void add(int pos, T x) {
		_sum += x;
		for (int i = pos; i < _size; i += i & -i) val[i] += x;
		return ;
	}

	T ask(int pos) const {
		T ans = 0;
		for (int i = pos; i; i ^= i & -i) ans += val[i];
		return ans;
	}
	T ask(int l, int r) const {return ask(r) - ask(l - 1);}

	int lower_bound(T x) const {
		int ans = 0;
		for (int i = 1 << __lg(_size - 1); i > 0; i >>= 1) 
			if (ans + i < _size && val[ans + i] < x) x -= val[ans += i];
		return ans + 1;
	}

	int upper_bound(T x) const {
		int ans = 0;
		for (int i = 1 << __lg(_size - 1); i > 0; i >>= 1) 
			if (ans + i < _size && val[ans + i] <= x) x -= val[ans += i];
		return ans + 1;
	}

	void clear() {memset(val + 1, 0, sizeof(T) * (_size - 1));}
	void clear(int pos) {for (int i = pos; i < _size; i += i & -i) val[i] = 0;}
};
