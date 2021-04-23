// p should be sorted increasingly according
// to the x-coordinates.
double Dis(P a, P b) { return (a - b).abs(); }
double ClosestPair(P *p, int l, int r) {
  if (l == r) return 1E9;
  if (r - l == 1) return Dis(p[l], p[r]);
  int m = (l + r) >> 1;
  double d = min(ClosestPair(p, l, m),
    ClosestPair(p, m + 1, r));
  vector<int> vec;
  for (int i = m;
       i >= l && abs(p[m].x - p[i].x) < d; i--)
    vec.push_back(i);
  for (int i = m + 1;
       i <= r && abs(p[m].x - p[i].x) < d; i++)
    vec.push_back(i);
  sort(vec.begin(), vec.end(),
    [&](int a, int b) { return p[a].y < p[b].y; });
  for (int i = 0; i < int(vec.size()); ++i) {
    for (int j = i + 1; j < int(vec.size()) &&
         abs(p[vec[j]].y - p[vec[i]].y) < d;
         ++j) {
      d = min(d, Dis(p[vec[i]], p[vec[j]]));
    }
  }
  return d;
}
