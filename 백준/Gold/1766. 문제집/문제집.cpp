#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> v(n + 1);
  vector<int> in_degree(n + 1, 0);

  while (m--) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    ++in_degree[b];
  }

  priority_queue<int, vector<int>, greater<int>> pq;
  for (int i = 1; i <= n; ++i) {
    if (in_degree[i] == 0) {
      pq.push(i);
    }
  }

  vector<int> result;
  result.reserve(n);

  while (!pq.empty()) {
    int now_node = pq.top();
    pq.pop();

    result.push_back(now_node);

    for (int next_node : v[now_node]) {
      if (--in_degree[next_node] == 0) {
        pq.push(next_node);
      }
    }
  }

  for (int i : result) {
    cout << i << " ";
  }

  return 0;
}