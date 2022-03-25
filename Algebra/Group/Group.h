#pragma once

#include "../../Various/FastIO/Output/Output.h"
#include "../Monoid/Monoid.h"

template <typename T, T (*op)(const T&, const T&), T E, T (*inv)(const T&)> class Group : public Monoid<T, op, E> {
	using Monoid<T, op, E>::Monoid;

	public:

		static_assert(inv(Monoid<T, op, E>::identity) == Monoid<T, op, E>::identity, "E^-1 != E");

		constexpr Group operator / (const Group<T, op, E, inv>& o) const;
		constexpr const Group& operator /= (const Group<T, op, E, inv>& o);

		T inverse() const;
};

#include "Group.ipp"


