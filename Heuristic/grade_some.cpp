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

int scores[kN];

int main() {
	System("g++ -O2 sol.cpp -o sol.exe");

	int cases; cin >> cases;
	vector<int> v(cases); for (int i = 0; i < cases; i++) cin >> v[i]; 

	bool first = true;
	for (int i : v) {
		if (first) {
			printf("running on testcase %3d", i);
			first = false;
		}
		else printf("\b\b\b%3d", i);
		System("sol < sample_in/" + my_to_string(4, i) + ".txt > sample_out/out" + my_to_string(4, i));
	}
	printf("\n");

	printf("calculating...\n");
	System("g++ -O2 grader.cpp -o grade.exe");
	for (int i : v) System("grade sample_in/" + my_to_string(4, i) + ".txt sample_out/out" + my_to_string(4, i) + " > score" + my_to_string(4, i));

	System_wait();

	for (int i : v) {
		fstream score;
		score.open("score" + my_to_string(4, i), ios::in);
		score >> scores[i];
		score.close();
		System("del score" + my_to_string(4, i));
	}

	for (int i : v) cout << "case " << my_to_string(4, i) << " : score = " << scores[i] << "\n";
}

