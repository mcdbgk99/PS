#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> v(n + 1, vector<int>());
  vector<int> in_degree(n + 1, 0);

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    ++in_degree[b];
  }

  vector<int> result;
  deque<int> dq;

  for (int i = 1; i <= n; ++i) {
    if (in_degree[i] != 0) {
      continue;
    }

    dq.push_back(i);
  }

  while (!dq.empty()) {
    int now_node = dq.front();
    dq.pop_front();

    result.push_back(now_node);

    for (int new_node : v[now_node]) {
      if (--in_degree[new_node] != 0) {
        continue;
      }

      dq.push_back(new_node);
    }
  }

  for (int i : result) {
    cout << i << " ";
  }

  return 0;
}