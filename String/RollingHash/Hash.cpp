// 1 based
template <typename T, typename _T> void Build_Hash(const char *s, T*& hs, _T kP) {
	int n = int(strlen(s));
	
	delete [] hs; hs = new T[n + 1];
	hs[0] = 0; for (int i = 1; i <= n; i++) hs[i] = hs[i - 1] * kP + s[i - 1];

	return ;
}
template <typename T, typename _T> void Build_Hash(string s, T*& hs, _T kP) {return Build_Hash(s.c_str(), hs, kP);}

template <typename T, typename _T> void Build_Pow(int n, T*& p, _T kP) {
	delete [] p; p = new T[n + 1];
	p[0] = 1; p[1] = kP; for (int i = 2; i <= n; i++) p[i] = p[i - 1] * kP;
	return ;
}

template <typename T> T Hash_value(int l, int r, const T* const hs, const T* const p) {return hs[r] - hs[l - 1] * p[r - l + 1];}
template <typename T> bool same(int l1, int r1, int l2, int r2, const T* const hs1, const T* const hs2, const T* const p) {return Hash_value(l1, r1, hs1, p) == Hash_value(l2, r2, hs2, p);}
template <typename T> int lcp(int l1, int r1, int l2, int r2, const T* const hs1, const T* const hs2, const T* const p) {
	int l = 0, r = min(r1 - l1, r2 - l2) + 1;
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		if (same(l1, l1 + mid - 1, l2, l2 + mid - 1, hs1, hs2, p)) l = mid;
		else r = mid;
	}
	return l;
}
