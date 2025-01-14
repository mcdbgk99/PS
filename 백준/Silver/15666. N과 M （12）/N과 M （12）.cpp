#include <bits/stdc++.h>
using namespace std;

vector<int> v;
set<vector<int>> s;
queue<tuple<vector<int>, int>> q;

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
  q.push({{}, 0});

  while (!q.empty()) {
    vector<int> now_v = get<0>(q.front());
    int now_n = get<1>(q.front());
    q.pop();

    if (now_v.size() == m) {
      sort(now_v.begin(), now_v.end());
      s.insert(now_v);
      continue;
    }

    for (int i = now_n; i < n; ++i) {
      now_v.push_back(v[i]);
      q.push({now_v, i});
      now_v.pop_back();
    }
  }

  for (auto& result : s) {
    for (int i : result) {
      cout << i << " ";
    }
    cout << "\n";
  }

  return 0;
}