#include <bits/stdc++.h>
using namespace std;

vector<string> v;
queue<tuple<int, int>> q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  v.resize(n);

  for (int y = 0; y < n; ++y) {
    cin >> v[y];
  }

  vector<vector<int>> patterns = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  vector<int> result;

  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      if (v[y][x] == '1') {
        v[y][x] = '0';
        q.push({y, x});
      }

      int count = 0;

      while (!q.empty()) {
        int now_y = get<0>(q.front());
        int now_x = get<1>(q.front());
        q.pop();

        ++count;

        for (auto& pattern : patterns) {
          int new_y = now_y + pattern[0];
          int new_x = now_x + pattern[1];

          if (new_y < 0 || new_y >= n || new_x < 0 || new_x >= n) {
            continue;
          }

          if (v[new_y][new_x] != '1') {
            continue;
          }

          v[new_y][new_x] = '0';
          q.push({new_y, new_x});
        }
      }

      if (count) {
        result.push_back(count);
      }
    }
  }

  sort(result.begin(), result.end());

  cout << result.size() << "\n";
  for (int i : result) {
    cout << i << "\n";
  }

  return 0;
}