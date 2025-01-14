#include <bits/stdc++.h>
using namespace std;

vector<int> v;
queue<tuple<vector<int>, vector<bool>>> q;
set<vector<int>> result;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  v.resize(n);

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());
  vector<bool> temp(n, false);
  q.push({{}, temp});

  while (!q.empty()) {
    vector<int> now_v = get<0>(q.front());
    vector<bool> now_visited = get<1>(q.front());
    q.pop();

    if (now_v.size() == m) {
      result.insert(now_v);
      continue;
    }

    for (int i = 0; i < n; ++i) {
      if (now_visited[i]) {
        continue;
      }

      now_v.push_back(v[i]);
      now_visited[i] = true;
      q.push({now_v, now_visited});
      now_visited[i] = false;
      now_v.pop_back();
    }
  }

  for (auto& vv : result) {
    for (int i : vv) {
      cout << i << " ";
    }
    cout << "\n";
  }

  return 0;
}