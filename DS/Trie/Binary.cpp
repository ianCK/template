struct Binary_Trie {
	using ull = unsigned long long int;
	static constexpr int default_max_size = 63;
	int max_size;
	vector<int> l, r, sz;

	int new_node() {
		l.push_back(0);
		r.push_back(0);
		sz.push_back(0);
		return int(l.size()) - 1;
	}

	Binary_Trie() {new_node(); max_size = default_max_size;}

	void set_max_size(int n) {max_size = n; return ;}

	void reserve(int n) {
		l.reserve(n);
		r.reserve(n);
		sz.reserve(n);
		return ;
	}

	void clear() {
		l.clear();
		r.clear();
		sz.clear();
		new_node();
		return ;
	}

	void Insert(ull x, int cur, int pos) {
		sz[cur]++;
		if (pos >= 0) {
			if (x >> pos & 1) {
				if (!r[cur]) {
					int tmp = new_node();
					r[cur] = tmp;
				}
				Insert(x, r[cur], pos - 1);
			}
			else {
				if (!l[cur]) {
					int tmp = new_node();
					l[cur] = tmp;
				}
				Insert(x, l[cur], pos - 1);
			}
		}
		return ;
	}

	ull mxor(ull x, int cur, int pos) const {
		if (pos < 0) return 0;
		else {
			if (x >> pos & 1) {
				if (r[cur]) return mxor(x, r[cur], pos - 1);
				else return mxor(x, l[cur], pos - 1) | (1LLU << pos);
			}
			else {
				if (l[cur]) return mxor(x, l[cur], pos - 1);
				else return mxor(x, r[cur], pos - 1) | (1LLU << pos);
			}
		}
	}
	ull Mxor(ull x, int cur, int pos) const {
		if (pos < 0) return 0;
		else {
			if (x >> pos & 1) {
				if (l[cur]) return Mxor(x, l[cur], pos - 1) | (1LLU << pos);
				else return Mxor(x, r[cur], pos - 1);
			}
			else {
				if (r[cur]) return Mxor(x, r[cur], pos - 1) | (1LLU << pos);
				else return Mxor(x, l[cur], pos - 1);
			}
		}
	}

	void Insert(ull x) {return Insert(x, 0, max_size - 1);}
	ull mxor(ull x) const {return mxor(x, 0, max_size - 1);}
	ull Mxor(ull x) const {return Mxor(x, 0, max_size - 1);}
};

