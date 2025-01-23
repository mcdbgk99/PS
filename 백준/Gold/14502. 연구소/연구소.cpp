#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> v(n, vector<int>(m));
  vector<tuple<int, int>> blank;

  int wall_count = 0;

  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < m; ++x) {
      cin >> v[y][x];
      if (v[y][x] == 0) {
        blank.push_back({y, x});
      }
    }
  }

  vector<int> mask(blank.size(), 0);
  fill(mask.end() - 3, mask.end(), 1);
  int max_safe = 0;

  do {
    vector<int> temp;
    for (int i = 0; i < mask.size(); ++i) {
      if (mask[i] == 1) {
        temp.push_back(i);
      }
    }

    for (int i : temp) {
      v[get<0>(blank[i])][get<1>(blank[i])] = 1;
    }

    vector<vector<int>> visited(n, vector<int>(m, 0));
    deque<tuple<int, int>> dq;
    array<int, 4> pattern_y = {-1, 1, 0, 0};
    array<int, 4> pattern_x = {0, 0, -1, 1};
    int safe_sum = 0;

    for (int y = 0; y < n; ++y) {
      for (int x = 0; x < m; ++x) {
        if (visited[y][x] != 0 || v[y][x] != 0) {
          continue;
        }

        visited[y][x] = 1;
        dq.push_back({y, x});
        int safe = 0;
        bool virus_found = false;

        while (!dq.empty()) {
          auto [now_y, now_x] = dq.front();
          dq.pop_front();

          if (v[now_y][now_x] == 2) {
            virus_found = true;
          }
          ++safe;

          for (int i = 0; i < 4; ++i) {
            int new_y = now_y + pattern_y[i];
            int new_x = now_x + pattern_x[i];

            if (new_y < 0 || new_y >= n || new_x < 0 || new_x >= m) {
              continue;
            }

            if (visited[new_y][new_x] || v[new_y][new_x] == 1) {
              continue;
            }

            visited[new_y][new_x] = 1;
            dq.push_back({new_y, new_x});
          }
        }

        if (!virus_found) {
          safe_sum += safe;
        }
      }
    }

    max_safe = max(max_safe, safe_sum);

    for (int i : temp) {
      v[get<0>(blank[i])][get<1>(blank[i])] = 0;
    }
  } while (next_permutation(mask.begin(), mask.end()));

  cout << max_safe;

  return 0;
}