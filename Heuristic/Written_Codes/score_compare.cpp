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

constexpr int n = 100;

ll A[kN], B[kN];

int main(const int argc, const char *argv[]) {
	Assert(argc == 3, "Usage : Compare [input] [output]");

	fstream inputA, inputB;
	inputA.open(argv[1], ios::in);
	inputB.open(argv[2], ios::in);

	for (int i = 0; i < n; i++) inputA >> A[i];
	for (int i = 0; i < n; i++) inputB >> B[i];

	inputA.close();
	inputB.close();

	vector<pair<ll, int>> va, vb;

	for (int i = 0; i < n; i++) 
		if (A[i] > B[i]) va.PB(MP(A[i] - B[i], i + 1));
		else if (A[i] < B[i]) vb.PB(MP(B[i] - A[i], i + 1));

	sort(va);
	printf("A count = %d\n", int(va.size()));
	printf("A min = (%d, %lld), A max = (%d, %lld)\n", va.front().S, va.front().F, va.back().S, va.back().F);

	sort(vb);
	printf("B count = %d\n", int(vb.size()));
	printf("B min = (%d, %lld), B max = (%d, %lld)\n", vb.front().S, vb.front().F, vb.back().S, vb.back().F);
}


