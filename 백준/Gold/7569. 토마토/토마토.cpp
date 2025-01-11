#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
vector<vector<int>> visited;
deque<tuple<int, int, int, int>> dq;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int m, n, h;
  cin >> m >> n >> h;

  v.resize(m, vector<int>(n * h));
  visited.resize(m, vector<int>(n * h, 0));

  for (int z = 0; z < h; ++z) {
    for (int y = 0; y < n; ++y) {
      for (int x = 0; x < m; ++x) {
        cin >> v[x][y + z * n];
      }
    }
  }

  bool empty = false;

  for (int z = 0; z < h; ++z) {
    for (int y = 0; y < n; ++y) {
      for (int x = 0; x < m; ++x) {
        if (v[x][y + z * n] == 0) {
          empty = true;
          continue;
        }

        if (v[x][y + z * n] == -1 || visited[x][y + z * n] != 0) {
          continue;
        }

        visited[x][y + z * n] = 1;
        dq.push_back({x, y, z, 1});
      }
    }
  }

  if (!empty) {
    dq.clear();
  }

  vector<vector<int>> patterns = {{-1, 0, 0}, {1, 0, 0},  {0, -1, 0},
                                  {0, 1, 0},  {0, 0, -1}, {0, 0, 1}};
  int result = 0;

  while (!dq.empty()) {
    int now_x = get<0>(dq.front());
    int now_y = get<1>(dq.front());
    int now_z = get<2>(dq.front());
    int now_day = get<3>(dq.front());
    dq.pop_front();

    for (auto& pattern : patterns) {
      int new_x = now_x + pattern[0];
      int new_y = now_y + pattern[1];
      int new_z = now_z + pattern[2];

      if (new_x < 0 || new_x >= m || new_y < 0 || new_y >= n || new_z < 0 ||
          new_z >= h) {
        continue;
      }

      if (v[new_x][new_y + new_z * n] != 0) {
        continue;
      }

      if (visited[new_x][new_y + new_z * n] != 0) {
        continue;
      }

      result = max(result, now_day);

      v[new_x][new_y + new_z * n] = 1;
      visited[new_x][new_y + new_z * n] = 1;
      dq.push_back({new_x, new_y, new_z, now_day + 1});
    }
  }

  for (int z = 0; z < h; ++z) {
    for (int y = 0; y < n; ++y) {
      for (int x = 0; x < m; ++x) {
        if (v[x][y + z * n] == 0) {
          result = -1;
          break;
        }
      }

      if (result == -1) {
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