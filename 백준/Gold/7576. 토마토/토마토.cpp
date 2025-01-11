#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
vector<vector<int>> visited;
deque<tuple<int, int, int>> dq;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int m, n;
  cin >> m >> n;

  v.resize(m, vector<int>(n));
  visited.resize(m, vector<int>(n, 0));

  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < m; ++x) {
      cin >> v[x][y];
    }
  }

  bool empty = false;

  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < m; ++x) {
      if (v[x][y] == 0) {
        empty = true;
        continue;
      }

      if (v[x][y] == -1 || visited[x][y] != 0) {
        continue;
      }

      visited[x][y] = 1;
      dq.push_back({x, y, 1});
    }
  }

  if (!empty) {
    dq.clear();
  }

  vector<vector<int>> patterns = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  int result = 0;

  while (!dq.empty()) {
    int now_x = get<0>(dq.front());
    int now_y = get<1>(dq.front());
    int now_day = get<2>(dq.front());
    dq.pop_front();

    for (auto& pattern : patterns) {
      int new_x = now_x + pattern[0];
      int new_y = now_y + pattern[1];

      if (new_x < 0 || new_x >= m || new_y < 0 || new_y >= n) {
        continue;
      }

      if (v[new_x][new_y] != 0) {
        continue;
      }

      if (visited[new_x][new_y] != 0) {
        continue;
      }

      result = max(result, now_day);

      v[new_x][new_y] = 1;
      visited[new_x][new_y] = 1;
      dq.push_back({new_x, new_y, now_day + 1});
    }
  }

  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < m; ++x) {
      if (v[x][y] == 0) {
        result = -1;
        break;
      }
    }

    if (result == -1) {
      break;
    }
  }

  cout << result;

  return 0;
}