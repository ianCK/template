#pragma once

#include "../../Various/FastIO/Output/Output.h"

template <typename T, T (*op)(const T&, const T&), T E, T (*inv)(const T&)> class Group {
	public:
		static constexpr T identity = E;

		static_assert(op(identity, identity) == identity, "E * E != E");
		static_assert(inv(identity) == identity, "E^-1 != E");

		constexpr Group();
		constexpr Group(const T& _val);

		template <typename oT> constexpr Group(const oT& _val);

		constexpr Group operator * (const Group<T, op, E, inv>& o) const;
		constexpr Group operator / (const Group<T, op, E, inv>& o) const;
		constexpr const Group& operator *= (const Group<T, op, E, inv>& o);
		constexpr const Group& operator /= (const Group<T, op, E, inv>& o);

		const T& value() const;
		T inverse() const;

		void out(Output& output) const;

	private:
		T val;
};

#include "Group.ipp"


