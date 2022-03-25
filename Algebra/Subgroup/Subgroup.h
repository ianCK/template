#pragma once

#include "../../Various/FastIO/Output/Output.h"

template <typename T, T (*op)(const T&, const T&)> class Subgroup {
	public:
		constexpr Subgroup();
		constexpr Subgroup(const T& _val);

		template <typename oT> constexpr Subgroup(const oT& _val);

		constexpr Subgroup operator * (const Subgroup<T, op>& o) const;
		constexpr const Subgroup& operator *= (const Subgroup<T, op>& o);

		const T& value() const;
		void out(Output& output) const;

	private:
		T val;
};

#include "Subgroup.ipp"