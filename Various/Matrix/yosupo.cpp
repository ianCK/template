#include <CommonInclude\CommonInclude.h>

constexpr int kN = 1024;
constexpr int kMod = 998244353;
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

#include <Math\ModInt\ModInt.h>
#include <Various\Matrix\Matrix.h>

using Mint = ModInt<kMod>;
using M = Matrix<Mint, kN, kN>;
FastIO IO;

int a[kN][kN];
int b[kN][kN];

int main() {
	int n, m, k; IO.RP(n, m, k);
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) IO.RP(a[i][j]);
	for (int i = 0; i < m; i++) for (int j = 0; j < k; j++) IO.RP(b[i][j]);

	M A, B;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) A[i][j] = a[i][j];
	for (int i = 0; i < m; i++) for (int j = 0; j < k; j++) B[i][j] = b[i][j];

	M C = A * B;
	for (int i = 0; i < n; i++) {
		IO.W(C[i][0]); for (int j = 1; j < k; j++) { IO.WSpace(); IO.W(C[i][j]); } IO.WLine();
	}

}
