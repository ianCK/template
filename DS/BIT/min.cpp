#include "Min.h"

template<> int BIT_min<int>::defaultValue() const {return 0x3f3f3f3f;}
template<> long long int BIT_min<long long int>::defaultValue() const {return 0x3f3f3f3f3f3f3f3f;}

