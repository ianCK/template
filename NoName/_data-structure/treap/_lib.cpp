// Merge two treaps, amortized log^2(n)
uint32_t Rng() {
  static uint32_t x = 71227123, y = 88030166;
  return y = x + y, x = y - x;
}
struct Treap;
Treap *Join(Treap *a, Treap *b);
void Split(
  uint32_t p, Treap *n, Treap *&a, Treap *&b);
int GetMin(Treap *n);
Treap *Merge(Treap *a, Treap *b) {
  if (!a || !b) return a ? a : b;
  int min_a = GetMin(a), min_b = GetMin(b);
  if (min_a > min_b) swap(a, b);
  Treap *tmp = nullptr;
  Split(min_b, a, a, tmp);
  return Merge(Join(a, b), tmp);
}
