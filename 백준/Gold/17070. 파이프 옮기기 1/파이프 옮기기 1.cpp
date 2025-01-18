#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
queue<tuple<int, int, int>> q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  v.resize(n, vector<int>(n));

  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      cin >> v[x][y];
    }
  }

  int result = 0;

  vector<vector<vector<tuple<int, int>>>> all_patterns = {
      {{{0, 0}, {1, 0}, {2, 0}}, {}, {{0, 0}, {1, 0}, {2, 1}, {1, 1}, {2, 0}}},
      {{}, {{0, 0}, {0, 1}, {0, 2}}, {{0, 0}, {0, 1}, {1, 2}, {0, 2}, {1, 1}}},
      {{{0, 0}, {1, 1}, {2, 1}},
       {{0, 0}, {1, 1}, {1, 2}},
       {{0, 0}, {1, 1}, {2, 2}, {1, 2}, {2, 1}}},
  };

  q.push({0, 0, 0});

  while (!q.empty()) {
    auto [now_x, now_y, type] = q.front();
    q.pop();

    for (int i = 0; i < 3; ++i) {
      auto& patterns = all_patterns[type][i];

      if (patterns.empty()) {
        continue;
      }

      bool can_move = true;
      bool finish = false;
      for (int j = 0; j < patterns.size(); ++j) {
        int new_x = now_x + get<0>(patterns[j]);
        int new_y = now_y + get<1>(patterns[j]);

        if (new_x >= n || new_y >= n || v[new_x][new_y] == 1) {
          can_move = false;
          break;
        }

        if (j == 2 && new_x == n - 1 && new_y == n - 1) {
          finish = true;
        }
      }

      if (!can_move) {
        continue;
      }

      if (finish) {
        ++result;
        continue;
      }

      q.push({now_x + get<0>(patterns[1]), now_y + get<1>(patterns[1]), i});
    }
  }

  cout << result;

  return 0;
}