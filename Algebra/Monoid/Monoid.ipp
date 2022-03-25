template <typename T, T (*op)(const T&, const T&), T E> constexpr Monoid<T, op, E>::Monoid() : Subgroup<T, op>::val(identity) {}
