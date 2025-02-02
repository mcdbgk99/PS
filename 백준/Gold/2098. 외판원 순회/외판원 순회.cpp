#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<int>> v(n, vector<int>(n));

  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      cin >> v[y][x];
    }
  }

  vector<vector<int>> visited(n, vector<int>(1 << n, INT32_MAX));
  priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                 greater<tuple<int, int, int>>>
      pq;
  visited[0][1] = 0;
  pq.push({0, 0, 1});

  while (!pq.empty()) {
    auto [now_cost, now_node, now_visited] = pq.top();
    pq.pop();

    if (now_cost > visited[now_node][now_visited]) {
      continue;
    }

    for (int i = 0; i < n; ++i) {
      if (now_visited & (1 << i)) {
        continue;
      }

      if (v[now_node][i] == 0) {
        continue;
      }

      int new_visited = now_visited | (1 << i);

      if (visited[i][new_visited] <= now_cost + v[now_node][i]) {
        continue;
      }

      visited[i][new_visited] = now_cost + v[now_node][i];
      pq.push({visited[i][new_visited], i, new_visited});
    }
  }

  int result = INT32_MAX;
  for (int i = 0; i < n; ++i) {
    if (v[i][0] != 0 && visited[i][(1 << n) - 1] != INT32_MAX) {
      result = min(result, visited[i][(1 << n) - 1] + v[i][0]);
    }
  }

  cout << result;

  return 0;
}