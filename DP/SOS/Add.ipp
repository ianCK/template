#include "../../Various/Operator/Operator.h"

template <typename T> void SOSAdd(int tot, T* arr) { return SOS<T, ADD<T>>(tot, arr); }
