// sa[i]: sa[i]-th suffix is the i-th lexigraphically smallest suffix. 
// hi[i]: longest common prefix of suffix sa[i] and suffix sa[i - 1].
namespace SA {
	bool *t_glob = nullptr;
	int *hi, *rnk, *sa, *_s = nullptr, *c_glob = nullptr, *x = nullptr, *p_glob = nullptr, *q_glob = nullptr;

	void induce(int *_sa, int *c, const int *s, const bool *t, int n, int z) {
		memcpy(x + 1, c, sizeof(int) * (z - 1));
		for (int i = 0; i < n; ++i) if (_sa[i] && !t[_sa[i] - 1]) _sa[x[s[_sa[i] - 1]]++] = _sa[i] - 1;
		memcpy(x, c, sizeof(int) * z);
		for (int i = n - 1; i >= 0; --i) if (_sa[i] && t[_sa[i] - 1]) _sa[--x[s[_sa[i] - 1]]] = _sa[i] - 1;
		return ;
	}

	void sais(int *s, int *_sa, int *p, int *q, bool *t, int *c, int n, int z) {
		bool uniq = t[n - 1] = true;
		int nn = 0, nmxz = -1, *nsa = _sa + n, *ns = s + n, last = -1;
		memset(c, 0, sizeof(int) * z);
		for (int i = 0; i < n; ++i) uniq &= c[s[i]]++;
		for (int i = 0; i < z - 1; ++i) c[i + 1] += c[i];
		if (uniq) {
			for (int i = 0; i < n; ++i) _sa[--c[s[i]]] = i;
			return;
		}
		for (int i = n - 2; i >= 0; --i) t[i] = (s[i] == s[i + 1] ? t[i + 1] : s[i] < s[i + 1]);
		memset(_sa, 0, sizeof(int) * n);
		memcpy(x, c, sizeof(int) * z);

		// p[i] = position of LMS substring
		// q[i] = #LMS substring of this position,  
		for (int i = 1; i <= n - 1; ++i) if (t[i] && !t[i - 1]) _sa[--x[s[i]]] = p[q[i] = nn++] = i;
		induce(_sa, c, s, t, n, z);
		for (int i = 0; i < n; ++i) if (_sa[i] && t[_sa[i]] && !t[_sa[i] - 1]) {
			bool neq = last < 0 || memcmp(s + _sa[i], s + last, (p[q[_sa[i]] + 1] - _sa[i]) * sizeof(int)) != 0;
			ns[q[last = _sa[i]]] = nmxz += neq;
		}

		sais(ns, nsa, p + nn, q + n, t + n, c + z, nn, nmxz + 1);
		memset(_sa, 0, sizeof(int) * n);
		memcpy(x, c, sizeof(int) * z);
		for (int i = nn - 1; i >= 0; --i) _sa[--x[s[p[nsa[i]]]]] = p[nsa[i]];
		induce(_sa, c, s, t, n, z);
	}

	void build(const string &s) {
		int n = int(s.size());

		int _kN = n + 266;
		delete hi; 	hi 	= new int[_kN];
		delete rnk; rnk	= new int[_kN];
		delete sa; 	sa 	= new int[_kN << 1];
		t_glob 	= new bool[_kN << 1];
		_s 			= new int[_kN << 1];
		p_glob 	= new int[_kN];
		q_glob	= new int[_kN << 1];
		x				= new int[_kN];
		c_glob 	= new int[_kN << 1];

		for (int i = 0; i < n; ++i) _s[i] = uint8_t(s[i]);
		_s[n] = 0;  // s shouldn't contain 0

		sais(_s, sa, p_glob, q_glob, t_glob, c_glob, n + 1, 256);

		for (int i = 0; i < n; ++i) sa[i] = sa[i + 1];
		for (int i = 0; i < n; ++i) rnk[sa[i]] = i;
		int ind = 0;
		hi[0] = 0;
		for (int i = 0; i < n; ++i) {
			if (!rnk[i]) {
				ind = 0;
				continue;
			}
			while (i + ind < n && s[i + ind] == s[sa[rnk[i] - 1] + ind]) ++ind;
			hi[rnk[i]] = ind ? ind-- : 0;
		}

		delete t_glob;
		delete p_glob;
		delete q_glob;
		delete c_glob;
		delete x;
		delete _s;

		return ;
	}
} 
