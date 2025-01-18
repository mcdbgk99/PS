#include <bits/stdc++.h>
using namespace std;

vector<vector<tuple<int, int>>> v;
vector<vector<int>> visited;
deque<tuple<int, int, int>> dq;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, e;
  cin >> n >> e;

  v.resize(n + 1);
  visited.resize(n + 1, vector<int>(4, -1));

  for (int i = 0; i < e; ++i) {
    int a, b, c;
    cin >> a >> b >> c;
    v[a].push_back({b, c});
    v[b].push_back({a, c});
  }

  int b1, b2;
  cin >> b1 >> b2;

  visited[1][0] = 0;
  int flag = (b1 == 1 ? 1 : 0) | (b2 == 1 ? 1 : 0);
  dq.push_back({1, 0, flag});

  while (!dq.empty()) {
    auto [now_num, now_step, now_flag] = dq.front();
    dq.pop_front();

    for (auto& [new_num, new_step] : v[now_num]) {
      int new_flag = now_flag;

      if (new_num == b1) {
        new_flag |= 1;
      }

      if (new_num == b2) {
        new_flag |= 2;
      }

      if (visited[new_num][new_flag] != -1 &&
          visited[new_num][new_flag] < now_step + new_step) {
        continue;
      }

      visited[new_num][new_flag] = now_step + new_step;
      dq.push_back({new_num, visited[new_num][new_flag], new_flag});
    }
  }

  cout << visited[n][3];

  return 0;
}