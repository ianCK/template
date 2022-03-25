#pragma once

#include "../../Various/FastIO/Output/Output.h"

template <typename T, T (*op)(const T&, const T&), T E> class Monoid {
	public:
		static constexpr T identity = E;

		constexpr Monoid();
		constexpr Monoid(const T& _val);

		template <typename oT> constexpr Monoid(const oT& _val);

		constexpr Monoid operator * (const Monoid<T, op, E>& o) const;
		constexpr const Monoid& operator *= (const Monoid<T, op, E>& o);

		const T& value() const;
		void out(Output& output) const;

	private:
		T val;
};

#include "Monoid.ipp"

