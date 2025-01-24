#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int16_t n, m;
  cin >> n >> m;

  vector<string> v(n);

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  constexpr array<int8_t, 4> pattern_y = {-1, 1, 0, 0};
  constexpr array<int8_t, 4> pattern_x = {0, 0, -1, 1};

  auto bfs = [n, m, &v, &pattern_y, &pattern_x](int16_t y, int16_t x) {
    deque<tuple<int16_t, int16_t>> dq;
    vector<vector<int>> visited(n, vector<int>(m, -1));

    visited[y][x] = 1;
    dq.emplace_back(y, x);

    while (!dq.empty()) {
      auto [now_y, now_x] = dq.front();
      dq.pop_front();

      for (int i = 0; i < 4; ++i) {
        int16_t new_y = now_y + pattern_y[i];
        int16_t new_x = now_x + pattern_x[i];

        if (new_y < 0 || new_y >= n || new_x < 0 || new_x >= m) {
          continue;
        }

        if (v[new_y][new_x] != '0' || visited[new_y][new_x] != -1) {
          continue;
        }

        visited[new_y][new_x] = visited[now_y][now_x] + 1;
        dq.emplace_back(new_y, new_x);
      }
    }

    return visited;
  };

  auto&& start = bfs(0, 0);
  auto&& end = bfs(n - 1, m - 1);
  int result = (start[n - 1][m - 1] != -1 ? start[n - 1][m - 1] : INT32_MAX);

  for (int16_t now_y = 0; now_y < n; ++now_y) {
    for (int16_t now_x = 0; now_x < m; ++now_x) {
      if (v[now_y][now_x] != '1') {
        continue;
      }

      if (result < n + m) {
        cout << result;
        return 0;
      }

      vector<tuple<int16_t, int16_t, int>> first;
      vector<tuple<int16_t, int16_t, int>> second;
      first.reserve(4);
      second.reserve(4);

      for (int i = 0; i < 4; ++i) {
        int16_t new_y = now_y + pattern_y[i];
        int16_t new_x = now_x + pattern_x[i];

        if (new_y < 0 || new_y >= n || new_x < 0 || new_x >= m) {
          continue;
        }

        if (start[new_y][new_x] != -1) {
          first.emplace_back(new_y, new_x, start[new_y][new_x]);
        }

        if (end[new_y][new_x] != -1) {
          second.emplace_back(new_y, new_x, end[new_y][new_x]);
        }
      }

      if (first.empty() || second.empty()) {
        continue;
      }

      for (auto [first_y, first_x, first_cost] : first) {
        for (auto [second_y, second_x, second_cost] : second) {
          if (first_y == second_y && first_x == second_x) {
            continue;
          }

          int dist = first_cost + second_cost + 1;
          if (dist < result) {
            result = dist;
          }
        }
      }
    }
  }

  cout << (result != INT32_MAX ? result : -1);

  return 0;
}