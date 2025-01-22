#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<string> v(n);

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  queue<tuple<int, int, int>> q;
  vector<vector<int>> patterns = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  vector<vector<vector<int>>> visited(
      2, vector<vector<int>>(n, vector<int>(m, -1)));

  visited[0][0][0] = 1;
  q.push({0, 0, 0});

  while (!q.empty()) {
    auto [now_y, now_x, now_breached] = q.front();
    q.pop();

    for (auto& pattern : patterns) {
      int new_y = now_y + pattern[0];
      int new_x = now_x + pattern[1];

      if (new_y < 0 || new_y >= n || new_x < 0 || new_x >= m) {
        continue;
      }

      int need_breach = v[new_y][new_x] == '1';
      int new_breached = now_breached;

      if (need_breach) {
        if (now_breached) {
          continue;
        }
        new_breached = 1;
      }

      if (visited[new_breached][new_y][new_x] != -1) {
        continue;
      }

      visited[new_breached][new_y][new_x] =
          visited[now_breached][now_y][now_x] + 1;
      q.push({new_y, new_x, new_breached});
    }
  }

  cout << static_cast<int>(
      min<uint32_t>(visited[0][n - 1][m - 1], visited[1][n - 1][m - 1]));

  return 0;
}