#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<array<int, 2>> queries;
  queries.reserve(m);

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    queries.push_back({u, v});
  }

  vector<int> result(n + 1);
  iota(result.begin(), result.end(), 0);

  for (int i = m - 1; i >= 0; --i) {
    result[queries[i][0]] = result[queries[i][1]];
  }

  for (int i = 1; i <= n; ++i) {
    cout << result[i] << " ";
  }

  return 0;
}