#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
vector<int> visited;
deque<int> dq;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, start;
  cin >> n >> m >> start;

  v.resize(n + 1, vector<int>(n + 1, 0));

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    v[a][b] = 1;
    v[b][a] = 1;
  }

  visited.assign(n + 1, 0);
  dq.push_back(start);

  while (!dq.empty()) {
    int now = dq.back();
    dq.pop_back();

    if (visited[now] != 1) {
      cout << now << " ";
      visited[now] = 1;
    }

    for (int i = v[now].size() - 1; i >= 1; --i) {
      if (visited[i] == 1 || v[now][i] == 0) {
        continue;
      }

      dq.push_back(i);
    }
  }

  cout << "\n";

  visited.assign(n + 1, 0);
  visited[start] = 1;
  dq.push_back(start);

  while (!dq.empty()) {
    int now = dq.front();
    dq.pop_front();

    cout << now << " ";

    for (int i = 1; i < v[now].size(); ++i) {
      if (visited[i] == 1 || v[now][i] == 0) {
        continue;
      }

      visited[i] = 1;
      dq.push_back(i);
    }
  }

  return 0;
}