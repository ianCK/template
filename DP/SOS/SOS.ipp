#include "../../CommonInclude/CommonInclude.h"

template <typename T, T (*oper)(T, T)> void SOS(int tot, T* arr) {
	int n = __lg(tot);
	for (int i = 1; i <= n; i++) {
		int w = tot >> i;
		for (int s = 0; s < w; s++) {
			int from = s << i;
			int to = (s + 1) << i;
			int half = 1 << (i - 1);

			for (int l = from, r = from | half; r < to; l++, r++) arr[r] = oper(arr[l], arr[r]);
		}
	}

	return ;
}
