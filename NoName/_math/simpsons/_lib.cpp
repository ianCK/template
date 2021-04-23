#define S(a, b) \
  (f(a) + 4 * f((a + b) / 2) + f(b)) * (b - a) / 6
template <class F>
double Rec(
  F& f, double a, double b, double eps, double S) {
  double c = (a + b) / 2;
  double S1 = S(a, c), S2 = S(c, b), T = S1 + S2;
  if (abs(T - S) <= 15 * eps || b - a < 1e-10)
    return T + (T - S) / 15;
  return Rec(f, a, c, eps / 2, S1) +
    Rec(f, c, b, eps / 2, S2);
}
template <class F>
double Quad(double a, double b, F f) {
  return Rec(f, a, b, kEps, S(a, b));
}
