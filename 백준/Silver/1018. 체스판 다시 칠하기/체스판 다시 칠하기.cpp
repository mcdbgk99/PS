#include <bits/stdc++.h>
using namespace std;

vector<string> v;
vector<vector<int>> pre;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  v.resize(n);
  pre.resize(n + 1, vector<int>(m + 1, 0));

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < m; ++x) {
      pre[y + 1][x + 1] = (v[y][x] == ((x + y) % 2 != 0 ? 'W' : 'B')) +
                          pre[y][x + 1] + pre[y + 1][x] - pre[y][x];
    }
  }

  int best = INT32_MAX;
  for (int y = 1; y <= n - 7; ++y) {
    for (int x = 1; x <= m - 7; ++x) {
      int changes = pre[y + 7][x + 7] - pre[y - 1][x + 7] - pre[y + 7][x - 1] +
                    pre[y - 1][x - 1];
      best = min({best, changes, 64 - changes});
    }
  }

  cout << best;

  return 0;
}