#include <bits/stdc++.h>
using namespace std;
const int kN = 105;
const double kEps = 1e-9;

int n, m, d;
double A[kN][kN];
int GetID(int i, int j) {
    return m * i + j;
}
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

    for(int i = 0; i < n; i++) {
        assert(fabs(v[i][i]) > kEps);
        v[i][m - 1] /= v[i][i];
        v[i][i] = 1.0;
    }
}

int main() {
    bool flag = 0;
    while(true) {
				scanf("%d%d%d", &m, &n, &d);
				if (n == 0 && m == 0 && d == 0) break;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++) scanf("%lf", &A[i][j]);

        if(flag) printf("\n\n");
        flag = 1;

        vector<vector<double>> v(n * m, vector<double>(n * m + 1, 0));

        auto Ok = [&](int i, int j) {
            if(i >= 0 && i < n && j >= 0 && j < m) return 1;
            return 0;
        };
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int cnt = 0, row = GetID(i, j);
                for(int a = -d; a <= d; a++) {
                    for(int b = -(d - abs(a)); b <= d - abs(a); b++) {
                        int x = i + a, y = j + b;
                        if(!Ok(x, y)) continue;
                        cnt++;
                        v[row][GetID(x, y)] = 1;
                    }
                }
                v[row][n * m] = cnt * A[i][j];
            }
        }

        Gauss(v);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                printf("%8.2lf", v[GetID(i, j)][n * m]);
            }
            if(i != n - 1) puts("");
        }
    } 
    return 0;
}
