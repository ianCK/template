#include "../../Various/Operator/Operator.h"

template <typename T> void SOSMul(int tot, T* arr) { return SOS<T, MUL<T>>(tot, arr); }
