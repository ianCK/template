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
#include "C:\Users\ianli\Desktop\CP\Atcoder\AHC\Utilities\System.cpp"
#include "C:\Users\ianli\Desktop\CP\Atcoder\AHC\Utilities\parsing.cpp"

constexpr int cases = 50;

int scores[kN], gen_cnt[kN], climbing_cnt[kN];

int main() {
	System("g++ -O2 speed.cpp -o speed.exe");

	for (int t = 1; t <= 5; t++) {
		for (int i = 1; i <= cases; i++) {
			if (i > 1) printf("\b\b\b%3d", i);
			else printf("running on testcase %3d", i);
			System("speed < sample_in/" + my_to_string(4, i) + ".txt > sample_out/out" + my_to_string(4, i));
		}
		printf("\n");

		printf("calculating...\n");

		for (int i = 1; i <= cases; i++) {
			fstream output;
			output.open("sample_out/out" + my_to_string(4, i), ios::in);
			output >> gen_cnt[i] >> climbing_cnt[i];
			output.close();
		}

		ll tot_gen_cnt = 0, tot_climbing_cnt = 0;
		for (int i = 1; i <= cases; i++) tot_gen_cnt += gen_cnt[i];
		for (int i = 1; i <= cases; i++) tot_climbing_cnt += climbing_cnt[i];

		printf("tot_gen_cnt = %lld, tot_climbing_cnt = %lld\n", tot_gen_cnt, tot_climbing_cnt);
	}
}
