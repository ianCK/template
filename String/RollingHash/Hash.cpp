// 1 based
template <typename T> struct RollingHash {
	T *lhs, *rhs, *p;
	
	RollingHash() {lhs = rhs = p = nullptr;}
	void init(string s, int kP = 31) {
		delete [] lhs;
		delete [] rhs;
		delete [] p;

		int n = int(s.size());
		lhs = new T[n + 1];
		rhs = new T[n + 2];
		p = new T[n + 1];

		p[0] = 1; p[1] = kP; for (int i = 2; i <= n; i++) p[i] = p[i - 1] * kP;
		lhs[0] = 0; for (int i = 1; i <= n; i++) lhs[i] = lhs[i - 1] * kP + (s[i - 1] - 'a');
		rhs[n + 1] = 0; for (int i = n; i >= 1; i--) rhs[i] = rhs[i + 1] * kP + (s[i - 1] - 'a');
		return ;
	}

	T l_value(int l, int r) const {return lhs[r] - lhs[l - 1] * p[r - l + 1];}
	T r_value(int l, int r) const {return rhs[l] - rhs[r + 1] * p[r - l + 1];}
	bool same(int l1, int r1, int l2, int r2) const {return l_value(l1, r1) == l_value(l2, r2);}// && r_value(l1, r1) == r_value(l2, r2);}
	bool is_palindrome(int l, int r) const {return l_value(l, r) == r_value(l, r);}
};

