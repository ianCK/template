// This file is moved to template/various/random/random.cpp
double rng_double() {
	static random_device rd;
	static mt19937 eng(rd());
	static uniform_real_distribution<double> distr(0.0, 1.0);
	return distr(eng);
}

template <int l, int r> int rng_int() {
	static random_device rd;
	static mt19937 eng(rd());
	static uniform_int_distribution<int> distr(l, r);
	return distr(eng);
}

int rng_int(int l, int r) {
	static random_device rd;
	static mt19937 eng(rd());
	return eng() % (r - l + 1) + l;
}

template <int l, int r> void rng_array(int n, int *a) {
	unordered_set<int> used;

	int cnt = 0;
	while (cnt < n) {
		int tmp = rng_int<l, r>();
		if (used.find(tmp) == used.end()) used.insert(a[++cnt] = tmp);
	}

	return ;
}