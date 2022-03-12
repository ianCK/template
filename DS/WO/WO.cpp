// 0-based
template <typename T, T (*op)(T, T)> class WO {
	private:
		int _size;
		T _all;
		T *_val;

	public:
		WO () : _size(0), _val(nullptr) {}
		~WO() {delete [] _val;}
		inline int size() const {return _size;}
		void init(int n) {
			_size = n;
			delete [] _val; _val = new T [_size];
			return ;
		}
		void build() {
			T *tol = new T [_size], *tor = new T [_size];

			tol[0] = _val[0];
			for (int i = 1; i < _size; i++) tol[i] = op(tol[i - 1], _val[i]);

			tor[_size - 1] = _val[_size - 1];
			for (int i = _size - 2; i >= 0; i--) tor[i] = op(_val[i], tor[i + 1]);

			_val[0] = tor[1], _val[_size - 1] = tol[_size - 2];
			for (int i = 1; i < _size - 1; i++) _val[i] = op(tol[i - 1], tor[i + 1]);

			_all = tor[0];

			delete [] tol;
			delete [] tor;

			return ;
		}
		T& operator [] (int x) {return _val[x];}
		inline T all() const {return _all;}
		inline T cal_all() const {
			T ret = _val[0];
			for (int i = 1; i < _size; i++) ret = op(ret, _val[i]);
			return ret;
		}
};
