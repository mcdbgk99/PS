#include <bits/stdc++.h>
using namespace std;

set<vector<int>> s;
queue<vector<int>> q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  q.push({});

  while (!q.empty()) {
    vector<int> now = q.front();
    q.pop();

    if (now.size() == m) {
      sort(now.begin(), now.end());
      s.insert(now);
      continue;
    }

    for (int i = (now.empty() ? 1 : now[now.size() - 1]); i <= n; ++i) {
      now.push_back(i);
      q.push(now);
      now.pop_back();
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