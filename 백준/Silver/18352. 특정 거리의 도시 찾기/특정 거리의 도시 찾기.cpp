#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, k, x;
  cin >> n >> m >> k >> x;

  vector<vector<int>> g(n + 1);

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    g[a].push_back(b);
  }

  vector<int> dist(n + 1, -1);
  queue<int> q;

  dist[x] = 0;
  q.push(x);

  while (!q.empty()) {
    int now_node = q.front();
    q.pop();

    for (int new_node : g[now_node]) {
      if (dist[new_node] == -1) {
        dist[new_node] = dist[now_node] + 1;
        q.push(new_node);
      }
    }
  }

  bool result = false;

  for (int i = 1; i <= n; ++i) {
    if (dist[i] == k) {
      cout << i << "\n";
      result = true;
    }
  }

  if (!result) {
    cout << "-1\n";
  }

  return 0;
}