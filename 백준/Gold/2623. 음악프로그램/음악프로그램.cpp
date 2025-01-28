#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<unordered_set<int>> v(n + 1);
  vector<int> in_degree(n + 1, 0);

  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;

    vector<int> temp(x);

    for (int j = 0; j < x; ++j) {
      cin >> temp[j];
    }

    for (int j = 0; j < x - 1; ++j) {
      if (v[temp[j]].insert(temp[j + 1]).second) {
        ++in_degree[temp[j + 1]];
      }
    }
  }

  deque<int> dq;

  for (int i = 1; i <= n; ++i) {
    if (in_degree[i] == 0) {
      dq.push_back(i);
    }
  }

  vector<int> result;

  while (!dq.empty()) {
    int now_node = dq.front();
    dq.pop_front();

    result.push_back(now_node);

    for (int i : v[now_node]) {
      if (--in_degree[i] == 0) {
        dq.push_back(i);
      }
    }
  }

  if (result.size() != n) {
    cout << 0;
  } else {
    for (int i : result) {
      cout << i << "\n";
    }
  }

  return 0;
}