#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<int> v(n);

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());

  set<vector<int>> result;
  queue<tuple<vector<int>, int>> q;
  q.push({{}, 0});

  while (!q.empty()) {
    auto [now_v, mask] = q.front();
    q.pop();

    if (now_v.size() == m) {
      result.insert(now_v);
      continue;
    }

    for (int i = 0; i < n; ++i) {
      if (mask & (1 << i)) {
        continue;
      }

      if (i > 0 && v[i] == v[i - 1] && !(mask & (1 << (i - 1)))) {
        continue;
      }

      vector<int> next_v = now_v;
      next_v.push_back(v[i]);
      q.push({next_v, mask | (1 << i)});
    }
  }

  for (auto& comb : result) {
    for (int i : comb) {
      cout << i << " ";
    }
    cout << "\n";
  }

  return 0;
}