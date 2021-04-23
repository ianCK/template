constexpr int kN = 320000 + 6, kC = 10005,
              kD = 306;
int64_t pi_form[kN], phi_form[kC][kD],
  p2_form[kC][kD], p[kN];
bool prime[kN];
void Init() {
  memset(phi_form, 0, sizeof(phi_form));
  memset(p2_form, 0, sizeof(p2_form));
  prime[0] = prime[1] = 1;
  int id = 1;
  for (int i = 2; kN > i; i++) {
    if (!prime[i]) {
      for (int64_t j = 1LL * i * i; kN > j; j += i)
        prime[j] = 1;
      p[id++] = i;
    }
    pi_form[i] = pi_form[i - 1] + (!prime[i]);
  }
}
int64_t Pi(int64_t m);
int64_t P2(int64_t m, int64_t n) {
  if (m < kC && n < kD && p2_form[m][n] != -1)
    return p2_form[m][n];
  if (p[n] == 0) return 0;
  int64_t ret = 0, tmp = int64_t(sqrt(m) + 0.5);
  for (int64_t i = n + 1; p[i] <= tmp; i++)
    ret += Pi(m / p[i]) - Pi(p[i]) + 1;
  if (m < kC && n < kD) p2_form[m][n] = ret;
  return ret;
}
int64_t Phi2(int64_t m, int64_t n) {
  if (m < kC && n < kD && phi_form[m][n] != -1)
    return phi_form[m][n];
  if (!n) return m;
  if (p[n] >= m) return 1;
  if (m < kC && n < kD)
    return phi_form[m][n] = Phi2(m, n - 1) -
      Phi2(m / p[n], n - 1);
  return Phi2(m, n - 1) - Phi2(m / p[n], n - 1);
}
int64_t Pi(int64_t m) {
  if (m < kN) return pi_form[m];
  else {
    int64_t n = Pi(int64_t(ceil(cbrt(m))));
    return Phi2(m, n) + n - 1 - P2(m, n);
  }
}
// Init(); cout << Pi(n); (n <= 10^11)
