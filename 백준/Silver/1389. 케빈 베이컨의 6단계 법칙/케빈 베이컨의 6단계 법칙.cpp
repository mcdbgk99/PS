#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
vector<int> steps;
queue<tuple<int, int>> q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  v.resize(n + 1);

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  int min_index = 0;
  int min_steps = INT32_MAX;

  for (int i = 1; i <= n; ++i) {
    steps.assign(n + 1, 0);
    q.push({i, 1});

    while (!q.empty()) {
      int now_index = get<0>(q.front());
      int now_step = get<1>(q.front());
      q.pop();

      for (int new_index : v[now_index]) {
        if (steps[new_index] != 0 && steps[new_index] <= now_step + 1) {
          continue;
        }

        steps[new_index] = now_step + 1;
        q.push({new_index, now_step + 1});
      }
    }

    int now_steps = accumulate(steps.begin(), steps.end(), 0);
    if (now_steps < min_steps) {
      min_index = i;
      min_steps = now_steps;
    }
  }

  cout << min_index;

  return 0;
}