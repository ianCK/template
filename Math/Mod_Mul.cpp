constexpr uint64_t kMod = (1LL << 61) - 1;

uint64_t Mul(uint64_t a, uint64_t b) {
  uint64_t l1 = uint32_t(a), h1 = a >> 32, l2 = uint32_t(b), h2 = b >> 32;
  uint64_t l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;
  uint64_t ret = (l & kMod) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + 1;
  ret = (ret & kMod) + (ret >> 61);
  ret = (ret & kMod) + (ret >> 61);
  return ret - 1;
}
