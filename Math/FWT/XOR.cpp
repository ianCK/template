template <typename T> void FWT_XOR(T *a, int n) {
	for (int i = 2; i <= n; i <<= 1)
		for (int j = i; j <= n; j += i)
			for (int l = j - i, r = j - (i >> 1); r < j; l++, r++)
				a[r] = (a[l] += a[r]) - (a[r] + a[r]);
	return ;
}

template <typename T> void FWT_XOR_Inv(T *a, int n) {
	T inv(T(n).inv());
	for (int i = 2; i <= n; i <<= 1)
		for (int j = i; j <= n; j += i)
			for (int l = j - i, r = j - (i >> 1); r < j; l++, r++)
				a[r] = (a[l] += a[r]) - (a[r] + a[r]);
	for (int i = 0; i < n; i++) a[i] *= inv;
	return ;
}
