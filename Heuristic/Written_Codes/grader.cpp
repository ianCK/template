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
#include "C:\Users\ianli\Desktop\CP\template\Heuristic\Assert.cpp"

int n;
int x[kN], y[kN], r[kN], a[kN], b[kN], c[kN], d[kN];

int main(const int argc, const char *argv[]) {
	Assert(argc == 3, "Usage : grade [input] [output]");

	fstream input, output;
	input.open(argv[1], ios::in);
	output.open(argv[2], ios::in);
	
	// ---read---

	input.close();
	output.close();

	// ---check---

	for (int i = 1; i <= n; i++) {
		Assert(a[i] < c[i], "a[" + to_string(i) + "] = " + to_string(a[i]) + " should be lesser than"
					 						+ "c[" + to_string(i) + "] = " + to_string(c[i]));
		Assert(b[i] < d[i], "b[" + to_string(i) + "] = " + to_string(b[i]) + " should be lesser than"
					 						+ "d[" + to_string(i) + "] = " + to_string(d[i]));
	}

	for (int i = 1; i <= n; i++) for (int j = i + 1; j <= n; j++) {
		if (max(a[i], a[j]) < min(c[i], c[j]) && max(b[i], b[j]) < min(d[i], d[j])) {
			printf("rectangle %d and rectangle %d intersects\n", i, j);
			printf("rectangle %d : (%d, %d, %d, %d)\n", i, a[i], b[i], c[i], d[i]);
			printf("rectangle %d : (%d, %d, %d, %d)\n", j, a[j], b[j], c[j], d[j]);
			assert(false);
		}
	}

	// ---cal---

	double ans = 0;

	for (int i = 1; i <= n; i++) {
		if (a[i] <= x[i] && x[i] < c[i] &&
				b[i] <= y[i] && y[i] < d[i]) {
			int s = (c[i] - a[i]) * (d[i] - b[i]);
			long double tmp = (long double)min(r[i], s) / max(r[i], s);
			ans += 1.0 - (1.0 - tmp) * (1.0 - tmp);
		}
	}

	ans = round(1E9 * ans / n);
	printf("%.0lf\n", ans);
}
