#include <bits/stdc++.h>
using namespace std;

const int kMaxN = 100000 + 1;
vector<vector<int>> graph(kMaxN);
vector<vector<pair<int, int>>> queries(kMaxN);
vector<char> visited(kMaxN);
vector<int> parent(kMaxN), ances(kMaxN), result(kMaxN);

int Find(int x) {
  if (parent[x] == x) {
    return x;
  }

  return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
  x = Find(x);
  y = Find(y);

  if (x != y) {
    parent[y] = x;
  }
}

void Dfs(int u) {
  parent[u] = u;
  ances[u] = u;
  visited[u] = 1;

  for (auto v : graph[u]) {
    if (!visited[v]) {
      Dfs(v);
      Union(u, v);
      ances[Find(u)] = u;
    }
  }

  for (auto [v, index] : queries[u]) {
    if (visited[v]) {
      result[index] = ances[Find(v)];
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 1; i <= n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    graph[u].push_back(v);
    graph[v].push_back(u);
  }

  int m;
  cin >> m;

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    queries[u].push_back({v, i});
    queries[v].push_back({u, i});
  }

  for (int i = 1; i <= n; ++i) {
    visited[i] = 0;
  }

  Dfs(1);

  for (int i = 0; i < m; ++i) {
    cout << result[i] << "\n";
  }

  return 0;
}