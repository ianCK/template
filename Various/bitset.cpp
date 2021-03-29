template <typename T, int bitset_size> T RevValue(const bitset<bitset_size> &bs) {
	T ans = 0;
	for (int i = 0; i < bitset_size; i++) ans = (ans << 1) | (bs[i] ? 1 : 0);
	return ans;
}

template <typename T, int bitset_size> T Value(const bitset<bitset_size> &bs) {
	T ans = 0;
	for (int i = bitset_size - 1; i >= 0; i--) ans = (ans << 1) | (bs[i] ? 1 : 0);
	return ans;
}

template <int bitset_size> bitset<bitset_size> Reverse(const bitset<bitset_size> &bs) {
	bitset<bitset_size> ans;
	for (int l = 0, r = bitset_size - 1; l <= r; l++, r--) {
		ans[l] = bs[r];
		ans[r] = bs[l];
	}
	return ans;
}
