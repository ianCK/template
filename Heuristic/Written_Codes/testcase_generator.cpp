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

double rng_double() {
	static random_device rd;
	static mt19937 eng(rd());
	static uniform_real_distribution<double> distr(0.0, 1.0);
	return distr(eng);
}

template <int l, int r> int rng_int() {
	static random_device rd;
	static mt19937 eng(rd());
	static uniform_int_distribution<int> distr(l, r);
	return distr(eng);
}

template <int l, int r> void rng_array(int n, int *a) {
	unordered_set<int> used;

	int cnt = 0;
	while (cnt < n) {
		int tmp = rng_int<l, r>();
		if (used.find(tmp) == used.end()) used.insert(a[++cnt] = tmp);
	}

	return ;
}

int x[kN], y[kN], r[kN], q[kN];

int main() {
	int seed; RP(seed);

	int n = int(50 * pow(4, rng_double()));
	for (int i = 1; i <= n; i++) x[i] = rng_int<0, 9999>();
	for (int i = 1; i <= n; i++) y[i] = rng_int<0, 9999>();

	rng_array<1, 99999999>(n - 1, q);
	sort(q + 1, q + n);

	q[0] = 0, q[n] = 100000000;
	for (int i = 1; i <= n; i++) r[i] = q[i] - q[i - 1];

	printf("%d\n", n);
	for (int i = 1; i <= n; i++) printf("%d %d %d\n", x[i], y[i], r[i]);
}
