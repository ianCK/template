uint64_t Hash1(uint64_t x) {
  x ^= (x << 13), x ^= (x >> 7), x ^= (x << 17);
  return x;
}
uint64_t Hash2(uint64_t x) {
  uint64_t z = (x += 0x9e3779b97f4a7c15);
  z = (z ^ (z >> 30)) * 0xbf58476d1ce4e5b9;
  z = (z ^ (z >> 27)) * 0x94d049bb133111eb;
  return z ^ (z >> 31);
}
