constexpr uint64_t kModMP = (1LL << 61) - 1;
uint64_t ModMulMP(uint64_t a, uint64_t b) {
  uint64_t l1 = uint32_t(a), h1 = a >> 32,
           l2 = uint32_t(b), h2 = b >> 32;
  uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1,
           h = h1 * h2;
  uint64_t ret = (l & kModMP) + (l >> 61) +
    (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
  ret = (ret & kModMP) + (ret >> 61);
  ret = (ret & kModMP) + (ret >> 61);
  return ret - 1;
}
uint64_t Reduce(uint64_t a, uint64_t b,
  uint64_t m) {  // a % b + (0 or b)
  return a -
    uint64_t((__uint128_t(m) * a) >> 64) * b;
}
uint64_t ModMul64(
  uint64_t a, uint64_t b, uint64_t m) {
  int64_t ret =
    a * b - m * uint64_t(1.L / m * a * b);
  return ret + m * (ret < 0) -
    m * (ret >= int64_t(m));
}
