#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define MTP make_tuple
#define R Read
#define RD Read_Digit
#define RP Read_P
#define RL Read_Loop
#define RLD Read_Loop_Digit
#define RLP Read_Loop_P
typedef long long int ll;
typedef unsigned long long int ull;

constexpr int kN = int(1E5 + 10);
// constexpr int kMod = 998244353;
// constexpr int kMod = int(1E9 + 7);
// constexpr int kInf = 0x3f3f3f3f;
// constexpr ll kInf = 0x3f3f3f3f3f3f3f3f;
// constexpr double kPi = acos(-1);
// constexpr double kEps = 1E-9;

#include "C:\Users\ianli\Desktop\CP\template\Various\Fast_IO\Fast_IO.cpp"
#include "C:\Users\ianli\Desktop\CP\template\Various\Useful_Functions\Useful_Functions.cpp"
#include "C:\Users\ianli\Desktop\CP\template\Various\Debug\Debug.cpp"

int x[kN], y[kN], r[kN];

int main() {
	int n; RP(n);
	RLP(n, x, y, r);

	Assert(n >= 50, "n = " + to_string(n) + " should be at least 50");
	Assert(n <= 200, "n = " + to_string(n) + " should be at most 200");

	for (int i = 1; i <= n; i++) {
		Assert(x[i] >= 0, "x[" + to_string(i) + "] = " + to_string(x[i]) + " should be at least 0");
		Assert(x[i] <= 9999, "x[" + to_string(i) + "] = " + to_string(x[i]) + " should be at most 9999");
		Assert(y[i] >= 0, "y[" + to_string(i) + "] = " + to_string(y[i]) + " should be at least 0");
		Assert(y[i] <= 9999, "y[" + to_string(i) + "] = " + to_string(y[i]) + " should be at most 9999");
		Assert(r[i] >= 1, "r[" + to_string(i) + "] = " + to_string(r[i]) + " should be at least 1");
	}

	ll sum = 0;
	for (int i = 1; i <= n; i++) sum += r[i];
	Assert(sum == 100000000, "sum of r should be equal to 100000000");

	printf("This testcase is valid\n");
}
