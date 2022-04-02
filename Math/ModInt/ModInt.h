#pragma once

#include "../../Various/FastIO/Output/Output.h"

template <int mod> class ModInt {
	public:
		static constexpr int kMod = mod;

		ModInt();
		ModInt(int _val);

		void pull();

		constexpr ModInt operator - () const;
		constexpr ModInt operator + (const ModInt& o) const;
		constexpr ModInt operator - (const ModInt& o) const;
		constexpr ModInt operator * (const ModInt& o) const;
		constexpr ModInt operator / (const ModInt& o) const;
		const ModInt& operator += (const ModInt& o);
		const ModInt& operator -= (const ModInt& o);
		const ModInt& operator *= (const ModInt& o);
		const ModInt& operator /= (const ModInt& o);

		constexpr ModInt pow(int b) const;
		constexpr ModInt inv() const;
		constexpr int value() const;

		const ModInt& operator ++(int);
		const ModInt& operator --(int);

		constexpr bool operator <  (const ModInt &x) const;
		constexpr bool operator >  (const ModInt &x) const;
		constexpr bool operator <= (const ModInt &x) const;
		constexpr bool operator >= (const ModInt &x) const;
		constexpr bool operator == (const ModInt &x) const;
		constexpr bool operator != (const ModInt &x) const;

		void out(Output& output) const;

	private:
		int val;
};

#include "ModInt.ipp"
