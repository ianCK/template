template <typename T, T (*op)(T, T)> struct seg_tree_semigroup {
	private :
		int _size;
		T *val;

		inline void pull(int n) {
			val[n] = op(val[n << 1], val[n << 1 | 1]);
			return ;
		}

		void init(int n, int l, int r, T x) {
			if (l == r) val[n] = x;
			else {
				int mid = (l + r) >> 1;
				init(n << 1, l, mid, x);
				init(n << 1 | 1, mid + 1, r, x);
				pull(n);
			}
			return ;
		}

		void init(int n, int l, int r, T *v) {
			if (l == r) val[n] = v[l];
			else {
				int mid = (l + r) >> 1;
				init(n << 1, l, mid, v);
				init(n << 1 | 1, mid + 1, r, v);
				pull(n);
			}
			return ;
		}

		void set(int n, int l, int r, int pos, T x) {
			if (l == r) val[n] = x;
			else {
				int mid = (l + r) >> 1;
				if (pos <= mid) set(n << 1, l, mid, pos, x);
				else set(n << 1 | 1, mid + 1, r, pos, x);
				pull(n);
			}
			return ;
		}

		T ask(int n, int l, int r, int pos) const {
			if (l == r) return val[n];
			else {
				int mid = (l + r) >> 1;
				if (pos <= mid) return ask(n << 1, l, mid, pos);
				else return ask(n << 1 | 1, mid + 1, r, pos);
			}
		}

		T ask(int n, int l, int r, int L, int R) const {
			if (L <= l and r <= R) return val[n];
			else {
				int mid = (l + r) >> 1;

				if (L <= mid and mid < R) return op(ask(n << 1, l, mid, L, R), ask(n << 1 | 1, mid + 1, r, L, R));
				else if (L <= mid) return ask(n << 1, l, mid, L, R);
				else return ask(n << 1 | 1, mid + 1, r, L, R); // mid < R
			}
		}

	public:
		seg_tree_semigroup() : _size(0), val(nullptr) {}
		~seg_tree_semigroup() {delete [] val;}
		void init(int n, T x) {
			delete [] val; val = new T [n << 2];
			return init(1, 1, _size = n, x);
		}
		void init(int n, T *v) {
			delete [] val; val = new T [n << 2];
			return init(1, 1, _size = n, v);
		}
		void set(int pos, T x) {return set(1, 1, _size, pos, x);}
		T ask(int pos) const {return ask(1, 1, _size, pos);}
		T ask(int L, int R) const {return ask(1, 1, _size, L, R);}
		inline T top() const {return val[1];}
};
