template <typename T, T (*op)(T, T)> struct Sliding_Window {
	vector<T> val, L, R;
	int l, mid, r;
	// L : [l ~ mid]
	// R : [mid + 1 ~ r]
	Sliding_Window() {
		l = 0;
		mid = r = -1;
	}

	void RtoL() {
		L.clear();
		L.resize(int(R.size()));
		R.clear();
		l = mid + 1;
		L[0] = val[mid = r];
		for (int i = mid - 1, j = 1; i >= l; i--, j++) L[j] = op(val[i], L[j - 1]);
		return ;
	}

	void init(int sz = 0) {
		val.clear();
		val.reserve(sz);
		L.clear();
		R.clear();
		l = 0;
		mid = r = -1;
		return ;
	}

	void push_back(const T &x) {return val.push_back(x);}

	T ask(int nl, int nr) {
		while (r < nr) {
			if (R.empty()) R.push_back(val[++r]);
			else R.push_back(op(R.back(), val[++r]));
		}
		if (nl > mid + 1) RtoL();

		if (nr == mid) return L[mid - nl];
		else if (nl == mid + 1) return R[nr - mid - 1];
		else return op(L[mid - nl], R[nr - mid - 1]);
	}

	T operator () (int nl, int nr) {return ask(nl, nr);}
};
