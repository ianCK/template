bool InPolygon(P p, vector<P> &v) {
  bool f = false;
  int n = int(v.size());
  for (int i = 0, j = n - 1; i < n; j = i++)
    if ((dcmp(v[i].y - p.y) > 0 !=
          dcmp(v[j].y - p.y) > 0) &&
      dcmp(p.x -
        (p.y - v[i].y) * (v[i].x - v[j].x) /
          (v[i].y - v[j].y) -
        v[i].x) < 0)
      f = !f;
  return f;
}
