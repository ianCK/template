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

constexpr int n = 50;

int gen[kN], single[kN], beam[kN];

int main() {
	fstream input;
	input.open("score_gen", ios::in);
	for (int i = 0; i < 50; i++) input >> gen[i];
	input.close();
	input.open("score_single", ios::in);
	for (int i = 0; i < 50; i++) input >> single[i];
	input.close();
	input.open("score_beam", ios::in);
	for (int i = 0; i < 50; i++) input >> beam[i];
	input.close();

	vector<pair<int, int>> vs, vb;

	for (int i = 0; i < 50; i++) 
		if (single[i] > beam[i]) vs.PB(MP(gen[i], single[i] - beam[i]));
		else vb.PB(MP(gen[i], beam[i] - single[i]));

	sort(vs);
	printf("single count = %d\n", int(vs.size()));
	printf("single min = %d, single max = %d\n", vs.front().F, vs.back().F);
	sort(vb);
	printf("beam count = %d\n", int(vb.size()));
	printf("beam min = %d, beam max = %d\n", vb.front().F, vb.back().F);

	printf("vs :\n");
	for (pair<int, int> i : vs) printf("%d %d\n", i.F, i.S);

	printf("vb :\n");
	for (pair<int, int> i : vb) printf("%d %d\n", i.F, i.S);
}
