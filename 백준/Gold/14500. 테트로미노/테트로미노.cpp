#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
const vector<vector<tuple<int, int>>> patterns = {
    {{0, 0}, {1, 0}, {2, 0}, {3, 0}},   {{0, 0}, {0, 1}, {0, 2}, {0, 3}},

    {{0, 0}, {1, 0}, {0, 1}, {1, 1}},

    {{0, 0}, {1, 0}, {2, 0}, {2, 1}},   {{0, 0}, {1, 0}, {0, 1}, {0, 2}},
    {{0, 0}, {0, 1}, {1, 1}, {2, 1}},   {{0, 0}, {0, 1}, {0, 2}, {-1, 2}},
    {{0, 0}, {0, 1}, {-1, 1}, {-2, 1}}, {{0, 0}, {1, 0}, {1, 1}, {1, 2}},
    {{0, 0}, {0, 1}, {1, 0}, {2, 0}},   {{0, 0}, {0, 1}, {0, 2}, {1, 2}},

    {{0, 0}, {1, 0}, {1, 1}, {2, 1}},   {{0, 0}, {0, 1}, {-1, 1}, {-1, 2}},
    {{0, 0}, {1, 0}, {0, 1}, {-1, 1}},  {{0, 0}, {0, 1}, {1, 1}, {1, 2}},

    {{0, 0}, {0, 1}, {1, 1}, {0, 2}},   {{0, 0}, {0, 1}, {-1, 1}, {1, 1}},
    {{0, 0}, {0, 1}, {-1, 1}, {0, 2}},  {{0, 0}, {1, 0}, {1, 1}, {2, 0}},
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  v.resize(n, vector<int>(m));

  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < m; ++x) {
      cin >> v[y][x];
    }
  }

  int result = 0;

  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < m; ++x) {
      for (auto& pattern : patterns) {
        int area = 0;

        for (auto& pos : pattern) {
          int new_y = y + get<0>(pos);
          int new_x = x + get<1>(pos);

          if (new_y < 0 || new_y >= n || new_x < 0 || new_x >= m) {
            break;
          }

          area += v[new_y][new_x];
        }

        result = max(result, area);
      }
    }
  }

  cout << result;

  return 0;
}