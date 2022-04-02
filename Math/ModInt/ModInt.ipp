template <int mod> ModInt<mod>::ModInt() : val(0) {}
template <int mod> ModInt<mod>::ModInt(int _val) : val(_val) {}

template <int mod> void ModInt<mod>::pull() { val %= kMod; if (val < 0) val += kMod; return ; }

template <int mod> constexpr ModInt<mod> ModInt<mod>::operator - () const { return val ? ModInt(kMod - val) : ModInt(0); }
template <int mod> constexpr ModInt<mod> ModInt<mod>::operator + (const ModInt<mod>& o) const { 
	int tmp = val + o.value();
	return tmp >= kMod ? ModInt(tmp - kMod) : ModInt(tmp);
}

template <int mod> constexpr ModInt<mod> ModInt<mod>::operator - (const ModInt<mod>& o) const { 
	int tmp = val + o.value();
	return tmp < 0 ? ModInt(tmp + kMod) : ModInt(tmp);
}

template <int mod> constexpr ModInt<mod> ModInt<mod>::operator * (const ModInt<mod>& o) const { 
	return ModInt(1LL * val * o.value() % kMod); 
}

template <int mod> constexpr ModInt<mod> ModInt<mod>::operator / (const ModInt<mod>& o) const { 
	return (val % o.value()) ? ModInt(1LL * val * o.inv().value() % kMod) : ModInt(val / o.value()); 
}

template <int mod> const ModInt<mod>& ModInt<mod>::operator += (const ModInt<mod>& o) { return *this = *this + o; }
template <int mod> const ModInt<mod>& ModInt<mod>::operator -= (const ModInt<mod>& o) { return *this = *this - o; }
template <int mod> const ModInt<mod>& ModInt<mod>::operator *= (const ModInt<mod>& o) { return *this = *this * o; }
template <int mod> const ModInt<mod>& ModInt<mod>::operator /= (const ModInt<mod>& o) { return *this = *this / o; }

template <int mod> constexpr ModInt<mod> ModInt<mod>::pow(int b) const {
	ModInt ans(1), a(val);
	while (b) {
		if (b & 1) ans *= a;
		a *= a;
		b >>= 1;
	}
	return ans;
}
template <int mod> constexpr ModInt<mod> ModInt<mod>::inv() const { return pow(kMod - 2); }
template <int mod> constexpr int ModInt<mod>::value() const { return val; }

template <int mod> const ModInt<mod>& ModInt<mod>::operator ++(int) {
	val++;
	if (val == kMod) val = 0;
	return *this;
}

template <int mod> const ModInt<mod>& ModInt<mod>::operator --(int) {
	val--;
	if (val == -1) val = kMod - 1;
	return *this;
}

template <int mod> constexpr bool ModInt<mod>::operator <  (const ModInt<mod> &o) const { return val <  o.value(); }
template <int mod> constexpr bool ModInt<mod>::operator >  (const ModInt<mod> &o) const { return val >  o.value(); }
template <int mod> constexpr bool ModInt<mod>::operator <= (const ModInt<mod> &o) const { return val <= o.value(); }
template <int mod> constexpr bool ModInt<mod>::operator >= (const ModInt<mod> &o) const { return val >= o.value(); }
template <int mod> constexpr bool ModInt<mod>::operator == (const ModInt<mod> &o) const { return val == o.value(); }
template <int mod> constexpr bool ModInt<mod>::operator != (const ModInt<mod> &o) const { return val != o.value(); }

template <int mod> void ModInt<mod>::out(Output& output) const { return output.WP(val); }
