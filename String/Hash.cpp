struct Rolling_Hash {
	vector<ll> val, pw;
	void Build_Hash(string &s, int p) {
		int n = int(s.size());
		val.resize(n + 1);
		pw.resize(n + 1);
		for (int i = 1; i <= n; i++) val[i] = (val[i - 1] * p + s[i]) % kMod;
		pw[0] = 1;
		for (int i = 1; i <= n; i++) pw[i] = pw[i - 1] * p % kMod;
		return ;
	}
	ll Hash_Value(int l, int r) {
		ll ans = (val[r] - val[l - 1] * pw[r - l + 1]) % kMod;
		if (ans < 0) return ans + kMod;
		else return ans;
	}
	bool Same(int l1, int r1, int l2, int r2) {
		return Hash_Value(l1, r1) == Hash_Vaule(l2, r2);
	}
};
