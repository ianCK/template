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
#include "C:\Users\ianli\Desktop\CP\Atcoder\AHC\Utilities\random.cpp"
#include "C:\Users\ianli\Desktop\CP\Atcoder\AHC\Utilities\System.cpp"
#include "C:\Users\ianli\Desktop\CP\Atcoder\AHC\Utilities\parsing.cpp"

constexpr int kLen = 3;

int main() {
	System("g++ testcase_generator.cpp -o generate_testcase");
	System("g++ testcase_checker.cpp -o check_testcase");

	int cases; RP(cases);

	for (int i = 1; i <= cases; i++) 
		System("echo " + to_string(rng_int<0, numeric_limits<int>::max()>()) + " | generate_testcase > input/in" + my_to_string(kLen, i));

	for (int i = 1; i <= cases; i++)
		System("check_testcase < input/in" + my_to_string(kLen, i));

	printf("generated %d testcases successfully\n", cases);
}
