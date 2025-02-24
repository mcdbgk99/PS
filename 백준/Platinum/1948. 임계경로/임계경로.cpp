#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<pair<int, int>>> graph(n + 1), graph_rev(n + 1);
  vector<int> in_degree(n + 1, 0);

  for (int i = 0; i < m; ++i) {
    int u, v, cost;
    cin >> u >> v >> cost;
    graph[u].push_back({v, cost});
    graph_rev[v].push_back({u, cost});
    ++in_degree[v];
  }

  int s, e;
  cin >> s >> e;

  vector<int> dist(n + 1, 0);
  queue<int> q;

  q.push(s);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    for (auto &edge : graph[u]) {
      int v = edge.first;

      if (dist[v] < dist[u] + edge.second) {
        dist[v] = dist[u] + edge.second;
      }

      if (--in_degree[v] == 0) {
        q.push(v);
      }
    }
  }

  cout << dist[e] << "\n";

  vector<char> visited(n + 1, 0);
  int edges = 0;

  visited[e] = 1;
  q.push(e);

  while (!q.empty()) {
    int v = q.front();
    q.pop();

    for (auto &edge : graph_rev[v]) {
      int u = edge.first;

      if (dist[u] + edge.second == dist[v]) {
        ++edges;

        if (visited[u]) {
          continue;
        }

        visited[u] = 1;
        q.push(u);
      }
    }
  }

  cout << edges << "\n";

  return 0;
}