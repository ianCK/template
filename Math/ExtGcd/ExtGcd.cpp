// (d, x, y): ax + by = d, d = gcd(a, b)
template <typename T> tuple<T, T, T> ExtGcd(T a, T b) {
	if (!b) return make_tuple(a, 1, 0);
	T d, x, y;
	tie(d, x, y) = ExtGcd(b, a % b);
	return make_tuple(d, y, x - (a / b) * y);
}
