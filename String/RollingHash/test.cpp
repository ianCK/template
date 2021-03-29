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
	#define Debug(x) ;
	#define Debugln(x) ;
	#define Debug_Array(n,x) ;
	#define Debugln_Array(n,x) ;
#else
	#define Debug(x) printf("%s :", (#x)); _Debug(x)
	#define Debugln(x) printf("%s :", (#x)); _Debugln(x)
	#define Debug_Array(n,x) printf("%s :", (#x)); _Debug_Array((n), (x))
	#define Debugln_Array(n,x) printf("%s :", (#x)); _Debugln_Array((n), (x))
#endif
typedef long long int ll;
typedef unsigned long long int ull;

constexpr int kN = int(1E5 + 10);
constexpr int kMod = 998244353;
// constexpr int kMod = int(1E9 + 7);
// constexpr int kInf = 0x3f3f3f3f;
// constexpr ll kInf = 0x3f3f3f3f3f3f3f3f;
// constexpr double kPi = acos(-1);
// constexpr double kEps = 1E-9;

#include "C:\Users\ianli\Desktop\CP\template\Various\Fast_IO\Fast_IO.cpp"
#include "C:\Users\ianli\Desktop\CP\template\Various\Useful_Functions\Useful_Functions.cpp"
#include "C:\Users\ianli\Desktop\CP\template\Various\Debug\Debug.cpp"
#include "C:\Users\ianli\Desktop\CP\template\Math\Mod_Int\Mod_Int.cpp"
#include "C:\Users\ianli\Desktop\CP\template\String\RollingHash\Hash.cpp"

RollingHash<Mint> hs;

int main() {
	string s; cin >> s;
	int n = int(s.size());

	hs.init(s);

	vector<int> v1, v2;
	for (int i = 1; i <= n; i++) {
		int l = 1, r = min(i, n - i + 1) + 1;
		while (r - l > 1) {
			int mid = (l + r) >> 1;
			if (hs.is_palindrome(i - mid + 1, i + mid - 1)) l = mid;
			else r = mid;
		}
		v1.PB(l * 2 - 1);
	}

	for (int i = 2; i <= n; i++) {
		if (s[i - 2] == s[i - 1]) {
			int l = 1, r = min(i - 1, n - i + 1) + 1;
			while (r - l > 1) {
				int mid = (l + r) >> 1;
				if (hs.is_palindrome(i - mid, i + mid - 1)) l = mid;
				else r = mid;
			}
			v2.PB(l * 2);
		}
		else v2.PB(0);
	}

	printf("%d", v1[0]); for (int i = 1; i < n; i++) printf(" %d %d", v2[i - 1], v1[i]); printf("\n");
}
