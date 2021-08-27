template <typename T> void FWT_AND(T *a, int n) {
	int mid = n >> 1;
	if (mid > 1) FWT_AND(a, mid), FWT_AND(a + mid, mid);
	if (mid) for (int l = 0, r = mid; r < n; l++, r++) a[l] += a[r];
	return ;
}

template <typename T> void FWT_AND_Inv(T *a, int n) {
	int mid = n >> 1;
	if (mid > 1) FWT_AND_Inv(a, mid), FWT_AND_Inv(a + mid, mid);
	if (mid) for (int l = 0, r = mid; r < n; l++, r++) a[l] -= a[r];
	return ;
}

