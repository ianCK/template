#include "../../Various/Operator/Operator.h"

template <typename T> void SOSXor(int tot, T* arr) { return SOS<T, XOR<T>>(tot, arr); }

