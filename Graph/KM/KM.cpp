// 0-based
// x - matchx
// y - matchy
template <typename T> struct KM {
	vector<vector<T>> g;
	vector<T> lx, ly, slack;
	vector<short> matchx, matchy, vx, vy;
	int n, timer;
	bool solved;

	void init(int _n) {
		n = _n;
		solved = false;
		g.clear();
		g.resize(n, vector<T>(n));
		return ;
	}

	void AddEdge(int x, int y, T c) {
		g[x][y] = c;
		return ;
	}
	
	bool Dfs(int x) {
		vx[x] = timer;
		for (int y = 0; y < n; y++) {
			if (vy[y] == timer) continue;
			T t = lx[x] + ly[y] - g[x][y];
			if (!t) {
				vy[y] = timer;
				if (!(~matchy[y]) || Dfs(matchy[y])) {
					matchx[x] = y;
					matchy[y] = x;
					return true;
				}
			}
			else slack[y] = min(slack[y], t);
		}
		return false;
	}

	void Reweight() {
		T t = 0x3f3f3f3f3f3f3f3f;
		for (int y = 0; y < n; y++) if (vy[y] != timer) t = min(t, slack[y]);
		for (int x = 0; x < n; x++) if (vx[x] == timer) lx[x] -= t;
		for (int y = 0; y < n; y++) if (vy[y] == timer) ly[y] += t;
		return ;
	}

	void solve() {
		solved = true;
		lx.resize(n); fill(lx.begin(), lx.end(), 0);
		ly.resize(n); fill(ly.begin(), ly.end(), 0);
		matchx.resize(n); fill(matchx.begin(), matchx.end(), -1);
		matchy.resize(n); fill(matchy.begin(), matchy.end(), -1);
		vx.resize(n); fill(vx.begin(), vx.end(), 0);
		vy.resize(n); fill(vy.begin(), vy.end(), 0);
		slack.resize(n);
		timer = 0;
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) lx[i] = max(lx[i], g[i][j]);

		for (int i = 0; i < n; i++) {
			while (true) {
				++timer;
				fill(slack.begin(), slack.end(), 0x3f3f3f3f3f3f3f3f);
				if (Dfs(i)) break;
				else Reweight();
			}
		}
	}

	T cal() {
		if (!solved) solve();
		T ans = 0;
		for (int i = 0; i < n; i++) ans += lx[i];
		for (int i = 0; i < n; i++) ans += ly[i];
		return ans;
	}

	T operator ()() {return cal();}
};
