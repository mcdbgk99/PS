#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  int m;
  cin >> m;

  vector<tuple<int, int, int>> swaps;
  for (int i = 0; i < m; ++i) {
    int l, r, c;
    cin >> l >> r >> c;
    swaps.push_back({l - 1, r - 1, c});
  }

  vector<int> v_sorted = v;
  sort(v_sorted.begin(), v_sorted.end());

  int result = -1;
  priority_queue<tuple<int, vector<int>>, vector<tuple<int, vector<int>>>,
                 greater<>>
      pq;
  map<vector<int>, int> costs;

  pq.push({0, v});
  costs[v] = 0;

  while (!pq.empty()) {
    auto [now_cost, now_v] = pq.top();
    pq.pop();

    if (now_cost > costs[now_v]) {
      continue;
    }

    if (now_v == v_sorted) {
      result = now_cost;
      break;
    }

    for (auto [l, r, c] : swaps) {
      vector<int> new_v = now_v;
      swap(new_v[l], new_v[r]);

      int new_cost = now_cost + c;
      auto it = costs.find(new_v);

      if (it == costs.end() || new_cost < it->second) {
        costs[new_v] = new_cost;
        pq.push({new_cost, new_v});
      }
    }
  }

  cout << result;

  return 0;
}