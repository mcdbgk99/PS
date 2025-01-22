#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int tc;
  cin >> tc;

  for (int i = 0; i < tc; ++i) {
    int n, m, w;
    cin >> n >> m >> w;

    vector<tuple<int, int, int>> edges;

    for (int j = 0; j < m; ++j) {
      int s, e, t;
      cin >> s >> e >> t;
      edges.push_back({s, e, t});
      edges.push_back({e, s, t});
    }

    for (int j = 0; j < w; ++j) {
      int s, e, t;
      cin >> s >> e >> t;
      edges.push_back({s, e, -t});
    }

    bool result = false;
    vector<int> dist(n + 1, 0);

    for (int j = 0; j < n; ++j) {
      bool updated = false;

      for (auto [src, dst, cost] : edges) {
        if (dist[dst] <= dist[src] + cost) {
          continue;
        }

        if (j == n - 1) {
          result = true;
          break;
        }

        updated = true;
        dist[dst] = dist[src] + cost;
      }

      if (result || !updated) {
        break;
      }
    }

    cout << (result ? "YES\n" : "NO\n");
  }

  return 0;
}