void Ntt(
  vector<long long int> &v, bool on, int size) {
  long long int wn, u, t, w, inv;
  for (int i = 1, j = size >> 1, k; i < (size - 1);
       i++) {
    if (i < j) swap(v[i], v[j]);
    k = size >> 1;
    while (j & k) {
      j ^= k;
      k >>= 1;
    }
    j |= k;
  }
  for (int i = 2; i <= size; i <<= 1) {
    wn = on ?
      PowMod(3, (kMod - 1) / i, kMod) :
      PowMod(3, kMod - 1 - (kMod - 1) / i, kMod);
    for (int j = 0; j < size; j += i) {
      w = 1;
      for (int k = j; k < j + (i >> 1); k++) {
        u = v[k];
        t = (w * v[k + (i >> 1)]) % kMod;
        v[k] = (u + t) % kMod;
        v[k + (i >> 1)] = (u - t + kMod) % kMod;
        w = (w * wn) % kMod;
      }
    }
  }
  if (on) {
    inv = Inv(size);
    for (int i = 0; i < size; i++)
      v[i] = (v[i] * inv) % kMod;
  }
}
