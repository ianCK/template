double rng_double(double l = 0, double r = 1) {
	static random_device rd;
	static mt19937 eng(rd());
	static uniform_real_distribution<double> distr(0, 1);

	return distr(eng) * (r - l) + l;
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

// 1 ~ n
vector<int> rng_perm(int n) {
	vector<int> ans(n);
	for (int i = 0; i < n; i++) ans[i] = i + 1;
	random_shuffle(ans.begin(), ans.end());
	return move(ans);
}

template <typename T> struct Lottery {
	vector<pair<double, T>> candidates;
	double sum;

	Lottery() : sum(0) {}
	~Lottery() {}

	void reserve(int n) {candidates.reserve(n); return ;}
	int size() const {return int(candidates.size());}
	bool empty() const {return candidates.empty();}

	void clear() {
		candidates.clear();
		sum = 0;
		return ;
	}

	void insert(double wei, T x) {
		sum += wei;
		if (!candidates.empty()) wei += candidates.back().first;
		candidates.push_back(make_pair(wei, x));
		return ;
	}

	T draw() const {
		double x = rng_double(0, sum);

		if (x < candidates[0].first) return candidates[0].second;

		int sz = int(candidates.size());

		int l = 0, r = sz;

		while (r - l > 1) {
			int mid = (l + r) >> 1;
			if (x >= candidates[mid].first) l = mid;
			else r = mid;
		}

		return candidates[r].second;
	}
};
