#include "SOS.h"

#include "../../CommonInclude/CommonInclude.h"

template <typename T> tSOS<T>::tSOS() {}

template <typename T> void tSOS<T>::solve(int tot, T* arr) const {
	int n = __lg(tot);
	for (int i = 1; i <= n; i++) {
		int w = tot >> i;
		for (int s = 0; s < w; s++) {
			int from = s << i;
			int to = (s + 1) << i;
			int half = 1 << (i - 1);

			for (int l = from, r = from | half; r < to; l++, r++) oper(arr[r], arr[l]);
		}
	}

	return ;
}

template <typename T> void tSOS<T>::operator () (int tot, T* arr) const { return solve(tot, arr); }

template class tSOS<ui>;
template class tSOS<int>;
template class tSOS<ll>;
template class tSOS<ull>;

template class tSOS<double>;
