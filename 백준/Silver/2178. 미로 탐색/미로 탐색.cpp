#include <bits/stdc++.h>
using namespace std;

vector<string> v;
queue<tuple<int, int, int>> q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  v.resize(n);

  for (int y = 0; y < n; ++y) {
    cin >> v[y];
  }

  vector<vector<int>> patterns = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  v[0][0] = '0';
  q.push({0, 0, 1});

  while (!q.empty()) {
    int now_y = get<0>(q.front());
    int now_x = get<1>(q.front());
    int now_step = get<2>(q.front());
    q.pop();

    if (now_y == n - 1 && now_x == m - 1) {
      cout << now_step;
      return 0;
    }

    for (auto& pattern : patterns) {
      int new_y = now_y + pattern[0];
      int new_x = now_x + pattern[1];

      if (new_y < 0 || new_y >= n || new_x < 0 || new_x >= m) {
        continue;
      }

      if (v[new_y][new_x] != '1') {
        continue;
      }

      v[new_y][new_x] = '0';
      q.push({new_y, new_x, now_step + 1});
    }
  }

  return 0;
}