#pragma once

#include "../../Various/FastIO/Output/Output.h"
#include "../Subgroup/Subgroup.h"

template <typename T, T (*op)(const T&, const T&), T E> class Monoid : public Subgroup<T, op> {
	using Subgroup<T, op>::Subgroup;

	public:
		static constexpr T identity = E;

		static_assert(op(identity, identity) == identity, "E * E != E");

		constexpr Monoid();
};

#include "Monoid.ipp"

