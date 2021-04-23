using InfInt = uint64_t;  // Stub
InfInt F(int64_t _p, int64_t _q, int64_t _n) {
  int64_t _t = __gcd(_p, _q);
  _p = _p / _t;
  _q = _q / _t;
  InfInt p = _p, q = _q, n = _n, t = _t, s = 0,
         z = 1;
  while (q > 0 && n > 0) {
    t = p / q;
    s += z * t * n * (n + 1) / 2;
    p -= q * t;
    t = n / q;
    s += z * p * t * (n + 1) -
      z * t * (p * q * t + p + q - 1) / 2;
    n -= q * t;
    t = n * p / q;
    s += z * t * n;
    n = t;
    swap(p, q);
    z = -z;
  }
  return s;
}
