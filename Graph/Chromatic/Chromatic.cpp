// O(n 2^n)
// 0-index
// init before using
struct Chromatic {
	using chromatic_mint = Mod_Int<int(1E9 + 7)>;

	int n;
	int *not_neighbor;

	void init(int _n) {
		delete [] not_neighbor;

		n = _n;
		not_neighbor = new int[n];
		for (int i = 0; i < n; i++) not_neighbor[i] = ((1 << n) - 1) ^ (1 << i);
		return ;
	}

	void AddEdge(int l, int r) {
		not_neighbor[l] &= ~(1 << r);
		not_neighbor[r] &= ~(1 << l);
		return ;
	}

	int solve() const {
		int tot = 1 << n;
		chromatic_mint *I = new chromatic_mint[tot];
		// I[S] = the number of independent subsets in S
		// I[S] = I[S / {v}] + I[S / N(v)]
		I[0] = 1;
		for (int S = 1; S < tot; S++) I[S] = I[S ^ (S & -S)] + I[S & not_neighbor[__builtin_ctz(S)]];

		int l = 0, r = n;
		while (r - l > 1) {
			int mid = (l + r) >> 1;
			chromatic_mint g;
			for (int S = 0; S < tot; S++)
				if (__builtin_parity(S)) g += Pow(I[S], mid);
				else g -= Pow(I[S], mid);
			// g = +- number of ways to choose k independent sets to cover (tot - 1)
			// the independent sets might intersect
			if (g == 0) l = mid;
			else r = mid;
		}

		delete [] I;
		return r;
	}

	int operator ()() const {return solve();}
};
