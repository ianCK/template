#include "Xor.h"

#include "../../CommonInclude/CommonInclude.h"

template <typename T> void SOSXor<T>::oper(T& lhs, const T& rhs) const {
	lhs ^= rhs;
	return ;
}

template class SOSXor<ui>;
template class SOSXor<int>;
template class SOSXor<ll>;
template class SOSXor<ull>;
