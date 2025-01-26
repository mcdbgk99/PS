#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int> costs(n + 1);
    vector<vector<int>> nodes(n + 1, vector<int>());

    for (int i = 1; i <= n; ++i) {
      cin >> costs[i];
    }

    for (int i = 0; i < k; ++i) {
      int x, y;
      cin >> x >> y;
      nodes[y].push_back(x);
    }

    int w;
    cin >> w;

    vector<int> dp(n + 1, -1);
    deque<tuple<int, bool>> dq;

    dq.push_back({w, false});

    while (!dq.empty()) {
      auto [now_node, now_built] = dq.back();
      dq.pop_back();

      if (now_built) {
        int max_cost = 0;
        for (int new_node : nodes[now_node]) {
          max_cost = max(max_cost, dp[new_node]);
        }
        dp[now_node] = max_cost + costs[now_node];
      } else {
        if (dp[now_node] != -1) {
          continue;
        }

        dq.push_back({now_node, true});
        for (int i = nodes[now_node].size() - 1; i >= 0; --i) {
          dq.push_back({nodes[now_node][i], false});
        }
      }
    }

    cout << dp[w] << "\n";
  }

  return 0;
}