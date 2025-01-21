#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> v(n + 1, vector<int>(n + 1, INT32_MAX));

  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    v[a][b] = min(v[a][b], c);
  }

  for (int i = 1; i <= n; ++i) {
    for (int x = 1; x <= n; ++x) {
      if (i == x) {
        continue;
      }

      if (v[x][i] == INT32_MAX) {
        continue;
      }

      for (int y = 1; y <= n; ++y) {
        if (x == y || i == y) {
          continue;
        }

        if (v[i][y] == INT32_MAX) {
          continue;
        }

        v[x][y] = min(v[x][y], v[x][i] + v[i][y]);
      }
    }
  }

  for (int x = 1; x <= n; ++x) {
    for (int y = 1; y <= n; ++y) {
      cout << (v[x][y] != INT32_MAX ? v[x][y] : 0) << " ";
    }
    cout << "\n";
  }

  return 0;
}