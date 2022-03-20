#include "Add.h"

#include "../../CommonInclude/CommonInclude.h"

template <typename T> void SOSAdd<T>::oper(T& lhs, const T& rhs) const {
	lhs += rhs;
	return ;
}

template class SOSAdd<ui>;
template class SOSAdd<int>;
template class SOSAdd<ll>;
template class SOSAdd<ull>;

template class SOSAdd<double>;
