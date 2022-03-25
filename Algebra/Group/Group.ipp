template <typename T, T (*op)(const T&, const T&), T E, T (*inv)(const T&)> constexpr Group<T, op, E, inv>::Group() : val(identity) {}
template <typename T, T (*op)(const T&, const T&), T E, T (*inv)(const T&)> constexpr Group<T, op, E, inv>::Group(const T& _val) : val(_val) {}

template <typename T, T (*op)(const T&, const T&), T E, T (*inv)(const T&)> template <typename oT> constexpr Group<T, op, E, inv>::Group(const oT& _val) : val(_val) {}

template <typename T, T (*op)(const T&, const T&), T E, T (*inv)(const T&)> constexpr Group<T, op, E, inv> Group<T, op, E, inv>::operator * (const Group<T, op, E, inv>& o) const { return op(val, o.value()); }
template <typename T, T (*op)(const T&, const T&), T E, T (*inv)(const T&)> constexpr Group<T, op, E, inv> Group<T, op, E, inv>::operator / (const Group<T, op, E, inv>& o) const { return op(val, o.inverse()); }
template <typename T, T (*op)(const T&, const T&), T E, T (*inv)(const T&)> constexpr const Group<T, op, E, inv>& Group<T, op, E, inv>::operator *= (const Group<T, op, E, inv>& o) { val = op(val, o.value()); return *this; }
template <typename T, T (*op)(const T&, const T&), T E, T (*inv)(const T&)> constexpr const Group<T, op, E, inv>& Group<T, op, E, inv>::operator /= (const Group<T, op, E, inv>& o) { val = op(val, o.inverse()); return *this; }

template <typename T, T (*op)(const T&, const T&), T E, T (*inv)(const T&)> const T& Group<T, op, E, inv>::value() const { return val; }
template <typename T, T (*op)(const T&, const T&), T E, T (*inv)(const T&)> T Group<T, op, E, inv>::inverse() const { return inv(val); }

template <typename T, T (*op)(const T&, const T&), T E, T (*inv)(const T&)> void Group<T, op, E, inv>::out(Output& output) const { output.W(val); }


