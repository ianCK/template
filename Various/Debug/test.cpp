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
#ifdef ONLINE_JUDGE
	#define Debug(...) ;
	#define Debug_Array(n,x) ;
	#define NL ;
#else
	#define Debug(...) {printf("(%s) = ", (#__VA_ARGS__)), _print(__VA_ARGS__), printf("\n");}
	#define Debug_Array(n,x) {for (int i = 1; i <= n; i++) {printf("%s", (#x)); printf("[%d] = ", i); _print(x[i]); printf("\n");}}
	#define NL printf("\n")
#endif
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

int abc[] = {0, 1, 2, 3, 3, 4, 2, 1};

int main() {
	int a = 3;
	bool b = false;
	char c = 'A';
	Debug(a, b, c);

	Debug_Array(7, abc);
}
