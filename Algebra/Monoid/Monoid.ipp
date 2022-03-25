template <typename T, T (*op)(const T&, const T&), T E> constexpr Monoid<T, op, E>::Monoid() : val(identity) {}
template <typename T, T (*op)(const T&, const T&), T E> constexpr Monoid<T, op, E>::Monoid(const T& _val) : val(_val) {}

template <typename T, T (*op)(const T&, const T&), T E> template <typename oT> constexpr Monoid<T, op, E>::Monoid(const oT& _val) : val(_val) {}

template <typename T, T (*op)(const T&, const T&), T E> constexpr Monoid<T, op, E> Monoid<T, op, E>::operator * (const Monoid<T, op, E>& o) const { return op(val, o.value()); }
template <typename T, T (*op)(const T&, const T&), T E> constexpr const Monoid<T, op, E>& Monoid<T, op, E>::operator *= (const Monoid<T, op, E>& o) { val = op(val, o.value()); return *this; }

template <typename T, T (*op)(const T&, const T&), T E> const T& Monoid<T, op, E>::value() const { return val; }
template <typename T, T (*op)(const T&, const T&), T E> void Monoid<T, op, E>::out(Output& output) const { output.W(val); }

