// O(n 2^n)
// 0-index
// init before using
struct Chromatic {
	static constexpr int kMod = 1'000'000'007;

	private:
	int n;
	int *neighbor;

	public:
	Chromatic() : n(0), neighbor(nullptr) {}
	~Chromatic() {
		delete [] neighbor;
	}

	void init(int _n) {
		delete [] neighbor;

		n = _n;
		neighbor = new int[n];
		for (int i = 0; i < n; i++) neighbor[i] = 1 << i;
		return ;
	}

	void AddEdge(int l, int r) {
		neighbor[l] |= 1 << r;
		neighbor[r] |= 1 << l;
		return ;
	}

	int solve() const {
		int tot = 1 << n;
		int *I = new int[tot];
		// I[S] = the number of independent subsets in S
		// I[S] = I[S / {v}] + I[S / N(v)]
		I[0] = 1;
		for (int S = 1; S < tot; S++) I[S] = I[S & (S - 1)] + I[S & ~neighbor[__builtin_ctz(S)]];

		int *val = new int[tot + 1];
		memset(val, 0, sizeof(int) * (tot + 1));
		for (int S = 0; S < tot; S++) {
			if (__builtin_parity(S)) val[I[S]]++;
			else val[I[S]]--;
		}

		delete [] I;

		int cnt = 0;
		for (int S = 1; S <= tot; S++) if (val[S]) cnt++;

		pair<int, int> *M = new pair<int, int>[cnt];
		for (int S = 1, idx = 0; S < tot; S++) if (val[S]) M[idx++] = make_pair(val[S], S);

		delete [] val;

		int ans = n;

		for (int c = 1; c <= n; c++) {
			long long int sum = 0;
			for (int idx = 0; idx < cnt; idx++) sum += (M[idx].first = 1LL * M[idx].first * M[idx].second % kMod);
			if (sum % kMod != 0) {
				ans = c;
				break;
			}
		}

		delete [] M;
		return ans;
	}

	int operator ()() const {return solve();}
};
