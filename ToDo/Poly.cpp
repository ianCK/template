#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#include "C:\Users\ianli\Desktop\CP\template\Math\Mod_Int.cpp"

struct Poly {
	int deg, size; // size >= 1 << (__lg(deg) + 2)
	vector<Mint> v;
	Poly() {size = 0;}
	Poly(int n) {
		size = 1 << (__lg(n - 1) + 2);
		v.resize(size);
	}
	//&Mint operator [] (size_t index) {return v[index];}
	Mint& operator [] (size_t index) {return v[index];}
	Mint operator ()(Mint x) const {
		Mint ans(0);
		for (int i = size - 1; i >= 0; i--) ans = ans * x + v[i];
		return ans;
	}

	Poly operator + (const Poly a) const {
		int mx = max(deg, a.deg), mn = min(deg, a.deg);
		Poly ans(mx);
		for (int i = 0; i < mn; i++) ans.v[i] = v[i] + a.v[i];
		// not done
		return ans;
	}

	Poly operator * (const Mint x) const {
		Poly ans(deg);
		for (int i = 0; i <= deg; i++) ans.v[i] = v[i] * x;
		return ans;
	}

	Poly operator << (const size_t x) const {
		Poly ans(deg + x);
		for (int i = 0; i <= deg; i++) ans.v[i + x] = v[i];
		return ans;
	}

	void operator /= (Mint x) {
		x = x.inv();
		for (int i = 0; i <= deg; i++) v[i] *= x;
		return ;
	}
	
	void operator >>= (const size_t x) {
		for (int i = x; i <= deg; i++) v[i - x] = v[i];
		deg -= x;
		// pull
		return ;
	}
};

Poly Exp(Poly a) {
	// not yet
	return a;
}

Poly Pow(Poly a, ll b) {
	int t = 0;
	Poly ans;
	Mint a0(1);
	while (a[t] == 0) t++;
	a >>= t;
	a0 = a[0];
	a /= a0;
	return (Exp(a * b) * Pow(a0, b)) << (t * b);
}

int main() {
}
