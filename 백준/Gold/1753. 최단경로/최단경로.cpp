#include <bits/stdc++.h>
using namespace std;

vector<vector<tuple<int, int>>> graph;
vector<tuple<bool, int>> visited;
auto cmp = [](tuple<int, int>& left, tuple<int, int>& right) {
  return get<1>(left) > get<1>(right);
};
priority_queue<tuple<int, int>, vector<tuple<int, int>>, decltype(cmp)> pq;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, e, k;
  cin >> n >> e >> k;

  graph.resize(n + 1);
  visited.resize(n + 1, {false, -1});

  for (int i = 0; i < e; ++i) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
  }

  get<1>(visited[k]) = 0;
  pq.push({k, 0});

  while (!pq.empty()) {
    auto [now_num, now_cost] = pq.top();
    pq.pop();

    if (get<0>(visited[now_num])) {
      continue;
    }
    get<0>(visited[now_num]) = true;

    for (auto& [new_num, new_cost] : graph[now_num]) {
      if (get<1>(visited[new_num]) != -1 &&
          get<1>(visited[new_num]) < now_cost + new_cost) {
        continue;
      }

      get<1>(visited[new_num]) = now_cost + new_cost;
      pq.push({new_num, get<1>(visited[new_num])});
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (get<1>(visited[i]) != -1) {
      cout << get<1>(visited[i]) << "\n";
    } else {
      cout << "INF\n";
    }
  }

  return 0;
}