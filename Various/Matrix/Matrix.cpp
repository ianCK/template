#include <bits/stdc++.h>
using namespace std;
template <typename T, int size> struct Matrix {
	T val[size][size];
	Matrix() {memset(val, 0, sizeof(val));}
	Matrix(T x) {
		memset(val, 0, sizeof(val));
		for (int i = 0; i < size; i++) val[i][i] = x;
	}

	struct _token {
		Matrix* pointer;
		int x;
		_token (Matrix* m, int _x) {pointer = m, x = _x;}
		T& operator [](int y) {return pointer -> val[x][y];}
	};

	_token operator [](int x) {return _token(this, x);}

	Matrix operator + (const Matrix &x) const {
		Matrix tmp;
		for (int i = 0; i < size; i++) for (int j = 0; j < size; j++) tmp[i][j] += x[i][j];
		return tmp;
	}
	Matrix operator - (const Matrix &x) const {
		Matrix tmp;
		for (int i = 0; i < size; i++) for (int j = 0; j < size; j++) tmp[i][j] -= x[i][j];
		return tmp;
	}
	Matrix operator * (const Matrix &x) const {}
	Matrix operator * (const T &x) const {}
	Matrix operator / (const T &x) const {}
	Matrix operator += (const Matrix &x) {return *this = *this + x;}
	Matrix operator -= (const Matrix &x) {return *this = *this - x;}
	Matrix operator *= (const Matrix &x) {return *this = *this * x;}
	Matrix operator *= (const T &x) {return *this = *this * x;}
	Matrix operator /= (const T &x) {return *this = *this / x;}

	void out() {
		for (int i = 0; i < size; i++, printf("\n")) for (int j = 0; j < size; j++) printf(" %d", val[i][j]);
	}
};

int main() {
	Matrix<int, 5> a(1), b(2);
	(a + b).out();
}
