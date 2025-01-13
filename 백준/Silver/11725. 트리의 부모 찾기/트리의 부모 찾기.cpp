#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
vector<bool> visited;
vector<int> result;
queue<int> q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  v.resize(n + 1);
  visited.resize(n + 1, false);
  result.resize(n + 1);

  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  visited[1] = true;
  q.push(1);

  while (!q.empty()) {
    int now = q.front();
    q.pop();

    for (int i : v[now]) {
      if (visited[i]) {
        continue;
      }

      visited[i] = true;
      result[i] = now;
      q.push(i);
    }
  }

  for (int i = 2; i < result.size(); ++i) {
    cout << result[i] << "\n";
  }

  return 0;
}