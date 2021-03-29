// the answer is in 0 ~ size
constexpr int NTT_size(int size) {return 1 << (__lg(size) + 2);}

template <typename T> void NTT(T *v , int size) {
	assert(size == (size & -size));

	for (int i = 1, j = size >> 1, k; i < (size - 1); i++) {
		if (i < j) swap(v[i], v[j]);
		k = size >> 1;
		while (j & k) {
			j ^= k;
			k >>= 1;
		}
		j |= k;
	}

	static bool first = true;
	static T wn[30];

	if (first) {
		for (int i = 1, j = 2; i < 30; i++, j <<= 1) wn[i] = Pow(T(3), T::Mod() - 1 - (T::Mod() - 1) / j);
		first = false;
	}

	for (int i = 1; i < size; i <<= 1) {
		T w(1);
		for (int k = 0; k < i; k++) {
			for (int j = 0; j < size; j += i << 1) {
				T u(v[k | j]);
				T t(w * v[k | j | i]);
				v[k | j] = u + t;
				v[k | j | i] = u - t;
			}
			w *= wn[__lg(i) + 1];
		}
	}
	return ;
}

template <typename T> void NTT_Inv(T *v, int size) {
	assert(size == (size & -size));

	for (int i = 1, j = size >> 1, k; i < (size - 1); i++) {
		if (i < j) swap(v[i], v[j]);
		k = size >> 1;
		while (j & k) {
			j ^= k;
			k >>= 1;
		}
		j |= k;
	}
	static bool first = true;
	static T wn[30];

	if (first) {
		for (int i = 1, j = 2; i < 30; i++, j <<= 1) wn[i] = Pow(T(3), (T::Mod() - 1) / j);
		first = false;
	}

	for (int i = 1; i < size; i <<= 1) {
		T w(1);
		for (int k = 0; k < i; k++) {
			for (int j = 0; j < size; j += i << 1) {
				T u(v[k | j]);
				T t(w * v[k | j | i]);
				v[k | j] = u + t;
				v[k | j | i] = u - t;
			}
			w *= wn[__lg(i) + 1];
		}
	}

	T inv(T(size).inv());
	for (int i = 0; i < size; i++) v[i] *= inv;
	return ;
}
