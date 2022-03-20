#include "Mul.h"

#include "../../CommonInclude/CommonInclude.h"

template <typename T> void SOSMul<T>::oper(T& lhs, const T& rhs) const {
	lhs *= rhs;
	return ;
}

template class SOSMul<ui>;
template class SOSMul<int>;
template class SOSMul<ll>;
template class SOSMul<ull>;

template class SOSMul<double>;

