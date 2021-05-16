// O(n 2^n)
// 0-index
// init before using
struct Chromatic {
	static constexpr uint64_t kMod = (1LL << 61) - 1;

	uint64_t Mul(uint64_t a, uint64_t b) {
		uint64_t l1 = uint32_t(a), h1 = a >> 32, l2 = uint32_t(b), h2 = b >> 32;
		uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
		uint64_t ret = (l & kMod) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
		ret = (ret & kMod) + (ret >> 61);
		ret = (ret & kMod) + (ret >> 61);
		return ret - 1;
	}

	private:
	int _size;
	int *neighbor;

	public:
	Chromatic() : _size(0), neighbor(nullptr) {}
	int size() const {return _size;}

	void init(int n) {
		delete [] neighbor;

		_size = n;
		neighbor = new int[_size];
		for (int i = 0; i < _size; i++) neighbor[i] = 1 << i;
		return ;
	}

	void AddEdge(int l, int r) {
		neighbor[l] |= 1 << r;
		neighbor[r] |= 1 << l;
		return ;
	}

	int solve() const {
		int tot = 1 << _size;
		int *I = new int[tot];
		// I[S] = the number of independent subsets in S
		// I[S] = I[S / {v}] + I[S / N(v)]
		I[0] = 1;
		for (int S = 1; S < tot; S++) I[S] = I[S & (S - 1)] + I[S & ~neighbor[__builtin_ctz(S)]];

		int *val = new int[tot + 1];
		memset(val, 0, sizeof(int) * (tot + 1));
		for (int S = 0; S < tot; S++) 
			if (__builtin_parity(S)) val[I[S]]++;
			else val[I[S]]--;

		delete [] I;

		int cnt = 0;
		for (int S = 1; S <= tot; S++) if (val[S]) cnt++;

		pair<int, int> *M = new pair<int, int>[cnt];
		for (int S = 1, idx = 0; S < tot; S++) if (val[S]) M[idx++] = make_pair(val[S], S);

		delete [] val;

		int ans = n;

		for (int c = 1; c <= n; c++) {
			uint64_t sum = 0;
			for (int idx = 0; idx < cnt; idx++) sum += (M[idx].first = Mul(M[idx].first, M[idx].second));
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
