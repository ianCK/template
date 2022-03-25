#pragma once

// --- unary ---
template <typename T> constexpr T MINUS(const T& x);
template <typename T> constexpr T NOT(const T& x);

// --- binary ---
template <typename T> constexpr T ADD(const T& lhs, const T& rhs);
template <typename T> constexpr T SUB(const T& lhs, const T& rhs);
template <typename T> constexpr T MUL(const T& lhs, const T& rhs);
template <typename T> constexpr T DIV(const T& lhs, const T& rhs);

template <typename T> constexpr T  OR(const T& lhs, const T& rhs);
template <typename T> constexpr T AND(const T& lhs, const T& rhs);
template <typename T> constexpr T XOR(const T& lhs, const T& rhs);

template <typename T> constexpr T MAX(const T& lhs, const T& rhs);
template <typename T> constexpr T MIN(const T& lhs, const T& rhs);

#include "Operations.ipp"
