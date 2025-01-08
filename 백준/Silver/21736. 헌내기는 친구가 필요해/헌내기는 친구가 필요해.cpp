#include <bits/stdc++.h>
using namespace std;

vector<vector<char>> v;
queue<tuple<int, int>> q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  v.resize(n + 1, vector<char>(m + 1));
  int start_y, start_x;

  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < m; ++x) {
      cin >> v[y][x];

      if (v[y][x] == 'I') {
        start_y = y;
        start_x = x;
      }
    }
  }

  vector<vector<int>> patterns = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  int result = 0;

  q.push({start_y, start_x});
  while (!q.empty()) {
    int now_y = get<0>(q.front());
    int now_x = get<1>(q.front());
    q.pop();

    for (auto& pattern : patterns) {
      int new_y = now_y + pattern[0];
      int new_x = now_x + pattern[1];

      if (new_y < 0 || new_y >= n || new_x < 0 || new_x >= m) {
        continue;
      }

      if (v[new_y][new_x] == 'X') {
        continue;
      }

      if (v[new_y][new_x] == 'P') {
        ++result;
      }

      v[new_y][new_x] = 'X';
      q.push({new_y, new_x});
    }
  }

  if (result != 0) {
    cout << result;
  } else {
    cout << "TT";
  }

  return 0;
}