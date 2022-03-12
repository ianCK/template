#include <array>

constexpr int kN = 1000;

template <class T, int N>
constexpr std::array<T, N> Calc() {
    return {};
}

template <class T, int N, bool is_constexpr = false>
struct ArrayImpl {
	static std::array<T, N> data = Calc<T, N>();
};

template <class T, int N>
struct ArrayImpl<T, N, true> {
    static constexpr std::array<T, N> data = Calc<T, N>();
};

template <class T, int N>
using Array = ArrayImpl<T, N, (N < kN)>;

