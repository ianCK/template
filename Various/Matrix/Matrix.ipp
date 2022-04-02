// -- Start of N, M ---
template <typename T, int N, int M> Matrix<T, N, M>::Matrix(int x) { if (x == 0) val.fill({}); }
template <typename T, int N, int M> Matrix<T, N, M>::Matrix(const Matrix& o) : val(o.val) {}
template <typename T, int N, int M> Matrix<T, N, M>::Matrix(Matrix&& o) : val(move(o.val)) {}

template <typename T, int N, int M> constexpr Matrix<T, N, M> Matrix<T, N, M>::operator + (const Matrix& o) const {
	Matrix<T, N, M> ret(-1);
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) ret[i][j] = val[i][j] + o[i][j];
	return ret;
}
template <typename T, int N, int M> constexpr Matrix<T, N, M> Matrix<T, N, M>::operator - (const Matrix& o) const {
	Matrix<T, N, M> ret(-1);
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) ret[i][j] = val[i][j] - o[i][j];
	return ret;
}
template <typename T, int N, int M> template <int K> constexpr Matrix<T, N, K> Matrix<T, N, M>::operator * (const Matrix<T, M, K>& o) const {
	Matrix<T, N, K> ret;
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) for (int k = 0; k < K; k++) ret[i][k] += val[i][j] * o[j][k];
	return ret;
}
template <typename T, int N, int M> constexpr Matrix<T, N, M> Matrix<T, N, M>::operator * (const T& x) const {
	Matrix<T, N, M> ret(-1);
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) ret[i][j] = val[i][j] * x;
	return ret;
}
template <typename T, int N, int M> constexpr Matrix<T, N, M> Matrix<T, N, M>::operator / (const T& x) const {
	Matrix<T, N, M> ret(-1);
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) ret[i][j] = val[i][j] / x;
	return ret;
}

template <typename T, int N, int M> const Matrix<T, N, M>& Matrix<T, N, M>::operator += (const Matrix& o) { return *this = move(*this + o); }
template <typename T, int N, int M> const Matrix<T, N, M>& Matrix<T, N, M>::operator -= (const Matrix& o) { return *this = move(*this - o); }
template <typename T, int N, int M> const Matrix<T, N, M>& Matrix<T, N, M>::operator *= (const T& x) { return *this = move(*this * x); }
template <typename T, int N, int M> const Matrix<T, N, M>& Matrix<T, N, M>::operator /= (const T& x) { return *this = move(*this / x); }

template <typename T, int N, int M> constexpr Matrix<T, M, N> Matrix<T, N, M>::transpose() const {
	Matrix <T, M, N> ret(-1);
	for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) ret[j][i] = val[i][j];
	return ret;
}

template <typename T, int N, int M> void Matrix<T, N, M>::out(Output& output) const {
	output.WS("Matrix<"); output.WP(N); output.WS(", "); output.WP(M); output.WS("> :\n");
	for (int i = 0; i < N; i++) {
		output.WS("| "); output.W(val[i][0]); for (int j = 1; j < M; j++) { output.WS(", "); output.W(val[i][j]); } output.WS(" |\n");
	}
	return ;
}

template <typename T, int N, int M> Matrix<T, N, M>::constToken::constToken(const array<T, M>& _arr) : arr(_arr) {}
template <typename T, int N, int M> constexpr T Matrix<T, N, M>::constToken::operator [] (int y) const { return arr[y]; }

template <typename T, int N, int M> Matrix<T, N, M>::Token::Token(array<T, M>& _arr) : arr(_arr) {}
template <typename T, int N, int M> T& Matrix<T, N, M>::Token::operator [] (int y) { return arr[y]; }

template <typename T, int N, int M> constexpr typename Matrix<T, N, M>::constToken Matrix<T, N, M>::operator [](int x) const { return constToken(val[x]); }
template <typename T, int N, int M> constexpr typename Matrix<T, N, M>::Token Matrix<T, N, M>::operator [](int x) { return Token(val[x]); }
// --- End of N, M ---

// --- Start of N, N ---
template <typename T, int N> Matrix<T, N>::Matrix(int x) { if (x == 0) val.fill({}); }
template <typename T, int N> Matrix<T, N>::Matrix(const Matrix& o) : val(o.val) {}
template <typename T, int N> Matrix<T, N>::Matrix(Matrix&& o) : val(move(o.val)) {}

