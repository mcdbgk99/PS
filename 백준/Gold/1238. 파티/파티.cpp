#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, x;
  cin >> n >> m >> x;

  vector<vector<tuple<int, int>>> v_forward(n + 1);
  vector<vector<tuple<int, int>>> v_reverse(n + 1);

  for (int i = 0; i < m; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    v_forward[a].push_back({b, c});
    v_reverse[b].push_back({a, c});
  }

  auto dijkstra = [&n](vector<vector<tuple<int, int>>>& v, int start) {
    vector<int> step(n + 1, INT32_MAX);
    auto cmp = [](tuple<int, int>& left, tuple<int, int>& right) {
      return get<1>(left) > get<1>(right);
    };
    priority_queue<tuple<int, int>, vector<tuple<int, int>>, decltype(cmp)> pq;
    step[start] = 0;
    pq.push({start, 0});

    while (!pq.empty()) {
      auto [now_node, now_step] = pq.top();
      pq.pop();

      if (now_step > step[now_node]) {
        continue;
      }

      for (auto& [new_node, new_step] : v[now_node]) {
        if (step[new_node] <= step[now_node] + new_step) {
          continue;
        }

        step[new_node] = step[now_node] + new_step;
        pq.push({new_node, step[new_node]});
      }
    }

    return step;
  };

  vector<int> home_to_party = dijkstra(v_reverse, x);
  vector<int> party_to_home = dijkstra(v_forward, x);

  int result = 0;
  for (int i = 1; i <= n; ++i) {
    if (i != x && home_to_party[i] != INT32_MAX &&
        party_to_home[i] != INT32_MAX) {
      result = max(result, home_to_party[i] + party_to_home[i]);
    }
  }

  cout << result;

  return 0;
}