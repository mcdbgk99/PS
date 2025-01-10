#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
vector<int> visited;
queue<tuple<int, int>> q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  v.resize(n + 1, vector<int>(n + 1));

  for (int x = 1; x <= n; ++x) {
    for (int y = 1; y <= n; ++y) {
      int a;
      cin >> a;
      v[x][y] = a;
    }
  }

  for (int x = 1; x <= n; ++x) {
    visited.assign(n + 1, 0);
    q.push({x, x});

    while (!q.empty()) {
      int now = get<0>(q.front());
      int origin = get<1>(q.front());
      q.pop();

      for (int y = 1; y <= n; ++y) {
        if (visited[y] != 0 || v[now][y] != 1) {
          continue;
        }

        v[origin][y] = 1;
        visited[y] = 1;
        q.push({y, origin});
      }
    }
  }

  for (int x = 1; x <= n; ++x) {
    for (int y = 1; y <= n; ++y) {
      cout << v[x][y] << " ";
    }
    cout << "\n";
  }

  return 0;
}