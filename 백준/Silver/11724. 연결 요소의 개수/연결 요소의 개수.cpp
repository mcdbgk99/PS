#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
vector<int> visited;
queue<int> q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  v.resize(n + 1);
  visited.resize(n + 1, 0);

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  int result = 0;

  for (int i = 1; i <= n; ++i) {
    if (visited[i] != 0) {
      continue;
    }

    ++result;
    visited[i] = 1;
    q.push(i);

    while (!q.empty()) {
      int now = q.front();
      q.pop();

      for (int j : v[now]) {
        if (visited[j] != 0) {
          continue;
        }

        visited[j] = 1;
        q.push(j);
      }
    }
  }

  cout << result;

  return 0;
}