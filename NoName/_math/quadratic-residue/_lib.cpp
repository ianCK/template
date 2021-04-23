bool Check(int x, int p) {
  return PowMod(x, (p - 1) >> 1, p) == 1;
}
int QuadraticResidue(int a, int p) {
  a %= p;
  if (a < 0) a += p;
  if (!Check(a, p)) return -1;
  int b = -1;
  for (b = 2;; b++)
    if (!Check(b, p)) break;
  assert(b != -1);
  int inva = int(Inv(a, p)), t = 0;
  while ((p - 1) % (1 << t) == 0) t++;
  t--;
  int s = (p - 1) / (1 << t);
  int x = int(PowMod(a, (s + 1) >> 1, p));
  int w = int(PowMod(a, s, p));
  int k = 1;
  while (k < t) {
    if (PowMod(w, 1 << (t - k - 1), p) != 1) {
      x = 1LL * x *
        PowMod(b, ((1 << (k - 1)) * s), p) % p;
      w = 1LL * inva * PowMod(x, 2, p) % p;
    }
    k++;
  }
  return x;
}
