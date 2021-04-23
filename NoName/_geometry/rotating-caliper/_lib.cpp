// To be implemented:
double Angle(Vector a, Vector b) {
  return atan2(a ^ b, a * b);
}
double TurnAngle(Vector a, Vector b) {
  return (dcmp(a * b) > 0) ? Angle(a, b) :
                             (kPi + Angle(a, b));
}
double DistToLine(P o, P a, P b) {
  return abs(((a - o) ^ (b - o)) / (a - b).abs());
}
pair<double, double> Caliper(
  const vector<P> &hull) {
  auto kZero = P(0, 0);
  int p1 = 0, p2 = 0, p3 = 0, p4 = 0,
      n = int(hull.size());
  for (int i = 1; i < n; i++) {
    if (dcmp(hull[i].y - hull[p1].y) < 0) p1 = i;
    if (dcmp(hull[i].y - hull[p2].y) > 0) p2 = i;
    if (dcmp(hull[i].x - hull[p3].x) < 0) p3 = i;
    if (dcmp(hull[i].x - hull[p4].x) > 0) p4 = i;
  }
  Vector orig = {1, 0}, v1 = {1, 0}, v2 = {0, 1};
  double ans_area = 1E30, ans_len = 1E30;
  while (dcmp(orig ^ v1) >= 0) {
    double d1 = DistToLine(
             hull[p1], hull[p2], hull[p2] + v1),
           d2 = DistToLine(
             hull[p3], hull[p4], hull[p4] + v2);
    ans_area = min(ans_area, d1 * d2);
    ans_len = min(ans_len, 2 * (d1 + d2));
    double min_ang =
      TurnAngle(v1, hull[p1 + 1] - hull[p1]);
    min_ang = min(min_ang,
      TurnAngle(
        kZero - v1, hull[p2 + 1] - hull[p2]));
    min_ang = min(min_ang,
      TurnAngle(
        kZero - v2, hull[p3 + 1] - hull[p3]));
    min_ang = min(min_ang,
      TurnAngle(v2, hull[p4 + 1] - hull[p4]));
    v1 = v1.spin(min_ang), v2 = v2.spin(min_ang);
    if (dcmp(Angle(v1, hull[p1 + 1] - hull[p1])) ==
      0)
      p1 = (p1 + 1) % n;
    if (dcmp(Angle(kZero - v1,
          hull[p2 + 1] - hull[p2])) == 0)
      p2 = (p2 + 1) % n;
    if (dcmp(Angle(kZero - v2,
          hull[p3 + 1] - hull[p3])) == 0)
      p3 = (p3 + 1) % n;
    if (dcmp(Angle(v2, hull[p4 + 1] - hull[p4])) ==
      0)
      p4 = (p4 + 1) % n;
  }
  return {ans_area, ans_len};
}
