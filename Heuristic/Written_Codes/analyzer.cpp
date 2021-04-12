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

ll score[kN];
pair<ll, int> p[kN];

int main() {
	// the scores of each cases are stored in "score"
	// n = the amount of testcases
	constexpr int n = 50;
	fstream input;
	input.open("score", ios::in);

	for (int i = 1; i <= n; i++) input >> score[i];

	input.close();

	double sum = 0, sqsum = 0;
	for (int i = 1; i <= n; i++) sum += score[i];
	for (int i = 1; i <= n; i++) sqsum += score[i] * score[i];
	
	double avg = sum / n;
	double sd = sqrt(sqsum / n - avg * avg);
	double se = sd / sqrt(n);

	printf("avg = %.0lf, sd = %.0lf, se = %.0lf\n", avg, sd, se);

	printf("95%% : %.0lf ~ %.0lf\n", avg - se * 2, avg + se * 2);
	printf("99%% : %.0lf ~ %.0lf\n", avg - se * 3, avg + se * 3);

	printf("95%% points : %.0lf ~ %.0lf\n", (avg - se * 2) * n, (avg + se * 2) * n);
	printf("99%% points : %.0lf ~ %.0lf\n", (avg - se * 3) * n, (avg + se * 3) * n);

	for (int i = 1; i <= n; i++) p[i] = MP(score[i], i);
	sort(p + 1, p + n + 1);

	printf("mean = %lld\n", p[n / 2].F);

	for (int i = 1; i <= 3; i++) printf("worst %d = testcase %2d, points = %lld\n", i, p[i].S, p[i].F);
	printf("\n");
	for (int i = 1; i <= 3; i++) printf("best  %d = testcase %2d, points = %lld\n", i, p[n + 1 - i].S, p[n + 1 - i].F);
}
