template <typename T> void FWT_AND(T *a, int n) {
	for (int i = 2; i <= n; i <<= 1)
		for (int j = i; j <= n; j += i)
			for (int l = j - i, r = j - (i >> 1); r < j; l++, r++)
				a[l] += a[r];
	return ;
}

template <typename T> void FWT_AND_Inv(T *a, int n) {
	for (int i = 2; i <= n; i <<= 1)
		for (int j = i; j <= n; j += i)
			for (int l = j - i, r = j - (i >> 1); r < j; l++, r++)
				a[l] -= a[r];
	return ;
}
