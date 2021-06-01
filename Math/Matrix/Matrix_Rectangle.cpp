namespace Matrix_Inner {
	template <typename T> T ABS(T x) {return x >= 0 ? x : -x;}
	bool IsZero(double x) {
		static constexpr double kEps = 1E-10;
		return ABS(x) <= kEps;
	}
	template <typename T> bool IsZero(T x) {return x == 0;}
}

template <typename T> class Matrix {
	private:
		T **_val;
		int _n, _m;

	public:
		Matrix() : _val(nullptr), _n(0), _m(0) {}
		Matrix(int n, int m) : _n(n), _m(m), _val(new T* [n]) {
			for (int i = 0; i < _n; i++) {
				_val[i] = new T [_m];
				memset(_val[i], 0, sizeof(T) * _m);
			}
		}
		Matrix(const Matrix &rhs) : _n(rhs.row_size()), _m(rhs.col_size()), _val(rhs._val) {}

		void clear() {
			for (int i = 0; i < _n; i++) delete [] _val[i];
			delete [] _val;
			_val = nullptr;
			_n = _m = 0;
			return ;
		}

		void resize(int n, int m) {
			clear();
			_n = n, _m = m;
			_val = new T* [_n];
			for (int i = 0; i < _n; i++) {
				_val[i] = new T [_m];
				memset(_val[i], 0, sizeof(T) * _m);
			}
			return ;
		}
		int row_size() const {return _n;}
		int col_size() const {return _m;}

		void copy(const Matrix &x) {
			clear();
			_n = x.row_size(), _m = x.col_size();
			_val = new T* [_n];
			for (int i = 0; i < _n; i++) {
				_val[i] = new T [_m];
				memcpy(_val[i], x[i], sizeof(T) * _m);
			}
			return ;
		}

		Matrix transpose() const {
			Matrix ans(_m, _n);
			for (int i = 0; i < _n; i++) for (int j = 0; j < _m; j++) ans[j][i] = _val[i][j];
			return ans;
		}

		T* operator [](int x) {return _val[x];}
		const T* operator [](int x) const {return _val[x];}

		Matrix operator + (const Matrix &x) const {
			Matrix ans(_n, _m);
			for (int i = 0; i < _n; i++) for (int j = 0; j < _m; j++) ans[i][j] = _val[i][j] + x[i][j];
			return ans;
		}
		Matrix operator - (const Matrix &x) const {
			Matrix ans(_n, _m);
			for (int i = 0; i < _n; i++) for (int j = 0; j < _m; j++) ans[i][j] = _val[i][j] - x[i][j];
			return ans;
		}
		Matrix operator * (const T &x) const {
			Matrix ans(_n, _m);
			for (int i = 0; i < _n; i++) for (int j = 0; j < _m; j++) ans[i][j] = _val[i][j] * x;
			return ans;
		} 
		Matrix operator * (const Matrix &x) const {
			static constexpr int kCacheSize = 8 * 1024 * 1024 * sizeof(bool);
			static constexpr int kT = (1 << (__lg(kCacheSize) >> 1)) / sizeof(T);
			assert(_m == x._n);
			int n = _n, m = _m, p = x._m;
			Matrix ans(n, p);
			for (int I = 0; I < n; I += kT) for (int J = 0; J < p; J += kT) for (int K = 0; K < m; K += kT) {
				int limi = min(I + kT, n), limj = min(J + kT, p), limk = min(K + kT, m);
				for (int i = I; i < limi; i++) for (int j = J; j < limj; j++) {
					T sum = 0;
					for (int k = K; k < limk; k++) sum += _val[i][k] * x[k][j];
					ans[i][j] += sum;
				}
			}
			return ans;
		} 
		Matrix operator / (const T &x) const {
			Matrix ans(_n, _m);
			for (int i = 0; i < _n; i++) for (int j = 0; j < _m; j++) ans[i][j] = _val[i][j] / x;
			return ans;
		}
		Matrix operator += (const Matrix &x) {return *this = *this + x;} 
		Matrix operator -= (const Matrix &x) {return *this = *this - x;} 
		Matrix operator *= (const T &x) {return *this = *this * x;} 
		Matrix operator *= (const Matrix &x) {return *this = *this * x;} 
		Matrix operator /= (const T &x) {return *this = *this / x;} 

		T det() const {
			assert(_n == _m);

			Matrix tmp;
			tmp.copy(*this);
			bool flip = false;

			for (int i = 0; i < _n; i++) {
				if (Matrix_Inner::IsZero(tmp[i][i])) {
					int id = -1;
					for (int j = i + 1; j < _n; j++) if (!Matrix_Inner::IsZero(tmp[j][i])) {
						id = j;
						break;
					}
					if (id == -1) return 0;
					for (int j = i; j < _n; j++) swap(tmp[i][j], tmp[id][j]);
					flip = !flip;
				}

				for (int j = i + 1; j < _n; j++) if (!Matrix_Inner::IsZero(tmp[j][i])) {
					T freq(tmp[j][i] / tmp[i][i]);
					for (int k = i; k < _n; k++) tmp[j][k] -= freq * tmp[i][k];
				}
			}

			T ans = (flip ? -1 : 1);
			for (int i = 0; i < _n; i++) ans *= tmp[i][i];
			tmp.clear();
			return (ans + 0 - 0);
		}

		T det_piviting() const {
			assert(_n == _m);
			Matrix tmp;
			tmp.copy(*this);
			bool flip = false;

			for (int i = 0; i < _n; i++) {
				int mx = -1, my = -1;
				T cur_mx = 0;
				for (int j = i; j < _n; j++) for (int k = i; k < _m; k++) {
					if (Matrix_Inner::ABS(tmp[j][k]) > cur_mx) {
						cur_mx = Matrix_Inner::ABS(tmp[j][k]);
						mx = j, my = k;
					}
				}

				if (mx == -1) return 0;
				if (mx != i) {
					for (int j = i; j < _m; j++) swap(tmp[i][j], tmp[mx][j]);
					flip = !flip;
				}
				if (my != i) {
					for (int j = i; j < _n; j++) swap(tmp[j][i], tmp[j][my]);
					flip = !flip;
				}

				for (int j = i + 1; j < _n; j++) if (!Matrix_Inner::IsZero(tmp[j][i])) {
					T freq(tmp[j][i] / tmp[i][i]);
					for (int k = i; k < _m; k++) tmp[j][k] -= freq * tmp[i][k];
				}
			}

			T ans = (flip ? -1 : 1);
			for (int i = 0; i < _n; i++) ans *= tmp[i][i];
			tmp.clear();
			return (ans + 0 - 0);
		}

		bool invertible() const {
			if (_n != _m) return false;
			Matrix tmp, I(_n, _m);
			tmp.copy(*this);
			for (int i = 0; i < _n; i++) I[i][i] = 1;

			for (int i = 0; i < _n; i++) {
				if (Matrix_Inner::IsZero(tmp[i][i])) {
					int id = -1;
					for (int j = i + 1; j < _n; j++) if (!Matrix_Inner::IsZero(tmp[j][i])) {
						id = j;
						break;
					}
					if (id == -1) return false;
					for (int j = 0; j < _n; j++) {
						swap(tmp[i][j], tmp[id][j]);
						swap(I[i][j], I[id][j]);
					}
				}

				for (int j = 0; j < _n; j++) if (j != i && !Matrix_Inner::IsZero(tmp[j][i])) {
					T freq(tmp[j][i] / tmp[i][i]);
					for (int k = 0; k < _n; k++) {
						tmp[j][k] -= freq * tmp[i][k];
						I[j][k] -= freq * I[i][k];
					}
				}
			}

			for (int i = 0; i < _n; i++) if (Matrix_Inner::IsZero(tmp[i][i])) return false;
			tmp.clear(), I.clear();
			return true;
		}

		Matrix inv() const {
			assert(_n == _m);
			Matrix tmp, I(_n, _m);
			tmp.copy(*this);
			for (int i = 0; i < _n; i++) I[i][i] = 1;

			for (int i = 0; i < _n; i++) {
				if (Matrix_Inner::IsZero(tmp[i][i])) {
					int id = -1;
					for (int j = i + 1; j < _n; j++) if (!Matrix_Inner::IsZero(tmp[j][i])) {
						id = j;
						break;
					}
					assert(id != -1);
					for (int j = 0; j < _n; j++) {
						swap(tmp[i][j], tmp[id][j]);
						swap(I[i][j], I[id][j]);
					}
				}

				for (int j = 0; j < _n; j++) if (j != i && !Matrix_Inner::IsZero(tmp[j][i])) {
					T freq(tmp[j][i] / tmp[i][i]);
					for (int k = 0; k < _n; k++) {
						tmp[j][k] -= freq * tmp[i][k];
						I[j][k] -= freq * I[i][k];
					}
				}
			}

			for (int i = 0; i < _n; i++) {
				for (int j = 0; j < _n; j++) I[i][j] /= tmp[i][i];
			}

			tmp.clear();

			return I;
		}

		void out() const {
			for (int i = 0; i < _n; i++, printf("\n")) for (int j = 0; j < _m; j++) printf("%10lf", _val[i][j]);
			return ;
		}
};

template <typename T1, typename T2> Matrix<T1> Pow(Matrix<T1> A, T2 b) {
	assert(A.row_size() == A.col_size());
	int n = A.row_size();
	Matrix<T1> ans(n, n);
	for (int i = 0; i < n; i++) ans[i][i] = 1;
	for (; b; b >>= 1, A *= A) if (b & 1) ans *= A;
	return ans;
}

