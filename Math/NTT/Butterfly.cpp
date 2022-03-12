namespace butterfly_inner {
	int bsf(unsigned int n) {
#ifdef _MSC_VER
		unsigned long index;
		_BitScanForward(&index, n);
		return index;
#else
		return __builtin_ctz(n);
#endif
	}
}

// the answer is in 0 ~ size
constexpr int NTT_size(int size) {return 1 << (__lg(size) + 1);}

template <typename T> void NTT(T *v, int size) {
	assert(size == (size & -size));

	static constexpr int g = 3; // primitive root
	int h = __lg(size);

	static bool first = true;
	static T sum_e[30];
	if (first) {
		first = false;
		T es[30], ies[30];
		int cnt2 = butterfly_inner::bsf(T::Mod() - 1);
		T e = Pow(T(g), (T::Mod() - 1) >> cnt2), ie = e.inv();
		for (int i = cnt2; i >= 2; i--) {
			es[i - 2] = e;
			ies[i - 2] = ie;
			e *= e;
			ie *= ie;
		}
		T now = 1;
		for (int i = 0; i <= cnt2 - 2; i++) {
			sum_e[i] = es[i] * now;
			now *= ies[i];
		}
	}
	for (int ph = 1; ph <= h; ph++) {
		int w = 1 << (ph - 1), p = 1 << (h - ph);
		T now = 1;
		for (int s = 0; s < w; s++) {
			int offset = s << (h - ph + 1);
#pragma GCC ivdep
			for (int i = 0; i < p; i++) {
				auto l = v[i + offset];
				auto r = v[i + offset + p] * now;
				v[i + offset] = l + r;
				v[i + offset + p] = l - r;
			}
			now *= sum_e[butterfly_inner::bsf(~(unsigned int)(s))];
		}
	}
	return ;
}

template <typename T> void NTT(vector<T> &v, int size) {
	assert(size == (size & -size));

	static constexpr int g = 3; // primitive root
	int h = __lg(size);

	static bool first = true;
	static T sum_e[30];
	if (first) {
		first = false;
		T es[30], ies[30];
		int cnt2 = butterfly_inner::bsf(T::Mod() - 1);
		T e = Pow(T(g), (T::Mod() - 1) >> cnt2), ie = e.inv();
		for (int i = cnt2; i >= 2; i--) {
			es[i - 2] = e;
			ies[i - 2] = ie;
			e *= e;
			ie *= ie;
		}
		T now = 1;
		for (int i = 0; i <= cnt2 - 2; i++) {
			sum_e[i] = es[i] * now;
			now *= ies[i];
		}
	}
	for (int ph = 1; ph <= h; ph++) {
		int w = 1 << (ph - 1), p = 1 << (h - ph);
		T now = 1;
		for (int s = 0; s < w; s++) {
			int offset = s << (h - ph + 1);
#pragma GCC ivdep
			for (int i = 0; i < p; i++) {
				auto l = v[i + offset];
				auto r = v[i + offset + p] * now;
				v[i + offset] = l + r;
				v[i + offset + p] = l - r;
			}
			now *= sum_e[butterfly_inner::bsf(~(unsigned int)(s))];
		}
	}
	return ;
}

template <typename T> void NTT_Inv(T *v, int size) {
	assert(size == (size & -size));

	static constexpr int g = 3; // primitive root
	int h = __lg(size);

	static bool first = true;
	static T sum_ie[30];
	if (first) {
		first = false;
		T es[30], ies[30];
		int cnt2 = butterfly_inner::bsf(T::Mod() - 1);
		T e = Pow(T(g), (T::Mod() - 1) >> cnt2), ie = e.inv();
		for (int i = cnt2; i >= 2; i--) {
			es[i - 2] = e;
			ies[i - 2] = ie;
			e *= e;
			ie *= ie;
		}
		T now = 1;
		for (int i = 0; i <= cnt2 - 2; i++) {
			sum_ie[i] = ies[i] * now;
			now *= es[i];
		}
	}

	for (int ph = h; ph >= 1; ph--) {
		int w = 1 << (ph - 1), p = 1 << (h - ph);
		T inow = 1;
		for (int s = 0; s < w; s++) {
			int offset = s << (h - ph + 1);
#pragma GCC ivdep
			for (int i = 0; i < p; i++) {
				T l = v[i + offset];
				T r = v[i + offset + p];
				v[i + offset] = l + r;
				v[i + offset + p] = (l - r) * inow;
			}
			inow *= sum_ie[butterfly_inner::bsf(~(unsigned int)(s))];
		}
	}

	T iz = T(size).inv();
	for (int i = 0; i < size; i++) v[i] *= iz;
	return ;
}

template <typename T> void NTT_Inv(vector<T> &v, int size) {
	assert(size == (size & -size));

	static constexpr int g = 3; // primitive root
	int h = __lg(size);

	static bool first = true;
	static T sum_ie[30];
	if (first) {
		first = false;
		T es[30], ies[30];
		int cnt2 = butterfly_inner::bsf(T::Mod() - 1);
		T e = Pow(T(g), (T::Mod() - 1) >> cnt2), ie = e.inv();
		for (int i = cnt2; i >= 2; i--) {
			es[i - 2] = e;
			ies[i - 2] = ie;
			e *= e;
			ie *= ie;
		}
		T now = 1;
		for (int i = 0; i <= cnt2 - 2; i++) {
			sum_ie[i] = ies[i] * now;
			now *= es[i];
		}
	}

	for (int ph = h; ph >= 1; ph--) {
		int w = 1 << (ph - 1), p = 1 << (h - ph);
		T inow = 1;
		for (int s = 0; s < w; s++) {
			int offset = s << (h - ph + 1);
#pragma GCC ivdep
			for (int i = 0; i < p; i++) {
				T l = v[i + offset];
				T r = v[i + offset + p];
				v[i + offset] = l + r;
				v[i + offset + p] = (l - r) * inow;
			}
			inow *= sum_ie[butterfly_inner::bsf(~(unsigned int)(s))];
		}
	}

	T iz = T(size).inv();
#pragma GCC ivdep
	for (int i = 0; i < size; i++) v[i] *= iz;
	return ;
}
