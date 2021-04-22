namespace Gauss_Inner {
	template <typename T> T ABS(T x) {return x >= 0 ? x : -x;}
	bool IsZero(double x) {
		static constexpr double kEps = 1E-10;
		return ABS(x) <= kEps;
	}
	template <typename T> bool IsZero(T x) {return x == 0;}
}

// 0-base
template <typename T> struct Gauss {
	T **val, *answer;
	int _size;
	bool calculated, need_piviting;

	Gauss() : val(nullptr), _size(0), calculated(false), answer(nullptr), need_piviting(true) {}
	Gauss(int x) {
		_size = x;
		val = new T* [_size];
		need_piviting = true;
		calculated = false;
		for (int i = 0; i < _size; i++) {
			val[i] = new T [_size + 1];
			// _size + 1 !!!
			memset(val[i], 0, sizeof(T) * (_size + 1));
		}
	}

	void add(int x, int y, const T &v) {
		val[x][y] += v;
		return ;
	}

	void set(int x, int y, const T &v) {
		val[x][y] = v;
		return ;
	}

	void add_constant(int x, const T &v) {
		val[x][_size] += v;
		return ;
	}

	void set_constant(int x, const T &v) {
		val[x][_size] = v;
		return ;
	}

	void reset(int x) {
		for (int i = 0; i < _size; i++) delete [] val[i];
		delete [] val;
		delete [] answer;

		_size = x;
		val = new T* [_size];
		need_piviting = true;
		calculated = false;
		for (int i = 0; i < _size; i++) {
			val[i] = new T [_size + 1];
			memset(val[i], 0, sizeof(T) * (_size + 1));
		}
		return ;
	}

	void no_piviting() {need_piviting = false; return ;}
	int size() const {return _size;}

	bool calculate_piviting() { // return true if it is linear independant
		int idy[_size], py[_size];
		for (int i = 0; i < _size; i++) idy[i] = py[i] = i;

		for (int i = 0; i < _size; i++) {
			int mx = -1, my = -1;
			T cur_mx = 0;
			for (int j = i; j < _size; j++) for (int k = i; k < _size; k++) {
				if (Gauss_Inner::ABS(val[j][k]) > cur_mx) {
					cur_mx = Gauss_Inner::ABS(val[j][k]);
					mx = j, my = k;
				}
			}

			if (mx == -1) return false;
			if (mx != i) for (int j = i; j <= _size; j++) swap(val[i][j], val[mx][j]);
			if (my != i) {
				for (int j = 0; j < _size; j++) swap(val[j][i], val[j][my]);
				swap(py[i], py[my]);
				swap(idy[py[i]], idy[py[my]]);
			}

			for (int j = 0; j < _size; j++) if (j != i && !Gauss_Inner::IsZero(val[j][i])) {
				T freq(val[j][i] / val[i][i]);
				for (int k = i; k <= _size; k++) val[j][k] -= freq * val[i][k];
			}
		}

		answer = new T [_size];
		for (int i = 0; i < _size; i++) answer[i] = val[idy[i]][_size] / val[idy[i]][idy[i]];

		return true;
	}

	bool calculate_naive() {
		for (int i = 0; i < _size; i++) {
			if (Gauss_Inner::IsZero(val[i][i])) {
				int id = -1;
				for (int j = i + 1; j < _size; j++) if (!Gauss_Inner::IsZero(val[j][i])) {
					id = j;
					break;
				}
				if (id == -1) return false;
				for (int j = i; j <= _size; j++) swap(val[i][j], val[id][j]);
			}

			for (int j = 0; j < _size; j++) if (j != i && !Gauss_Inner::IsZero(val[j][i])) {
				T freq(val[j][i] / val[i][i]);
				for (int k = i; k <= _size; k++) val[j][k] -= freq * val[i][k];
			}
		}

		answer = new T [_size];
		for (int i = 0; i < _size; i++) answer[i] = val[i][_size] / val[i][i];

		return true;
	}

	bool calculate() {
		calculated = true;
		if (need_piviting) return calculate_piviting();
		else return calculate_naive();
	}

	T operator [](int x) {
		if (!calculated) calculate();
		return answer[x];
	}
};
