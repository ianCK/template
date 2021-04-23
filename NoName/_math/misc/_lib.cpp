constexpr int64_t kMod = int64_t(1E9 + 7);
constexpr double kEps = 1E-10;
constexpr int64_t PowMod(
  int64_t x, int64_t e, int64_t m = kMod) {
  if (e == 0) return 1;
  __int128 t = PowMod(x, e / 2, m);
  t = t * t % m;
  if (e % 2 == 1) t = t * x % m;
  return int64_t(t);
}
int64_t Inv(int64_t x, int64_t p = kMod) {
  return PowMod(x, p - 2);
}
int64_t MulMod(
  int64_t x, int64_t y, int64_t m = kMod) {
  return x * y % m;
}
int64_t AddMod(
  int64_t x, int64_t y, int64_t m = kMod) {
  return (x + y) % m;
}
template <typename T>
tuple<T, T, T> ExtGcd(T a, T b) {
  // (d, x, y): ax + by = d, d = gcd(a, b)
  if (!b) return make_tuple(a, 1, 0);
  T d, x, y;
  tie(d, x, y) = ExtGcd(b, a % b);
  return make_tuple(d, y, x - (a / b) * y);
}
