namespace Dividing_Tree_Inner {
	int ans;
	inline void dfs(int dep, int l, int r) {
		ans = max(ans, dep);
		if (l < r) {
			int mid = (l + r) >> 1;
			dfs(dep + 1, l, mid);
			dfs(dep + 1, mid + 1, r);
		}
		return ;
	}
	inline int depth(int l, int r) {
		ans = 0;
		dfs(0, l, r);
		return ans;
	}
}

template <typename T> struct Dividing_Tree {
	vector<int*> toleft;
	T *val[2], *sorted;
	int size;

	void build(int dep, int l, int r) {
		if (l < r) {
			int lst = (dep ^ 1) & 1, nxt = dep & 1;
			int lower_cnt = 0;
			int mid = (l + r) >> 1;
			T mid_val = sorted[mid];

			for (int i = l; i <= r; i++) if (val[nxt][i] < mid_val) lower_cnt++;

			int need = (mid - l + 1) - lower_cnt;
			int lidx = l, ridx = mid + 1;

			for (int i = l; i <= r; i++)
				if (val[nxt][i] > mid_val || (val[nxt][i] == mid_val && !need)) {
					val[lst][ridx++] = val[nxt][i];
					toleft[dep][i] = toleft[dep][i - 1];
				}
				else {
					if (val[nxt][i] == mid_val) need--;
					val[lst][lidx++] = val[nxt][i];
					toleft[dep][i] = toleft[dep][i - 1] + 1;
				}

			build(dep + 1, l, mid); build(dep + 1, mid + 1, r);
		}
		return ;
	}

	void init(int n, T *a) {
		for (int* i : toleft) delete [] i;
		delete [] val[0]; delete [] val[1];
		delete [] sorted;
		size = n;

		int target_dep = Dividing_Tree_Inner::depth(1, n);

		toleft.resize(target_dep);
		for (int i = 0; i < target_dep; i++) {
			toleft[i] = new int[size + 1];
			toleft[i][0] = 0;
		}
		
		val[0] = new T[size + 1]; val[1] = new T[size + 1];
		memcpy(val[0] + 1, a + 1, sizeof(T) * size);

		sorted = new T[size + 1];
		memcpy(sorted + 1, a + 1, sizeof(T) * size);
		sort(sorted + 1, sorted + size + 1);

		return build(0, 1, size);
	}

	T ask(int ql, int qr, int k) const {
		int l = 1, r = size, dep = 0;
		while (l < r) {
			int mid = (l + r) >> 1;
			int cnt = toleft[dep][qr] - toleft[dep][ql - 1];

			if (cnt >= k) {
				ql = toleft[dep][ql - 1] - toleft[dep][l - 1] + l;
				qr = toleft[dep][qr] - toleft[dep][l - 1] + l - 1;
				r = mid;
			}
			else {
				ql = (ql - l) - (toleft[dep][ql - 1] - toleft[dep][l - 1]) + mid + 1; 
				qr = (qr - l + 1) - (toleft[dep][qr] - toleft[dep][l - 1]) + mid;
				k -= cnt;
				l = mid + 1;
			}
			dep++;
		}
		return sorted[l];
	}
	T operator ()(int ql, int qr, int k) const {return ask(ql, qr, k);}
};
