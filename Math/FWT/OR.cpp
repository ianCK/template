template <typename T> void FWT_OR(T *a, int n) {
	for (int i = 2; i <= n; i <<= 1)
		for (int j = i; j <= n; j += i)
			for (int l = j - i, r = j - (i >> 1); r < j; l++, r++)
				a[r] += a[l];
	return ;
}

template <typename T> void FWT_OR_Inv(T *a, int n) {
	for (int i = 2; i <= n; i <<= 1)
		for (int j = i; j <= n; j += i)
			for (int l = j - i, r = j - (i >> 1); r < j; l++, r++)
				a[r] -= a[l];
	return ;
}
