// this set could kill all numbers under 2^64
__int128 PowMod(__int128 a, __int128 b, __int128 kMod) {
	__int128 ans = 1;
	for (; b; b >>= 1, a = a * a % kMod) if (b & 1) ans = ans * a % kMod;
	return ans;
}

bool IsPrime(unsigned long long int x) {
	static constexpr bool low[10] = {false, false, true, true, false, true, false, true, false, false};
	static constexpr unsigned int as = 7, a[7] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022};
	if (x < 10) return low[x];
	unsigned long long int t = x - 1;
	int r = 0;
	while ((t & 1) == 0) {
		t >>= 1;
		r++;
	}
	for (unsigned int i = 0; i < as; i++) if (a[i] <= x - 2) {
		bool ok = false;
		__int128 tt = PowMod(a[i], t, x);
		if (tt == 1) continue;
		for (int j = 0; j < r; j++, tt = tt * tt % x) if (tt == x - 1) {
			ok = true;
			break;
		}
		if (!ok) return false;
	}
	return true;
}
