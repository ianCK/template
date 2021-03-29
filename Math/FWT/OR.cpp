template <typename T> void FWT_OR(T *a, int n) {
	for (int i = 2; i <= n; i <<= 1)
		for (int j = 0; j < n; j += i)
			for (int k = j; k < (j | (i >> 1)); k++)
				a[k | (i >> 1)] += a[k];
	return ;
}

template <typename T> void FWT_OR_Inv(T *a, int n) {
	for (int i = 2; i <= n; i <<= 1)
		for (int j = 0; j < n; j += i)
			for (int k = j; k < (j | (i >> 1)); k++)
				a[k | (i >> 1)] -= a[k];
	return ;
}
