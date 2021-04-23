mt19937 rng;
uint64_t PollardRho(uint64_t x) {
  int64_t a = rng() % (x - 2) + 2, b = a;
  uint64_t c = rng() % (x - 1) + 1, d = 1;
  while (d == 1) {
    a = (__int128(a) * a + c) % x;
    b = (__int128(b) * b + c) % x;
    b = (__int128(b) * b + c) % x;
    d = __gcd(uint64_t(abs(a - b)), x);
    if (d == x) return PollardRho(x);
  }
  return d;
}
