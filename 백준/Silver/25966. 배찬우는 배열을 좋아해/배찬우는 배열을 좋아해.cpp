#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, q;
  cin >> n >> m >> q;

  vector<vector<int>> v(n, vector<int>(m));

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> v[i][j];
    }
  }

  vector<int> pos(n);
  iota(pos.begin(), pos.end(), 0);

  while (q--) {
    int op;
    cin >> op;

    if (op & 1) {
      int i, j;
      cin >> i >> j;
      swap(pos[i], pos[j]);
    } else {
      int i, j, k;
      cin >> i >> j >> k;
      v[pos[i]][j] = k;
    }
  }

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << v[pos[i]][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}