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
		double x = rng_double(sum);

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

