#include <CommonInclude\CommonInclude.h>

#include <Various\FastIO\FastIO.h>
#include <Various\UsefulFunctions\UsefulFunctions.h>

#ifndef ONLINE_JUDGE
#include <Various\Debug\Debug.h>
#endif

constexpr int kN = 100'000 + 10; 
// constexpr int kMod = 998'244'353;
// constexpr int kMod = 1'000'000'000 + 7;
// constexpr int kInf = 0x3f3f3f3f;
// constexpr ll kInf = 0x3f3f3f3f3f3f3f3f;
// constexpr double kPi = acos(-1);
// constexpr double kEps = 1E-9;
// constexpr int dx[4] = {0, 0, 1, -1};
// constexpr int dy[4] = {1, -1, 0, 0};
// constexpr int dx[8] = {0, 0, 1, -1, 1, -1, 1, -1};
// constexpr int dy[8] = {1, -1, 1, -1, -1, 1, 0, 0};

// using Mint = ModInt<kMod>;
FastIO IO;

int abc[] = {0, 1, 2, 3, 3, 4, 2, 1};


int main()
{
	int a = 3;
	bool b = false;
	char c = 'A';
	double d = 0.3;
	float f = 0.2;
	long double lf = 0.14;

	bitset<10> bs;
	bs[2] = bs[5] = bs[9] = true;

	vector<int> vec = {1, 3, 5};
	vector<pair<double, char>> vec2 = {MP(0.3, 'A'), MP(1.32, 'B'), MP(1.45, 'Z')};

	vector<float> vecemp;

	stack<ll> st;
	st.push(3);
	st.push(1);
	st.push(2);

	queue<unsigned short> qu;
	qu.push(3);
	qu.push(1);
	qu.push(2);

	set<string> se;
	se.insert("abc");
	se.insert("cdf");
	se.insert("qqq");

	map<ull, bool> ma;
	ma[3] = false;
	ma[4] = true;
	ma[12345] = false;

	Debug(a, b, c, d, f, lf);
	Debug(MTP(a, c));
	Debug(MTP(a, c, d, lf));
	Debug(bs, vec, vec2);
	Debug(vecemp);
	Debug("Good!");

	Debug(st, qu);
	Debug(se, ma);

	DebugArray(7, abc);
	DebugArray0Ln(8, abc);
}
