// 1-based
template <typename T, T (*op)(T, T), T Id> class WO {
	private:
		int _size;
		T *_val;

		void build(int l, int r) {
			if (l == r) _val[l] = Id;
			else {
				int mid = (l + r) >> 1;
				T lhs = _val[l], rhs = _val[r];
				for (int i = l + 1; i <= mid; i++) lhs = op(lhs, _val[i]);
				for (int i = r - 1; i > mid; i--) rhs = op(_val[i], rhs);
				build(l, mid);
				build(mid + 1, r);
				for (int i = l; i <= mid; i++) _val[i] = op(_val[i], rhs);
				for (int i = mid + 1; i <= r; i++) _val[i] = op(lhs, _val[i]);
			}
			return ;
		}

	public:
		WO () : _size(0), _val(nullptr) {}
		WO (int n) : _size(n), _val(new T [n + 1]) {for (int i = 1; i <= n; i++) _val[i] = Id;}
		~WO() {delete [] _val;}
		void init(int n) {
			_size = n;
			delete [] _val; _val = new T [_size + 1];
			return ;
		}
		void build() {if (_size) return build(1, _size);}
		T& operator [] (int x) {return _val[x];}
};
