#include <bits/stdc++.h>
using namespace std;

constexpr int kMaxNode = 40000;
constexpr int kMaxQuery = 10000;

array<int, kMaxQuery + 1> result;
array<vector<tuple<int, int>>, kMaxNode + 1> tree;
array<vector<tuple<int, int>>, kMaxNode + 1> query;

array<bool, kMaxNode + 1> visited;
array<int, kMaxNode + 1> ancestor;
array<int, kMaxNode + 1> parent;
array<int, kMaxNode + 1> costs;

int Find(int x) {
  if (parent[x] == x) {
    return x;
  }

  return parent[x] = Find(parent[x]);
}

void Union(int a, int b) {
  a = Find(a);
  b = Find(b);

  parent[b] = a;
}

void Dfs(int u) {
  visited[u] = true;
  ancestor[u] = u;

  for (auto [v, cost] : tree[u]) {
    if (visited[v]) {
      continue;
    }

    costs[v] = costs[u] + cost;
    Dfs(v);
    Union(u, v);
    ancestor[Find(u)] = u;
  }

  for (auto [v, i] : query[u]) {
    if (!visited[v]) {
      continue;
    }

    result[i] = costs[u] + costs[v] - costs[ancestor[Find(v)]] * 2;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    parent[i] = i;
  }

  for (int i = 1; i <= n - 1; ++i) {
    int u, v, c;
    cin >> u >> v >> c;
    tree[u].push_back({v, c});
    tree[v].push_back({u, c});
  }

  int m;
  cin >> m;

  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    query[u].push_back({v, i});
    query[v].push_back({u, i});
  }

  Dfs(1);

  for (int i = 0; i < m; ++i) {
    cout << result[i] << "\n";
  }

  return 0;
}