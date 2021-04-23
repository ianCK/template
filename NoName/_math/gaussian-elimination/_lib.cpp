void Gauss(vector<vector<double>> &v) {
  if (v.empty()) return;
  int n = int(v.size()), m = int(v[0].size());
  for (int i = 0; i < m; i++) {
    int p = -1;
    for (int j = i; j < n; j++) {
      if (abs(v[j][i]) < kEps) continue;
      if (p == -1 || abs(v[j][i]) > abs(v[p][i]))
        p = j;
    }
    if (p == -1) continue;
    for (int j = 0; j < m; j++)
      swap(v[p][j], v[i][j]);
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      double tmp = v[j][i] / v[i][i];
      for (int k = 0; k < m; k++)
        v[j][k] -= tmp * v[i][k];
    }
  }
  for (int i = n - 1; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      double tmp = v[j][i] / v[i][i];
      for (int k = 0; k < m; k++)
        v[j][k] -= tmp * v[i][k];
    }
  }
}
