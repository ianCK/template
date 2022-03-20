#pragma once

#include "SOS.h"

template <typename T> class SOSAdd : public tSOS<T> {
	private:
		void oper(T& lhs, const T& rhs) const override;
	public:
};
