bool IsPrime(uint64_t x) {
  constexpr uint32_t as = 9,
                     a[] = {2, 3, 5, 7, 11, 13, 17,
                       19, 23};
  for (uint32_t i = 0; i < as; i++) {
    if (x == a[i]) return true;
  }
  if (x < a[as - 1]) return false;
  uint64_t t = x - 1;
  int r = 0;
  while ((t & 1) == 0) {
    t >>= 1;
    r++;
  }
  for (uint32_t i = 0; i < as; i++) {
    bool ok = false;
    __int128 tt = PowMod(a[i], t, x);
    if (tt == 1) continue;
    for (int j = 0; j < r;
         j++, tt = (tt * tt % x)) {
      if (tt == x - 1) {
        ok = true;
        break;
      }
    }
    if (!ok) return false;
  }
  return true;
}
