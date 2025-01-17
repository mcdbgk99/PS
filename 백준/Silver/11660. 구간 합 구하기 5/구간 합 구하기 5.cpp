#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  v.resize(n + 1, vector<int>(n + 1, 0));

  for (int x = 1; x <= n; ++x) {
    for (int y = 1; y <= n; ++y) {
      int i;
      cin >> i;
      v[x][y] = i + v[x - 1][y] + v[x][y - 1] - v[x - 1][y - 1];
    }
  }

  for (int i = 0; i < m; ++i) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    cout << v[x2][y2] - v[x1 - 1][y2] - v[x2][y1 - 1] + v[x1 - 1][y1 - 1]
         << "\n";
  }

  return 0;
}