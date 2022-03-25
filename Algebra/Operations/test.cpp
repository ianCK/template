#include "C:\Users\ianli\Desktop\CP\template\CommonInclude\CommonInclude.h"

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

#include "C:\Users\ianli\Desktop\CP\template\Various\FastIO\FastIO.h"
#include "C:\Users\ianli\Desktop\CP\template\Various\UsefulFunctions\UsefulFunctions.h"

#ifndef ONLINE_JUDGE
#include "C:\Users\ianli\Desktop\CP\template\Various\Debug\Debug.h"
#endif

// using Mint = Mod_Int<kMod>;

#include "Operations.h"

int main() {
	FastIO IO;

	constexpr int a = OR(2, 4), b = MIN(2, 10);

	Debug(ADD(a, b), SUB(a, b), MUL(a, b), DIV(a, b));
	Debug(OR(a, b), AND(a, b), XOR(a, b));
	Debug(MIN(a, b), MAX(a, b));


}
