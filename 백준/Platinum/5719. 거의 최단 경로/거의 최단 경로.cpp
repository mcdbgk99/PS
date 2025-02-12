#include <bits/stdc++.h>
using namespace std;

constexpr int kInf = 0x60000000;

struct Edge {
  int v, d;
  bool removed;
  Edge(int t, int w) : v(t), d(w), removed(false) {}
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  while (true) {
    int n, m;
    cin >> n >> m;

    if (n == 0 && m == 0) {
      break;
    }

    int s, d;
    cin >> s >> d;

    vector<vector<Edge>> graph(n);

    for (int i = 0; i < m; ++i) {
      int u, v, w;
      cin >> u >> v >> w;
      graph[u].emplace_back(v, w);
    }

    vector<int> dist(n, kInf);
    vector<vector<tuple<int, int>>> parent(n);
    priority_queue<tuple<int, int>, vector<tuple<int, int>>,
                   greater<tuple<int, int>>>
        pq;

    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
      auto [now_dist, u] = pq.top();
      pq.pop();

      if (now_dist != dist[u]) {
        continue;
      }

      for (int i = 0; i < graph[u].size(); ++i) {
        Edge &edge = graph[u][i];
        int v = edge.v;
        int new_dist = now_dist + edge.d;

        if (new_dist < dist[v]) {
          dist[v] = new_dist;
          pq.push({new_dist, v});
          parent[v].clear();
          parent[v].push_back({u, i});
        } else if (new_dist == dist[v]) {
          parent[v].push_back({u, i});
        }
      }
    }

    if (dist[d] == kInf) {
      cout << "-1\n";
      continue;
    }

    vector<char> visited(n, 0);
    function<void(int)> dfs = [&](int v) {
      visited[v] = 1;
      for (auto [u, idx] : parent[v]) {
        if (graph[u][idx].removed) {
          continue;
        }
        graph[u][idx].removed = true;

        if (!visited[u]) {
          dfs(u);
        }
      }
    };

    dfs(d);

    dist.assign(n, kInf);
    dist[s] = 0;
    pq.push({0, s});

    while (!pq.empty()) {
      auto [now_dist, u] = pq.top();
      pq.pop();

      if (now_dist != dist[u]) {
        continue;
      }

      for (auto &edge : graph[u]) {
        if (edge.removed) {
          continue;
        }

        int v = edge.v;
        int new_dist = now_dist + edge.d;

        if (new_dist < dist[v]) {
          dist[v] = new_dist;
          pq.push({new_dist, v});
        }
      }
    }

    cout << (dist[d] == kInf ? -1 : dist[d]) << "\n";
  }

  return 0;
}