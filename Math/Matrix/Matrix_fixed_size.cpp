template <typename T, int kN> struct Matrix {
	T val[kN][kN];
	int _size;

	Matrix() : _size(0) {}
	Matrix(int x, T v = 0) {
		_size = x;
		for (int i = 0; i < _size; i++) {
			memset(val[i], 0, sizeof(T) * _size);
			val[i][i] = v;
		}
	}

	void resize(int x) {
		_size = x;
		for (int i = 0; i < _size; i++) memset(val[i], 0, sizeof(T) * _size);
		return ;
	}
	int size() const {return _size;}

	Matrix operator = (const Matrix &x) {
		_size = x._size;
		for (int i = 0; i < _size; i++) memcpy(val[i], x[i], sizeof(T) * _size);
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
		Matrix tmp = *this;
		bool flip = false;

		for (int i = 0; i < _size; i++) {
			int id = -1;
			if (tmp[i][i] != 0) id = i;
			else {
				for (int j = i + 1; j < _size; j++) if (tmp[j][i] != 0) {
					id = j;
					break;
				}
				if (id == -1) return 0;
				for (int j = i; j < _size; j++) swap(tmp[i][j], tmp[id][j]);
				flip = !flip;
			}

			for (int j = i + 1; j < _size; j++) {
				if (tmp[j][i] == 0) continue;
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

template <typename T1, int kN, typename T2> Matrix<T1, kN> Pow(Matrix<T1, kN> A, T2 b) {
	Matrix<T1, kN> ans(A.size(), 1);
	for (; b; b >>= 1, A *= A) if (b & 1) ans *= A;
	return ans;
}
