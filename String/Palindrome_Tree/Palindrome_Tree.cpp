// Source : NoName Codebook
// 0-base
constexpr int kN = int(1E5 + 10), kC = 256;
struct PAM {
	int fail[kN], len[kN], nxt[kN][kC], sz, last;
	int cnt[kN];
	int newnode(int l, int fl = -1) {
		len[sz] = 1, fail[sz] = fl, cnt[sz] = 0;
		for (int i = 0; i < kC; i++) nxt[sz][i] = -1;
		return sz++;
	}
	void init() {
		sz = 0, last = 1;
		newnode(-1, 0); // odd
		newnode(0, 0); // even
		return ;
	}
	int get_fail(const char *s, int x, int pos) {
		while (pos - 1 - len[x] < 0 || s[pos - 1 - len[x]] != s[pos]) x = fail[x];
		return x;
	}
	void build(const char *s) {
		int n = int(strlen(s));
		for (int i = 0; i < n; i++) {
			int c = s[i] - 'a';
			int cur = get_fail(s, last, i);
			if (nxt[cur][c] == -1) {
				int now = newnode(len[cur] + 2);
				fail[now] = (len[now] == 1) ? 1 : nxt[get_fail(s, fail[cur], i)][c];
				nxt[cur][c] = now;
			}
			last = nxt[cur][c];
			cnt[last]++;
		}
	}
	void count() {for (int i = sz - 1; i >= 0; i--) cnt[fail[i]] += cnt[i];}
};
