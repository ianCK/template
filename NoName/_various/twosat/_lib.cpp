void TwoSat(int n, const int *topo, const int *scc,
  int *sat) {
  // Build SCC
  // unsatisfiable if scc[i] == scc[~i]
  for (int i = 0; i < n + n; ++i) {
    int x = topo[i];
    if (sat[scc[x]] == -1) {
      sat[scc[x]] = 0;
      sat[scc[~x]] = 1;
    }
  }
}
