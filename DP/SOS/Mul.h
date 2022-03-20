#pragma once

#include "SOS.h"

template <typename T> class SOSMul : public tSOS<T> {
	private:
		void oper(T& lhs, const T& rhs) const override;
	public:
};

