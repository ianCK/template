template <typename T> void FWT_XOR(T *a, int n) {
	for (int i = 2; i <= n; i <<= 1)
		for (int j = 0; j < n; j += i)
			for (int k = j; k < (j | (i >> 1)); k++)
				a[k | (i >> 1)] = (a[k] += a[k | (i >> 1)]) - (a[k | (i >> 1)] * 2);
	return ;
}

template <typename T> void FWT_XOR_Inv(T *a, int n) {
	T inv(T(n).inv());
	for (int i = 2; i <= n; i <<= 1)
		for (int j = 0; j < n; j += i)
			for (int k = j; k < (j | (i >> 1)); k++)
				a[k | (i >> 1)] = (a[k] += a[k | (i >> 1)]) - (a[k | (i >> 1)] * 2);
	for (int i = 0; i < n; i++) a[i] *= inv;
	return ;
}
