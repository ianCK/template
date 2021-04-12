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

constexpr int kLen = 3;
constexpr int cases = 100;

int scores[kN];

int main() {
	System("g++ -O2 sol.cpp -o sol.exe");
	System("g++ -O2 grader.cpp -o grade.exe");

	for (int i = 1; i <= cases; i++) {
		if (i > 1) printf("\b\b\b%3d", i);
		else printf("running on testcase %3d", i);
		System("sol < in/in" + my_to_string(kLen, i) + " > out/out" + my_to_string(kLen, i));
	}
	printf("\n");

	printf("calculating...\n");
	for (int i = 1; i <= cases; i++) System("grade in/in" + my_to_string(kLen, i) + " out/out" + my_to_string(kLen, i) + " > score" + my_to_string(kLen, i));

	System_wait();

	for (int i = 1; i <= cases; i++) {
		fstream score;
		score.open("score" + my_to_string(kLen, i), ios::in);
		score >> scores[i];
		score.close();
		System("del score" + my_to_string(kLen, i));
	}

	ll tot_score = 0;
	for (int i = 1; i <= cases; i++) tot_score += scores[i];

	fstream score;
	score.open("score", ios::out);
	for (int i = 1; i <= cases; i++) score << scores[i] << "\n";
	score << "tot_score = " << tot_score << "\n";
	score.close();

	printf("tot_score = %lld, see details in score\n", tot_score);
	printf("\nAnalyze : \n");
	System("analyze");
}
