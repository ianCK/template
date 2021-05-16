// zkw
template <typename T> class zkw {
	private:
		int _size, M;
		T *val;

	public:
		zkw() : _size(0), val(nullptr) {}
		void init(int n) {
			// !!! n > 1 
			_size = 1 << (__lg(n - 1) + 2);
			M = (_size >> 1) - 1;
			delete [] val; val = new T [_size];
			memset(val, 0, sizeof(T) * _size);
			return ;
		}
		void init(int n, T *v) {
			// !!! n > 1 
			_size = 1 << (__lg(n - 1) + 2);
			M = (_size >> 1) - 1;
			delete [] val; val = new T [_size];
			memcpy(val + ((_size >> 1) - 1), v + 1, sizeof(T) * n);
			return ;
		}
		void add(int pos, T x) {for (pos += M; pos; pos >>= 1) val[pos] += x; return ;}
		T ask(int l, int r) {
			T ans = 0;
			for (l += M, r += M

		}
};

