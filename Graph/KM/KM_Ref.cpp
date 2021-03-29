constexpr int kN = 1010;
constexpr long long int kInf = 0x3f3f3f3f;
long long int g[kN][kN];
int n, m;
long long int slack[kN], lx[kN], ly[kN];
int mx[kN], my[kN], vx[kN], vy[kN], timer;
bool vis[kN];
bool Dfs(int x) {
	vx[x] = timer;
	for (int y = 1; y <= m; y++) {
		if (vy[y] == timer) continue;
		long long int t = lx[x] + ly[y] - g[x][y];
		if (!t) {
			vy[y] = timer;
			if (!my[y] || Dfs(my[y])) {
				mx[x] = y;
				my[y] = x;
				return true;
			}
		} 
		else slack[y] = min(slack[y], t);
	}
	return false;
}

void Reweight() {
	long long int t = kInf;
	for (int y = 1; y <= m; y++) if (vy[y] != timer) t = min(t, slack[y]);
	for (int x = 1; x <= n; x++) if (vx[x] == timer) lx[x] -= t;
	for (int y = 1; y <= m; y++) if (vy[y] == timer) ly[y] += t;
	return ;
}

void Km() {
	memset(ly, 0, sizeof(ly));
	memset(mx, 0, sizeof(mx));
	memset(my, 0, sizeof(my));
	for (int x = 1; x <= n; x++) {
		lx[x] = -kInf;
		for (int y = 1; y <= m; y++) lx[x] = max(lx[x], g[x][y]);
	}
	for (int x = 1; x <= n; x++) {
		while (true) {
			++timer;
			memset(slack, kInf, sizeof(slack));
			if (Dfs(x)) break;
			else Reweight();
		}
	}
}
