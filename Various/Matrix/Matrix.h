#pragma once

#include <CommonInclude/CommonInclude.h>
#include <Various/FastIO/Output/Output.h>

// template <typename T, int N, int M> class Matrix;
// template <typename T, int N> class Matrix<T, N, N>;

template <typename T, int N, int M = N> class Matrix {
	public:
		static constexpr int n = N;
		static constexpr int m = M;

		Matrix(int x = 0); // 0 -> init, other -> no init
		Matrix(const Matrix& o); // copy
		Matrix(Matrix&& o); // move

		constexpr Matrix operator + (const Matrix& o) const;
		constexpr Matrix operator - (const Matrix& o) const;
		template <int K> constexpr Matrix<T, N, K> operator * (const Matrix<T, M, K>& o) const;
		constexpr Matrix operator * (const T& x) const;
		constexpr Matrix operator / (const T& x) const;
		const Matrix& operator += (const Matrix& o);
		const Matrix& operator -= (const Matrix& o);
		const Matrix& operator *= (const T& x);
		const Matrix& operator /= (const T& x);

		constexpr Matrix<T, M, N> transpose() const;

		void out(Output& output) const;

		class constToken {
			public:
				constToken(const array<T, M>& _arr);
				constexpr T operator [] (int y) const;

			private:
				const array<T, M>& arr;
		};

		class Token {
			public:
				Token(array<T, M>& _arr);
				T& operator [] (int y);

			private:
				array<T, M>& arr;
		};

		constexpr constToken operator [](int x) const;
		constexpr Token operator [](int x);

	private:
		array<array<T, M>, N> val;
};

template <typename T, int N> class Matrix<T, N, N> {
	public:
		static constexpr int n = N;

		Matrix(int x = 0); // 0 -> init, other -> no init
		Matrix(const Matrix& o); // copy
		Matrix(Matrix&& o); // move

		constexpr Matrix operator + (const Matrix& o) const;
		constexpr Matrix operator - (const Matrix& o) const;
		template <int K> constexpr Matrix<T, N, K> operator * (const Matrix<T, N, K>& o) const {
			Matrix<T, N, K> ret;
			for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) for (int k = 0; k < K; k++) ret[i][k] += val[i][j] * o[j][k];
			return ret;
		}

		constexpr Matrix operator / (const Matrix& o) const;
		constexpr Matrix operator * (const T& x) const;
		constexpr Matrix operator / (const T& x) const;
		const Matrix& operator += (const Matrix& o);
		const Matrix& operator -= (const Matrix& o);
		const Matrix& operator *= (const Matrix& o);
		const Matrix& operator /= (const Matrix& o);
		const Matrix& operator *= (const T& x);
		const Matrix& operator /= (const T& x);

		constexpr T det() const;
		constexpr T trace() const; // sum of diagonal
		constexpr Matrix inverse() const;
		constexpr Matrix transpose() const;

		void out(Output& output) const;

		class constToken {
			public:
				constToken(const array<T, N>& _arr);
				constexpr T operator [] (int y) const;

			private:
				const array<T, N>& arr;
		};

		class Token {
			public:
				Token(array<T, N>& _arr);
				T& operator [] (int y);

			private:
				array<T, N>& arr;
		};


		constexpr constToken operator [](int x) const;
		constexpr Token operator [](int x);

	private:
		array<array<T, N>, N> val;
};

#include <Various/Matrix/Matrix.ipp>
