#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
queue<tuple<int, int>> q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int m, n, k;
    cin >> m >> n >> k;

    v.assign(m, vector<int>(n, 0));

    for (int j = 0; j < k; ++j) {
      int x, y;
      cin >> x >> y;
      v[x][y] = 1;
    }

    int result = 0;
    vector<tuple<int, int>> patterns = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int x = 0; x < m; ++x) {
      for (int y = 0; y < n; ++y) {
        if (v[x][y] != 0) {
          ++result;
          v[x][y] = 0;
          q.push({x, y});
        }

        while (!q.empty()) {
          int now_x = get<0>(q.front());
          int now_y = get<1>(q.front());
          q.pop();

          for (auto& pattern : patterns) {
            int new_x = now_x + get<0>(pattern);
            int new_y = now_y + get<1>(pattern);

            if (new_x < 0 || new_x >= m || new_y < 0 || new_y >= n) {
              continue;
            }

            if (v[new_x][new_y] == 0) {
              continue;
            }

            v[new_x][new_y] = 0;
            q.push({new_x, new_y});
          }
        }
      }
    }

    cout << result << "\n";
  }

  return 0;
}