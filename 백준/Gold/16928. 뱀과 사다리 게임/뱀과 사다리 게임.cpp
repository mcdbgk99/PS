#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> v(100 + 1, 0);
  vector<int> visited(100 + 1, 0);
  queue<tuple<int, int>> q;

  for (int i = 0; i < n + m; ++i) {
    int x;
    cin >> x;
    cin >> v[x];
  }

  q.push({1, 0});
  int result = 0;

  while (!q.empty()) {
    auto [now_num, now_step] = q.front();
    q.pop();

    if (now_num == 100) {
      result = now_step;
      break;
    }

    for (int i = 1; i <= 6; ++i) {
      int new_num = now_num + i;
      if (new_num > 100) {
        continue;
      }

      if (v[new_num] != 0) {
        new_num = v[new_num];
      }

      if ((visited[new_num] != 0 && visited[new_num] <= visited[now_num])) {
        continue;
      }

      visited[new_num] = now_step + 1;
      q.push({new_num, visited[new_num]});
    }
  }

  cout << result;

  return 0;
}