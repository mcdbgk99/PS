#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, x;
  cin >> n >> m >> x;

  vector<vector<tuple<int, int>>> v(n + 1);

  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    v[a].push_back({b, c});
  }

  vector<int> home_to_party(n + 1, -1);
  vector<int> party_to_home(n + 1, -1);

  for (int i = 1; i <= n; ++i) {
    vector<tuple<bool, int>> visited(n + 1, {false, -1});
    auto cmp = [](tuple<int, int>& left, tuple<int, int>& right) {
      return get<1>(left) > get<1>(right);
    };
    priority_queue<tuple<int, int>, vector<tuple<int, int>>, decltype(cmp)> pq;
    visited[i] = {false, 0};
    pq.push({i, 0});

    while (!pq.empty()) {
      auto [now_node, now_step] = pq.top();
      pq.pop();

      if (get<0>(visited[now_node])) {
        continue;
      }
      get<0>(visited[now_node]) = true;

      if (i != x && now_node == x) {
        home_to_party[i] = now_step;
      }

      if (i == x && now_node != x) {
        party_to_home[now_node] = now_step;
      }

      for (auto& [new_node, new_step] : v[now_node]) {
        if (get<1>(visited[new_node]) != -1 &&
            get<1>(visited[new_node]) < now_step + new_step) {
          continue;
        }

        get<1>(visited[new_node]) = now_step + new_step;
        pq.push({new_node, now_step + new_step});
      }
    }
  }

  int result = 0;
  for (int i = 1; i <= n; ++i) {
    result = max(result, home_to_party[i] + party_to_home[i]);
  }

  cout << result;

  return 0;
}