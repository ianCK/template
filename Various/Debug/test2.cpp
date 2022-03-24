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
#include "C:\Users\ianli\Desktop\CP\template\Various\Useful_Functions\Useful_Functions.cpp"

#ifndef ONLINE_JUDGE
#include "C:\Users\ianli\Desktop\CP\template\Various\Debug\Debug.h"
#endif

// using Mint = Mod_Int<kMod>;

int abc[] = {0, 1, 2, 3, 3, 4, 2, 1};

int main() {
	FastIO IO;

	int a = 3;
	bool b = false;
	char c = 'A';
	double d = 0.3;
	float f = 0.2;
	long double lf = 0.14;


	Debug(a, b, c, d, f, lf);
	Debug(MTP(a, c));
	Debug(MTP(a, c, d, lf));
	Debug("Good!");

	DebugArray(7, abc);
	DebugArray0Ln(8, abc);
}
