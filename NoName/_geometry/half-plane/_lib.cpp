bool Cmp(Line a, Line b) {
  return same(a.theta, b.theta) ?
    dcmp((b.pb - b.pa) ^ (a.pb - b.pa)) == 1 :
    a.theta < b.theta;
}
bool Check(
  const Line l1, const Line l2, const Line l) {
  if (parallel(l1, l2)) return false;
  P p = line_intersection(l1, l2);
  return dcmp((l.pb - l.pa) ^ (p - l.pa)) != -1;
}
vector<P> Hpi(vector<Line> ls) {
  sort(ls.begin(), ls.end(), Cmp);
  vector<Line> vec;
  for (auto &l : ls) {
    if (!vec.empty() &&
      dcmp(l.theta - vec.back().theta) == 0)
      continue;
    vec.push_back(l);
  }
  deque<Line> dq;
  for (auto &l : vec) {
    while (dq.size() >= 2 &&
      !Check(
        dq[dq.size() - 2], dq[dq.size() - 1], l))
      dq.pop_back();
    while (
      dq.size() >= 2 && !Check(dq[0], dq[1], l))
      dq.pop_front();
    dq.push_back(l);
  }
  while (dq.size() >= 2 &&
    !Check(
      dq[dq.size() - 2], dq[dq.size() - 1], dq[0]))
    dq.pop_back();
  while (dq.size() >= 2 &&
    !Check(dq[0], dq[1], dq[dq.size() - 1]))
    dq.pop_front();
  vector<P> res(dq.size());
  for (int i = 0; i < int(dq.size()); i++)
    res[i] = line_intersection(
      dq[i], dq[(i + 1) % dq.size()]);
  return res;
}
