constexpr int kTh = 1000000;  // N^(2/3)
// \lfloor \frac{n}{x} \rfloor is a perfect hash
unordered_map<int64_t, int64_t> mem;
template <class Func>
int64_t Calc(int64_t x, int64_t g1, Func p_f,
  Func p_g, Func p_fg) {
  if (x <= kTh) return p_f(x);
  auto d = mem.find(x);
  if (d != mem.end()) return d->second;
  long long ans = 0;
  for (long long i = 2, la; i <= x; i = la + 1) {
    la = x / (x / i);
    ans = ans +
      (p_g(la) - p_g(i - 1) + kMod) *
        Calc(x / i, g1, p_f, p_g, p_fg);
  }
  ans = p_fg(x) - ans;
  ans = ans / g1;
  return mem[x] = ans;
}
