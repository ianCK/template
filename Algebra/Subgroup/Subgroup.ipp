template <typename T, T (*op)(const T&, const T&)> constexpr Subgroup<T, op>::Subgroup() : val() {}
template <typename T, T (*op)(const T&, const T&)> constexpr Subgroup<T, op>::Subgroup(const T& _val) : val(_val) {}

template <typename T, T (*op)(const T&, const T&)> template <typename oT> constexpr Subgroup<T, op>::Subgroup(const oT& _val) : val(_val) {}

template <typename T, T (*op)(const T&, const T&)> constexpr Subgroup<T, op> Subgroup<T, op>::operator * (const Subgroup<T, op>& o) const { return op(val, o.value()); }
template <typename T, T (*op)(const T&, const T&)> constexpr const Subgroup<T, op>& Subgroup<T, op>::operator *= (const Subgroup<T, op>& o) { val = op(val, o.value()); return *this; }

template <typename T, T (*op)(const T&, const T&)> const T& Subgroup<T, op>::value() const { return val; }
template <typename T, T (*op)(const T&, const T&)> void Subgroup<T, op>::out(Output& output) const { output.W(val); }
