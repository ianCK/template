// Source: https://en.wikipedia.org/wiki/Reservoir_sampling
vector<int> rng_seq(int len, int l, int r) {
	vector<int> ans;
	ans.reserve(len);

	int n = r - l + 1;
	for (int i = 1; i <= len; i++) ans.PB(l + i - 1);

	double W = exp(log(rng_double()) / len);

	int i = len + 1;
	while (i <= n) {
		i = i + floor(log(rng_double()) / log(1 - W)) + 1;
		if (i <= n) {
			ans[rng_int(0, len - 1)] = i + l - 1;
			W = W * exp(log(rng_double()) / len);
		}
	}

	return ans;
}

