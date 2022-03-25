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

#include "../Operations/Operations.h"
#include "Group.h"

struct md {
	double val;

	constexpr md(double _val) : val(_val) {}
	md operator * (const md& o) const { return md(val * o.val); }
	md operator / (const md& o) const { return md(val / o.val); }

	void out(Output& output) const { return output.W(val); }
};

md rev(const md& x) { return md(1.0 / x.val); }
constexpr double rev(const double& x) { return 1 / x; }

int main() {
	FastIO IO;

	Group<int, ADD, 0, MINUS> a(3), b(5);

	Debug(a, b, a * b, a / b);

	// This is only valid in C++20
	// Group<double, MUL, double(1), rev> c(3), d(5);
	// Debug(c, d, c * d, c / d);

}
