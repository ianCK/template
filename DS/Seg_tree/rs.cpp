template <typename T> class Seg_tree_rs {
	private:
		int _size;
		T *_val;
		vector<bool> _has_flag;

		void resize(int n) {
			_size = n;
			delete [] _val; _val = new T [n << 2];
			_has_flag.resize(n << 2);
			return ;
		}

		void init_dfs(int n, int l, int r, const T *a) {
			if (l == r) {
				_val[n] = a[l];
				_has_flag[n] = true;
			}
			else {
				int mid = (l + r) >> 1;
				_has_flag[n] = false;
				init_dfs(n << 1, l, mid, a);
				init_dfs(n << 1 | 1, mid + 1, r, a);
			}
			return ;
		}

		void push(int n) {
			if (_has_flag[n]) {
				_has_flag[n << 1] = _has_flag[n << 1 | 1] = true;
				_val[n << 1] = _val[n << 1 | 1] = _val[n];
				_has_flag[n] = false;
			}
			return ;
		}

		void set(int n, int l, int r, int L, int R, T x) {
			if (L <= l and r <= R) {
				_val[n] = x;
				_has_flag[n] = true;
			}
			else if (!(L > r or l > R)) {
				int mid = (l + r) >> 1;
				push(n);
				set(n << 1, l, mid, L, R, x);
				set(n << 1 | 1, mid + 1, r, L, R, x);
			}
			return ;
		}

		T ask(int n, int l, int r, int pos) const {
			if (_has_flag[n]) return _val[n];
			else {
				int mid = (l + r) >> 1;
				if (pos <= mid) return ask(n << 1, l, mid, pos);
				else return ask(n << 1 | 1, mid + 1, r, pos);
			}
		}

	public:
		Seg_tree_rs() : _size(0), _val(nullptr) {}
		Seg_tree_rs(int n) : _size(n), _val(new T [n << 2]) {
			_has_flag.resize(n << 2);
			_has_flag[1] = true;
		}
		Seg_tree_rs(int n, T val) : _size(n), _val(new T [n << 2]) {
			_val[1] = val;
			_has_flag.resize(n << 2);
			_has_flag[1] = true;
		}

		~Seg_tree_rs() {delete [] _val;}

		void init(int n) {
			if (_size != n) resize(n);
			_has_flag[1] = true;
			return ;
		}
		void init(int n, T val) {
			if (_size != n) resize(n);
			_val[1] = val;
			_has_flag[1] = true;
		}
		void init(int n, const T *a) {
			if (_size != n) resize(n);
			init_dfs(1, 1, _size, a);
			return ;
		}

		void set(int l, int r, T x) {return set(1, 1, _size, l, r, x);}
		T ask(int pos) const {return ask(1, 1, _size, pos);}

		void out() const {
			printf("seg_tree, size = %d\n", _size);
			_print(ask(1)); for (int i = 2; i <= _size; i++) {printf(" "); _print(ask(i));}
			return ;
		}
};
