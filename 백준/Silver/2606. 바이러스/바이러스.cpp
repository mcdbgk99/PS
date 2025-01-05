#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> v;
vector<bool> result;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int m, n;
  cin >> m >> n;

  v.resize(m + 1, vector<bool>(m + 1, false));
  result.resize(m + 1, false);

  for (int i = 0; i < n; ++i) {
    int a, b;
    cin >> a >> b;
    v[a][b] = true;
    v[b][a] = true;
  }

  queue<int> q;
  result[1] = true;
  q.push(1);

  while (!q.empty()) {
    int now = q.front();
    q.pop();

    for (int i = 1; i <= m; ++i) {
      if (result[i] || !v[now][i]) {
        continue;
      }

      result[i] = true;
      q.push(i);
    }
  }

  cout << count(result.begin(), result.end(), true) - 1;

  return 0;
}