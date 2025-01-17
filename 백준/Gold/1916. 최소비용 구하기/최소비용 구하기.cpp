#include <bits/stdc++.h>
using namespace std;

vector<vector<tuple<int, int>>> v;
vector<tuple<bool, int64_t>> visited;
auto cmp = [](tuple<int, int64_t>& left, tuple<int, int64_t>& right) {
  return get<1>(left) > get<1>(right);
};
priority_queue<tuple<int, int64_t>, vector<tuple<int, int64_t>>, decltype(cmp)>
    pq;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  v.resize(n + 1);
  visited.resize(n + 1, {false, INT64_MAX});

  for (int i = 0; i < m; ++i) {
    int left, right, cost;
    cin >> left >> right >> cost;
    v[left].push_back({right, cost});
  }

  int start, end;
  cin >> start >> end;

  get<1>(visited[start]) = 0;
  pq.push({start, 0});

  while (!pq.empty()) {
    auto [now_city, now_cost] = pq.top();
    pq.pop();

    if (get<0>(visited[now_city])) {
      continue;
    } else {
      get<0>(visited[now_city]) = true;
    }

    for (auto& t : v[now_city]) {
      int new_city = get<0>(t);
      int new_cost = get<1>(t);

      if (get<0>(visited[new_city])) {
        continue;
      }

      if (get<1>(visited[new_city]) <= get<1>(visited[now_city]) + new_cost) {
        continue;
      }

      get<1>(visited[new_city]) = get<1>(visited[now_city]) + new_cost;
      pq.push({new_city, get<1>(visited[new_city])});
    }
  }

  cout << get<1>(visited[end]);

  return 0;
}