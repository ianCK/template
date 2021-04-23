#include <cstring>
#include <iostream>
using std::cin;
using std::cout;
const int MAXN = 100, INF = 1 << 20;
char str[MAXN];
int dp[MAXN][MAXN], z[MAXN];
#include "_lib.cpp"
int dfs(int l, int r) {
  if (l == r) return 1;
  if (dp[l][r]) return dp[l][r];
  int res = INF;
  for (int k = l; k < r; k++)
    res = std::min(res, dfs(l, k) + dfs(k + 1, r));
  int len = r - l + 1;
  zalg(str + l, len, z);
  for (int i = 1; i < len; i++) {
    if (len % i == 0 && z[i] + i == len)
      res = std::min(res, dfs(l, l + i - 1));
  }
  return dp[l][r] = res;
}
int main() {
  while (cin >> str && strcmp(str, "*") != 0) {
    memset(dp, 0, sizeof(dp));
    cout << dfs(0, strlen(str) - 1) << '\n';
  }
}
