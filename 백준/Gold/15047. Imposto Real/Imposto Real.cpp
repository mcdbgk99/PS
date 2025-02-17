#include <bits/stdc++.h>
using namespace std;

vector<int> tax;
vector<vector<tuple<int, int>>> adj;
int n, c;
int64_t result = 0;

int64_t Dfs(int u, int parent) {
  int64_t sum = tax[u];

  for (auto [v, w] : adj[u]) {
    if (v == parent) {
      continue;
    }

    int64_t t = Dfs(v, u);
    if (t > 0) {
      result += (t + c - 1) / c * w * 2;
    }

    sum += t;
  }

  return sum;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n >> c;

  tax.resize(n + 1);
  adj.resize(n + 1, vector<tuple<int, int>>());

  for (int i = 1; i <= n; ++i) {
    cin >> tax[i];
  }

  for (int i = 1; i < n; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

  Dfs(1, -1);

  cout << result << "\n";

  return 0;
}