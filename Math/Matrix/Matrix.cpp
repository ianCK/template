namespace Matrix_Inner {
	template <typename T> T ABS(T x) {return x >= 0 ? x : -x;}
	bool IsZero(double x) {
		static constexpr double kEps = 1E-10;
		return ABS(x) <= kEps;
	}
	template <typename T> bool IsZero(T x) {return x == 0;}
}

template <typename T> struct Matrix {
	T **val;
	int _size;

	Matrix() : val(nullptr), _size(0) {}
	Matrix(int x, T v = 0) {
		_size = x;
		val = new T* [_size];
		for (int i = 0; i < _size; i++) {
			val[i] = new T [_size];
			memset(val[i], 0, sizeof(T) * _size);
			val[i][i] = v;
		}
	}

	void clear() {
		for (int i = 0; i < _size; i++) delete [] val[i];
		delete [] val;
		return ;
	}

	void resize(int x) {
		clear();
		_size = x;
		val = new T* [_size];
		for (int i = 0; i < _size; i++) {
			val[i] = new T [_size];
			memset(val[i], 0, sizeof(T) * _size);
		}
		return ;
	}
	int size() const {return _size;}

	void copy(const Matrix &x) {
		clear();
		_size = x.size();
		val = new T* [_size];
		for (int i = 0; i < _size; i++) {
			val[i] = new T [_size];
			memcpy(val[i], x[i], sizeof(T) * _size);
		}
		return ;
	}

	Matrix operator = (const Matrix &x) {
		clear();
		val = x.val;
		_size = x._size;
		return *this;
	}
	T* operator [](int x) {return val[x];}
	const T* operator [](int x) const {return val[x];}

	Matrix operator + (const Matrix &x) const {
		Matrix ans(_size);
		for (int i = 0; i < _size; i++) for (int j = 0; j < _size; j++) ans[i][j] = val[i][j] + x[i][j];
		return ans;
	}
	Matrix operator - (const Matrix &x) const {
		Matrix ans(_size);
		for (int i = 0; i < _size; i++) for (int j = 0; j < _size; j++) ans[i][j] = val[i][j] - x[i][j];
		return ans;
	}
	Matrix operator * (const T &x) const {
		Matrix ans(_size);
		for (int i = 0; i < _size; i++) for (int j = 0; j < _size; j++) ans[i][j] = val[i][j] * x;
		return ans;
	} 
	Matrix operator * (const Matrix &x) const {
		static constexpr int kCacheSize = 8 * 1024 * 1024 * sizeof(bool);
		static constexpr int kT = (1 << (__lg(kCacheSize) >> 1)) / sizeof(T);
		Matrix ans(_size);
		for (int I = 0; I < _size; I += kT) for (int J = 0; J < _size; J += kT) for (int K = 0; K < _size; K += kT) {
			int limi = min(I + kT, _size), limj = min(J + kT, _size), limk = min(K + kT, _size);
			for (int i = I; i < limi; i++) for (int j = J; j < limj; j++) {
				T sum = 0;
				for (int k = K; k < limk; k++) sum += val[i][k] * x[k][j];
				ans[i][j] += sum;
			}
		}
		return ans;
	} 
	Matrix operator / (const T &x) const {
		Matrix ans(_size);
		for (int i = 0; i < _size; i++) for (int j = 0; j < _size; j++) ans[i][j] = val[i][j] * x;
		return ans;
	}
	Matrix operator += (const Matrix &x) {return *this = *this + x;} 
	Matrix operator -= (const Matrix &x) {return *this = *this - x;} 
	Matrix operator *= (const T &x) {return *this = *this * x;} 
	Matrix operator *= (const Matrix &x) {return *this = *this * x;} 
	Matrix operator /= (const T &x) {return *this = *this / x;} 

	T det() const {
		Matrix tmp;
		tmp.copy(*this);
		bool flip = false;

		for (int i = 0; i < _size; i++) {
			if (Matrix_Inner::IsZero(tmp[i][i])) {
				int id = -1;
				for (int j = i + 1; j < _size; j++) if (!Matrix_Inner::IsZero(tmp[j][i])) {
					id = j;
					break;
				}
				if (id == -1) return 0;
				for (int j = i; j < _size; j++) swap(tmp[i][j], tmp[id][j]);
				flip = !flip;
			}

			for (int j = i + 1; j < _size; j++) if (!Matrix_Inner::IsZero(tmp[j][i])) {
				T freq(tmp[j][i] / tmp[i][i]);
				for (int k = i; k < _size; k++) tmp[j][k] -= freq * tmp[i][k];
			}
		}

		T ans = (flip ? -1 : 1);
		for (int i = 0; i < _size; i++) ans *= tmp[i][i];
		tmp.clear();
		return (ans + 0 - 0);
	}

	T det_piviting() const {
		// !!! not finished
		Matrix tmp;
		tmp.copy(*this);
		bool flip = false;

		for (int i = 0; i < _size; i++) {
			if (Matrix_Inner::IsZero(tmp[i][i])) {
				int id = -1;
				for (int j = i + 1; j < _size; j++) if (!Matrix_Inner::IsZero(tmp[j][i])) {
					id = j;
					break;
				}
				if (id == -1) return 0;
				for (int j = i; j < _size; j++) swap(tmp[i][j], tmp[id][j]);
				flip = !flip;
			}

			for (int j = i + 1; j < _size; j++) if (!Matrix_Inner::IsZero(tmp[j][i])) {
				T freq(tmp[j][i] / tmp[i][i]);
				for (int k = i; k < _size; k++) tmp[j][k] -= freq * tmp[i][k];
			}
		}

		T ans = (flip ? -1 : 1);
		for (int i = 0; i < _size; i++) ans *= tmp[i][i];
		tmp.clear();
		return ans;
	}

	void out() const {
		for (int i = 0; i < _size; i++, printf("\n")) for (int j = 0; j < _size; j++) printf("%5d", val[i][j]);
		return ;
	}
};

template <typename T1, typename T2> Matrix<T1> Pow(Matrix<T1> A, T2 b) {
	Matrix<T1> ans(A.size(), 1);
	for (; b; b >>= 1, A *= A) if (b & 1) ans *= A;
	return ans;
}
