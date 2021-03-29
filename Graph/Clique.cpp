// O(?)
// written by robert1003
// before using : memset(&MC, 0, sizeof(MC))
// n -> zero base
// solution is stored in sol[0 ~ ans - 1]
// solve(n)
// AddEdge(l, r)

template <int size> struct Maximum_Clique {  // Maximum Clique
	bitset<size> a[size], cs[size];
	int ans, sol[size], q, cur[size], d[size];
	void AddEdge(int u, int v) {
		a[u][v] = a[v][u] = true;
		return ;
	}
	void csort(vector<int> &r, vector<int> &c) {
		int mx = 1, km = max(ans - q + 1, 1), t = 0, m = int(r.size());
		cs[1].reset();
		cs[2].reset();
		for (int i = 0; i < m; i++) {
			int p = r[i], k = 1;
			while ((cs[k] & a[p]).count()) k++;
			if (k > mx) {
				mx++;
				cs[mx + 1].reset();
			}
			cs[k][p] = 1;
			if (k < km) r[t++] = p;
		}
		c.resize(m);
		if (t) c[t - 1] = 0;
		for (int k = km; k <= mx; k++) {
			for (int p = int(cs[k]._Find_first()); p < size; p = int(cs[k]._Find_next(p))) {
				r[t] = p;
				c[t] = k;
				t++;
			}
		}
		return ;
	}
	void dfs(vector<int> &r, vector<int> &c, int l, bitset<size> mask) {
		while (!r.empty()) {
			int p = r.back();
			r.pop_back();
			mask[p] = 0;
			if (q + c.back() <= ans) return;
			cur[q++] = p;
			vector<int> nr, nc;
			bitset<size> nmask = mask & a[p];
			for (int i : r) if (a[p][i]) nr.push_back(i);
			if (!nr.empty()) {
				if (l < 4) {
					for (int i : nr) d[i] = int((a[i] & nmask).count());
					sort(nr.begin(), nr.end(), [&](int x, int y) {return d[x] > d[y];});
				}
				csort(nr, nc);
				dfs(nr, nc, l + 1, nmask);
			} 
			else if (q > ans) {
				ans = q;
				copy(cur, cur + q, sol);
			}
			c.pop_back();
			q--;
		}
	}
	int operator ()(int n) {
		bitset<size> mask;
		vector<int> r, c;
		mask.reset();
		for (int i = 0; i < n; i++) mask[i] = true;
		for (int i = 0; i < n; i++) if (mask[i]) r.push_back(i);
		for (int i = 0; i < n; i++) d[i] = int((a[i] & mask).count());
		sort(r.begin(), r.end(), [&](int i, int j) {return d[i] > d[j];});
		csort(r, c);
		dfs(r, c, 1, mask);
		return ans;  // sol[0 ~ ans-1]
	}
};
