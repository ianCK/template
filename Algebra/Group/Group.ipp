template <typename T, T (*op)(const T&, const T&), T E, T (*inv)(const T&)> constexpr Group<T, op, E, inv> Group<T, op, E, inv>::operator / (const Group<T, op, E, inv>& o) const { return op(Monoid<T, op, E>::val, o.inverse()); }
template <typename T, T (*op)(const T&, const T&), T E, T (*inv)(const T&)> constexpr const Group<T, op, E, inv>& Group<T, op, E, inv>::operator /= (const Group<T, op, E, inv>& o) { Monoid<T, op, E>::val = op(Monoid<T, op, E>::val, o.inverse()); return *this; }

template <typename T, T (*op)(const T&, const T&), T E, T (*inv)(const T&)> T Group<T, op, E, inv>::inverse() const { return inv(Monoid<T, op, E>::val); }
