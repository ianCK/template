void ZAlg(char *str, int len, int *z) {
  int l = 0, r = 0;
  for (int i = 0; i < len; i++) {
    if (i > r) {
      l = r = i;
      while (r < len && str[r] == str[r - l]) r++;
      z[i] = r - l;
      r--;
    } else {
      if (z[i - l] < r - i + 1) {
        z[i] = z[i - l];
      } else {
        l = i;
        while (r < len && str[r] == str[r - l])
          r++;
        z[i] = r - l;
        r--;
      }
    }
  }
}
