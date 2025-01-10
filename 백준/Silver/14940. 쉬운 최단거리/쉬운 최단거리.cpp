#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
queue<tuple<int, int>> q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  v.resize(m, vector<int>(n));
  tuple<int, int> start;

  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < m; ++x) {
      cin >> v[x][y];
      if (v[x][y] == 2) {
        v[x][y] = 0;
        start = {x, y};
      } else if (v[x][y] != 0) {
        v[x][y] = -1;
      }
    }
  }

  vector<vector<int>> patterns = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  q.push(start);

  while (!q.empty()) {
    int now_x = get<0>(q.front());
    int now_y = get<1>(q.front());
    q.pop();

    for (auto& pattern : patterns) {
      int new_x = now_x + pattern[0];
      int new_y = now_y + pattern[1];

      if (new_x < 0 || new_x >= m || new_y < 0 || new_y >= n) {
        continue;
      }

      if (v[new_x][new_y] != -1 && v[new_x][new_y] <= v[now_x][now_y] + 1) {
        continue;
      }

      v[new_x][new_y] = v[now_x][now_y] + 1;
      q.push({new_x, new_y});
    }
  }

  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < m; ++x) {
      cout << v[x][y] << " ";
    }
    cout << "\n";
  }

  return 0;
}