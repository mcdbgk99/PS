#include <bits/stdc++.h>
using namespace std;

vector<vector<tuple<int, int>>> v;
vector<int> visited;
queue<int> q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  v.resize(n + 1);

  for (int i = 0; i < n - 1; ++i) {
    int parent, child, cost;
    cin >> parent >> child >> cost;
    v[parent].push_back({child, cost});
    v[child].push_back({parent, cost});
  }

  auto bfs = [&](int start) -> tuple<int, int> {
    visited.assign(n + 1, -1);
    visited[start] = 0;
    q.push(start);
    int longest_node = -1;
    int longest_cost = 0;

    while (!q.empty()) {
      int now_node = q.front();
      int now_cost = visited[now_node];
      q.pop();

      if (longest_cost < now_cost) {
        longest_cost = now_cost;
        longest_node = now_node;
      }

      for (auto& [new_node, new_cost] : v[now_node]) {
        if (visited[new_node] != -1) {
          continue;
        }

        visited[new_node] = now_cost + new_cost;
        q.push(new_node);
      }
    }

    return {longest_node, longest_cost};
  };

  tuple<int, int> first = bfs(1);
  tuple<int, int> result = bfs(get<0>(first));

  cout << get<1>(result);

  return 0;
}