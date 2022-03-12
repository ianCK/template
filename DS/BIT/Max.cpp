#include "Max.h"

template<> int BIT_max<int>::defaultValue() const {return -0x3f3f3f3f;}
template<> long long int BIT_max<long long int>::defaultValue() const {return -0x3f3f3f3f3f3f3f3f;}
