#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> temp;
vector<int> result;
vector<int> visited;

void Dfs(int node) {
  int count = 0;
  visited[node] = 1;

  for (int i : temp[node]) {
    if (visited[i]) {
      continue;
    }

    Dfs(i);

    result[node] += result[i];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, r, q;
  cin >> n >> r >> q;

  temp.resize(n + 1, vector<int>());
  result.resize(n + 1, 1);
  visited.resize(n + 1, 0);

  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    temp[u].push_back(v);
    temp[v].push_back(u);
  }

  Dfs(r);

  for (int i = 0; i < q; ++i) {
    int u;
    cin >> u;
    cout << result[u] << "\n";
  }

  return 0;
}