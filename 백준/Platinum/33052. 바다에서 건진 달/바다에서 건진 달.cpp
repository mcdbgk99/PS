#include <bits/stdc++.h>
using namespace std;

constexpr int kMaxN = 5000;
constexpr auto kTsumo = "Tsumo";
constexpr auto kRyuukyoku = "Ryuukyoku";

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, p, s, e;
  cin >> n >> p >> s >> e;

  vector<vector<tuple<int16_t, char>>> graph(n + 1);

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

  vector<bitset<kMaxN>> visited(n + 1);
  deque<tuple<int16_t, int, char>> dq;

  visited[s][1 % n] = 1;
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
      visited[new_node][new_cost_mod] = 1;

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