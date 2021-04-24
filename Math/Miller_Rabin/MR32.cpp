namespace MR32_Inner {
	unsigned long long int PowMod(unsigned long long int a, unsigned long long int b, unsigned long long int kMod) {
		unsigned long long int ans = 1;
		for (; b; b >>= 1, a = a * a % kMod) if (b & 1) ans = ans * a % kMod;
		return ans;
	}
}

bool IsPrime(unsigned int x) {
	static constexpr bool low[8] = {false, false, true, true, false, true, false, true};
	static constexpr unsigned int as = 3, a[3] = {2, 7, 61};
	if (x < 8) return low[x];

	unsigned int t = x - 1;
	int r = 0;
	while ((t & 1) == 0) {
		t >>= 1;
		r++;
	}
	for (unsigned int i = 0; i < as; i++) if (a[i] <= x - 2) {
		bool ok = false;
		unsigned long long int tt = MR32_Inner::PowMod(a[i], t, x);
		if (tt == 1) continue;
		for (int j = 0; j < r; j++, tt = tt * tt % x) if (tt == x - 1) {
			ok = true;
			break;
		}
		if (!ok) return false;
	}
	return true;
}
