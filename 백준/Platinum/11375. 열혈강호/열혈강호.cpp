#include <bits/stdc++.h>
using namespace std;

constexpr int kInf = numeric_limits<int>::max();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<vector<int>> adj(n + 1);

  for (int i = 1; i <= n; ++i) {
    int j;
    cin >> j;

    while (j--) {
      int k;
      cin >> k;
      adj[i].push_back(k);
    }
  }

  vector<int> match_u(n + 1, 0), match_v(m + 1, 0);
  vector<int> cost(n + 1, kInf);

  int result = 0;

  while (true) {
    deque<int> dq;

    for (int u = 1; u <= n; ++u) {
      if (match_u[u] == 0) {
        cost[u] = 0;
        dq.push_back(u);
      } else {
        cost[u] = kInf;
      }
    }

    int min_cost = kInf;

    while (!dq.empty()) {
      int now_node = dq.front();
      dq.pop_front();

      if (cost[now_node] < min_cost) {
        for (int i : adj[now_node]) {
          int new_node = match_v[i];
          if (new_node == 0) {
            min_cost = cost[now_node] + 1;
          } else if (cost[new_node] == kInf) {
            cost[new_node] = cost[now_node] + 1;
            dq.push_back(new_node);
          }
        }
      }
    }

    if (min_cost == kInf) {
      break;
    }

    for (int u = 1; u <= n; ++u) {
      if (match_u[u] != 0) {
        continue;
      }

      vector<int> index(n + 1, 0), parent(n + 1, -1), child(n + 1, -1);

      dq.push_back(u);
      bool found = false;

      while (!dq.empty()) {
        int now_node = dq.back();

        if (now_node == 0) {
          found = true;
          break;
        }

        if (index[now_node] < adj[now_node].size()) {
          int v = adj[now_node][index[now_node]++];
          int new_node = match_v[v];
          if (new_node == 0 || (cost[new_node] == cost[now_node] + 1)) {
            parent[new_node] = now_node;
            child[new_node] = v;
            dq.push_back(new_node);
          }
        } else {
          dq.pop_back();
        }
      }

      dq.clear();

      if (found) {
        int i = 0;

        while (parent[i] != -1) {
          int u = parent[i];
          int v = child[i];
          match_v[v] = u;
          match_u[u] = v;
          i = u;
        }

        ++result;
      }
    }
  }

  cout << result;

  return 0;
}