// "C:\Users\ianli\Desktop\CP\template\"
#include <bits/stdc++.h>
using namespace std;
#define PB push_back
#define F first
#define S second
#define MP make_pair
#define MTP make_tuple
typedef long long int ll;
constexpr int kN = int(1E5 + 10);
constexpr double kEps = 1E-9;

ll ABS(ll n) {return n >= 0 ? n : -n;}
ll gcd(ll a, ll b) {return b ? gcd (b, a % b) : a;}

int main() {
	//ios::sync_with_stdio(false);
	//cin.tie(0);

	int n;
	ll dx1, dx2, dy1, dy2, g;
	scanf("%d%lld%lld%lld%lld", &n, &dx1, &dy1, &dx2, &dy2);
	if (ABS(dx1 * dy2 - dx2 * dy1) != n) goto No;
	g = gcd(ABS(dx1), ABS(dx2));
	printf("YES\n");
	for (int i = 1; i <= g; i++) for (int j = 1; j <= n / g; j++) printf("%d %d\n", i, j);
	return 0;
No:
	printf("NO\n");
}
