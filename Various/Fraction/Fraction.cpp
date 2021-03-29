template <typename T> struct Fraction {
	constexpr static T gcd(T a, T b) {return b ? gcd(b, a % b) : a;}
	constexpr static T ABS(T n) {return n >= 0 ? n : -n;}

	static_assert(std::is_integral<T>::value);

	T p, q;
	Fraction (T a = 0, T b = 1) {p = a, q = b; pull();}
	void pull() {
		if (p == 0) p = 0, q = 1;
		else if (q == 0) p = p / ABS(p), q = 0;
		else {
			if (q < 0) p = -p, q = -q;
			T g = gcd(ABS(p), q);
			p /= g, q /= g;
		}
	}

	Fraction operator + (const Fraction &x) const {return Fraction(p * x.q + x.p * q, q * x.q);}
	Fraction operator - (const Fraction &x) const {return Fraction(p * x.q - x.p * q, q * x.q);}
	Fraction operator * (const Fraction &x) const {return Fraction(p * x.p, q * x.q);}
	Fraction operator / (const Fraction &x) const {return Fraction(p * x.q, q * x.p);}
	Fraction operator += (const Fraction &x) {return *this = *this + x;}
	Fraction operator -= (const Fraction &x) {return *this = *this - x;}
	Fraction operator *= (const Fraction &x) {return *this = *this * x;}
	Fraction operator /= (const Fraction &x) {return *this = *this / x;}

	bool operator < (const Fraction &x) const {return p * x.q < x.p * q;}
	bool operator > (const Fraction &x) const {return p * x.q > x.p * q;}
	bool operator == (const Fraction &x) const {return p == x.p && q == x.q;}
	bool operator != (const Fraction &x) const {return p != x.p || q != x.q;}
	bool operator <= (const Fraction &x) const {return p * x.q <= x.p * q;}
	bool operator >= (const Fraction &x) const {return p * x.q >= x.p * q;}

	void out() {
		Print(p); printf("/");
		Print(q); printf("\n");
		return ;
	}
};
