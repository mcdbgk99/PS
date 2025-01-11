#include <bits/stdc++.h>
using namespace std;

vector<string> v;
vector<vector<int>> visited;
queue<tuple<int, int>> q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  v.resize(n);

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  vector<vector<int>> patterns = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  array<int, 2> result = {0, 0};

  visited.assign(n, vector<int>(n, 0));

  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      if (visited[x][y] != 1) {
        ++result[0];
        visited[x][y] = 1;
        q.push({x, y});
      }

      while (!q.empty()) {
        int now_x = get<0>(q.front());
        int now_y = get<1>(q.front());
        q.pop();

        for (auto& pattern : patterns) {
          int new_x = now_x + pattern[0];
          int new_y = now_y + pattern[1];

          if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= n) {
            continue;
          }

          if (visited[new_x][new_y] != 0) {
            continue;
          }

          if (v[new_x][new_y] != v[now_x][now_y]) {
            continue;
          }

          visited[new_x][new_y] = 1;
          q.push({new_x, new_y});
        }
      }
    }
  }

  visited.assign(n, vector<int>(n, 0));

  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      if (visited[x][y] != 1) {
        ++result[1];
        visited[x][y] = 1;
        q.push({x, y});
      }

      while (!q.empty()) {
        int now_x = get<0>(q.front());
        int now_y = get<1>(q.front());
        q.pop();

        for (auto& pattern : patterns) {
          int new_x = now_x + pattern[0];
          int new_y = now_y + pattern[1];

          if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= n) {
            continue;
          }

          if (visited[new_x][new_y] != 0) {
            continue;
          }

          if ((v[new_x][new_y] != 'B') != (v[now_x][now_y] != 'B')) {
            continue;
          }

          visited[new_x][new_y] = 1;
          q.push({new_x, new_y});
        }
      }
    }
  }

  cout << result[0] << " " << result[1];

  return 0;
}