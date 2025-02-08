#include <bits/stdc++.h>
using namespace std;

constexpr auto kTsumo = "Tsumo";
constexpr auto kRyuukyoku = "Ryuukyoku";

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, p, s, e;
  cin >> n >> p >> s >> e;

  vector<vector<tuple<int, char>>> graph(n + 1);

  for (int i = 1; i <= n; ++i) {
    graph[i].push_back({i == n ? 1 : i + 1, 1});
  }

  for (int i = 1; i <= n; ++i) {
    int m;
    cin >> m;
    for (int j = 0; j < m; ++j) {
      int l;
      cin >> l;
      graph[i].push_back({l, 0});
    }
  }

  vector<vector<bool>> visited(n + 1, vector<bool>(n, false));
  deque<tuple<int, int, char>> dq;

  visited[s][1 % n] = true;
  dq.push_back({s, 1, 1});

  while (!dq.empty()) {
    auto [now_node, now_cost, is_draw] = dq.front();
    dq.pop_front();

    if (now_cost > p) {
      continue;
    }

    if (now_node == e && is_draw && (p - now_cost) % n == 0) {
      cout << kTsumo;
      return 0;
    }

    for (auto [new_node, is_draw] : graph[now_node]) {
      int new_cost = now_cost + is_draw;
      int new_cost_mod = new_cost % n;

      if (new_cost > p) {
        continue;
      }

      if (visited[new_node][new_cost_mod]) {
        continue;
      }
      visited[new_node][new_cost_mod] = true;

      if (is_draw != 0) {
        dq.push_back({new_node, new_cost, is_draw});
      } else {
        dq.push_front({new_node, new_cost, is_draw});
      }
    }
  }

  cout << kRyuukyoku;

  return 0;
}