template <typename T, int N> constexpr Matrix<T, N> Matrix<T, N>::operator + (const Matrix& o) const {
	Matrix<T, N> ret(-1);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) ret[i][j] = val[i][j] + o[i][j];
	return ret;
}
template <typename T, int N> constexpr Matrix<T, N> Matrix<T, N>::operator - (const Matrix& o) const {
	Matrix<T, N> ret(-1);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) ret[i][j] = val[i][j] - o[i][j];
	return ret;
}
// template <typename T, int N> template <int K> constexpr Matrix<T, N, K>::operator * (const Matrix<T, N, K>& o) const {
// 	Matrix<T, N, K> ret;
// 	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) for (int k = 0; k < K; k++) ret[i][k] += val[i][j] * o[j][k];
// 	return ret;
// }
// Specialize for k = 1
// template <typename T, int N> template <> constexpr Matrix<T, N, 1>::operator * (const Matrix<T, N, 1>& o) const {
// }
// template <typename T, int N> constexpr Matrix<T, N> Matrix<T, N>::operator / (const Matrix& o) const;
template <typename T, int N> constexpr Matrix<T, N> Matrix<T, N>::operator * (const T& x) const {
	Matrix<T, N> ret(-1);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) ret[i][j] = val[i][j] * x;
	return ret;
}
template <typename T, int N> constexpr Matrix<T, N> Matrix<T, N>::operator / (const T& x) const {
	Matrix<T, N> ret(-1);
	for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) ret[i][j] = val[i][j] * x;
	return ret;
}

template <typename T, int N> const Matrix<T, N>& Matrix<T, N>::operator += (const Matrix& o) { return *this = move(*this + o); }
template <typename T, int N> const Matrix<T, N>& Matrix<T, N>::operator -= (const Matrix& o) { return *this = move(*this - o); }
template <typename T, int N> const Matrix<T, N>& Matrix<T, N>::operator *= (const Matrix& o) { return *this = move(*this * o); }
// template <typename T, int N> const Matrix<T, N>& Matrix<T, N>::operator /= (const Matrix& o) { return *this = move(*this / o); }
template <typename T, int N> const Matrix<T, N>& Matrix<T, N>::operator *= (const T& x) { return *this = move(*this * x); }
template <typename T, int N> const Matrix<T, N>& Matrix<T, N>::operator /= (const T& x) { return *this = move(*this / x); }

// template <typename T, int N> constexpr T Matrix<T, N>::det() const;
// piviting
// template <int N> constexpr double Matrix<double, N>:: det() const;

template <typename T, int N> constexpr T Matrix<T, N>::trace() const {
	T ans(val[0][0]);
	for (int i = 1; i < N; i++) ans += val[i][i];
	return ans;
}

// template <typename T, int N> constexpr Matrix<T, N> Matrix<T, N>inverse() const;
// template <typename T, int N> constexpr Matrix<T, N> Matrix<T, N>transpose() const;

template <typename T, int N> void Matrix<T, N>::out(Output& output) const {
	output.WS("Matrix<"); output.WP(N); output.WS("> :\n");
	for (int i = 0; i < N; i++) {
		output.WS("| "); output.W(val[i][0]); for (int j = 1; j < N; j++) { output.WS(", "); output.W(val[i][j]); } output.WS(" |\n");
	}
	return ;
}

template <typename T, int N> Matrix<T, N>::constToken::constToken(const array<T, N>& _arr) : arr(_arr) {}
template <typename T, int N> constexpr T Matrix<T, N>::constToken::operator [] (int y) const { return arr[y]; }

template <typename T, int N> Matrix<T, N>::Token::Token(array<T, N>& _arr) : arr(_arr) {}
template <typename T, int N> T& Matrix<T, N>::Token::operator [] (int y) { return arr[y]; }

template <typename T, int N> constexpr typename Matrix<T, N>::constToken Matrix<T, N>::operator [](int x) const { return constToken(val[x]); }
template <typename T, int N> constexpr typename Matrix<T, N>::Token Matrix<T, N>::operator [](int x) { return Token(val[x]); }
// --- End of N, N ---
