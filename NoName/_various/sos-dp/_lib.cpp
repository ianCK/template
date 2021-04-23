void f(int *dp, int m) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < (1 << m); j++) {
      if (j & (1 << i)) dp[j] += dp[j ^ (1 << i)];
    }
  }
}
