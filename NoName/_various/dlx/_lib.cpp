constexpr int kC = 1005, kR = 10005, kNode = 20005;
struct Dlx {
  int ansd, ans[kR], sz, S[kC];
  int row[kNode], col[kNode];
  int L[kNode], R[kNode], U[kNode], D[kNode];
  void Init(int m) {
    for (int i = 0; i <= m; i++) {
      U[i] = i, D[i] = i, L[i] = i - 1,
      R[i] = i + 1;
    }
    L[0] = m, R[m] = 0;
    sz = m + 1;
    for (int i = 0; i <= m; i++) S[i] = 0;
  }
  void AddRow(int r, const vector<int> &column) {
    int first = sz;
    for (auto c : column) {
      L[sz] = sz - 1, R[sz] = sz + 1;
      D[sz] = c, U[sz] = U[c];
      D[U[c]] = sz, U[c] = sz;
      row[sz] = r, col[sz] = c;
      S[c]++;
      sz++;
    }
    L[first] = sz - 1, R[sz - 1] = first;
  }
#define ITER(i, A, st) \
  for (int i = A[st]; i != st; i = A[i])
  void Remove(int c) {
    L[R[c]] = L[c];
    R[L[c]] = R[c];
    ITER(i, D, c) ITER(j, R, i) {
      U[D[j]] = U[j];
      D[U[j]] = D[j];
      --S[col[j]];
    }
  }
  void Restore(int c) {
    ITER(i, U, c) ITER(j, L, i) {
      U[D[j]] = j;
      D[U[j]] = j;
      ++S[col[j]];
    }
    L[R[c]] = c;
    R[L[c]] = c;
  }
  bool Dfs(int d) {
    if (R[0] == 0) {
      ansd = d;
      return true;
    }
    int c = R[0];
    ITER(i, R, 0) if (S[i] < S[c]) c = i;
    Remove(c);
    ITER(i, D, c) {
      ans[d] = row[i];
      ITER(j, R, i) Remove(col[j]);
      if (Dfs(d + 1)) return true;
      ITER(j, L, i) Restore(col[j]);
    }
    Restore(c);
    return false;
  }
  bool Solve() { return Dfs(0); }
} solver;
