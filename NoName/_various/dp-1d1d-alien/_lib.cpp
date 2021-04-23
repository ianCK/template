bool debug = false;
constexpr long long int kInf = 1e16;
constexpr int N = 3e5;
int n, k;
long long int a[N], s[N], dp[N], val[N];
void pre() {
  scanf("%d%d", &n, &k);
  s[0] = a[0] = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    s[i] = s[i - 1] + a[i];
  }
}
long long int value(int l, int r) {
  int mid = (l + r + 1) >> 1;
  long long int ans =
    ((mid << 1) - r - l) * a[mid] + s[r] + s[l] -
    (s[mid] << 1);
  if (debug) {
    printf("value(%d,%d)=%lld\n", l, r, ans);
    return ans;
  }
  return ((mid << 1) - r - l) * a[mid] + s[r] +
    s[l] - (s[mid] << 1);
}
pair<long long, int> f(int l, int r) {
  return make_pair(dp[l] + value(l, r), val[l]);
}
struct P {
  int i, l, r;
};
pair<long long, int> aliens(long long int cost) {
  if (debug) printf("\naliens(%lld)\n", cost);
  dp[0] = val[0] = 0;
  deque<P> dq;
  dq.push_back({0, 1, n});
  for (int i = 1; i <= n; i++) {
    P ii = dq.front();
    dp[i] = dp[ii.i] + value(ii.i, i) + cost;
    val[i] = val[ii.i] + 1;
    while (!dq.empty() && dq.front().r < i + 1)
      dq.pop_front();
    dq.front().l = i + 1;
    while (!dq.empty() &&
      f(dq.back().i, dq.back().l) >
        f(i, dq.back().l))
      dq.pop_back();
    P tmp = {i, i + 1, n};
    if (!dq.empty()) {
      int now = dq.back().l;
      for (int j = 20; j >= 0; j--)
        if (now + (1 << j) <= dq.back().r) {
          if (f(i, now + (1 << j)) >
            f(dq.back().i, now + (1 << j)))
            now += (1 << j);
        }
      dq.back().r = now, tmp.l = now + 1;
    }
    if (tmp.l <= n) dq.push_back(tmp);
    if (debug)
      printf(
        "dp = %lld val = %lld\n", dp[i], val[i]);
  }
  return make_pair(dp[n], val[n]);
}
int main() {
  pre();
  if (n == k) {
    printf("0\n");
    return 0;
  }
  long long now = 0, tot = kInf;
  for (int i = 60; i >= 0; i--)
    if (now + (1LL << i) <= tot) {
      pair<long long, int> tmp =
        aliens(now + (1LL << i));
      if (tmp.second == k)
        return 0 *
          printf("%lld\n",
            tmp.first - (now + (1LL << i)) * k);
      if (tmp.second > k) now += (1LL << i);
    }
  now++;
  pair<long long, int> ans = aliens(now);
  printf("%lld\n", ans.first - now * k);
}
