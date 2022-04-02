#include <CommonInclude\CommonInclude.h>

constexpr int kN = int(1E5 + 10);
// constexpr int kMod = 998244353;
// constexpr int kMod = int(1E9 + 7);
// constexpr int kInf = 0x3f3f3f3f;
// constexpr ll kInf = 0x3f3f3f3f3f3f3f3f;
// constexpr double kPi = acos(-1);
// constexpr double kEps = 1E-9;
// constexpr int dx[4] = {0, 0, 1, -1};
// constexpr int dy[4] = {1, -1, 0, 0};
// constexpr int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
// constexpr int dy[8] = {1, -1, 1, -1, -1, 1, 0, 0};

#include <Various\FastIO\FastIO.h>
#include <Various\UsefulFunctions\UsefulFunctions.h>

#ifndef ONLINE_JUDGE
#include <Various\Debug\Debug.h>
#endif

// using Mint = Mod_Int<kMod>;
FastIO IO;

#include <Various\Matrix\Matrix.h>

int main() {
	Matrix<int, 3, 5> a, b;
	Matrix<int, 5, 4> c;
	Matrix<int, 4> d;
	// Matrix<int, 4, 4> c;

	for (int i = 0; i < 3; i++) for (int j = 0; j < 5; j++) a[i][j] = i * j;
	for (int i = 0; i < 3; i++) for (int j = 0; j < 5; j++) b[i][j] = i - j;

	for (int i = 0; i < 5; i++) for (int j = 0; j < 4; j++) c[i][j] = i * 2 + 1 + j;
	for (int i = 0; i < 4; i++) d[i][i] = 1;

	Debug(a, b, c, a + b, a * c, c.transpose() * a.transpose());
	Debug(d, c * d, d * c.transpose());

}
