template <typename T> T ADD(T lhs, T rhs) { return lhs + rhs; }
template <typename T> T SUB(T lhs, T rhs) { return lhs - rhs; }
template <typename T> T MUL(T lhs, T rhs) { return lhs * rhs; }
template <typename T> T DIV(T lhs, T rhs) { return lhs / rhs; }

template <typename T> T  OR(T lhs, T rhs) { return lhs | rhs; }
template <typename T> T AND(T lhs, T rhs) { return lhs & rhs; }
template <typename T> T XOR(T lhs, T rhs) { return lhs ^ rhs; }

template <typename T> T MAX(T lhs, T rhs) { return lhs < rhs ? rhs : lhs; }
template <typename T> T MIN(T lhs, T rhs) { return lhs < rhs ? lhs : rhs; }
