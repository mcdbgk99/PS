#include <bits/stdc++.h>
using namespace std;

vector<int> v;
queue<int> q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  v.resize(max(n, k) + 3);

  v[n] = 1;
  q.push(n);

  while (!q.empty()) {
    int now = q.front();
    q.pop();

    vector<tuple<int, int>> nexts = {{now + 1, 1}, {now - 1, 1}, {now * 2, 0}};
    for (auto& next : nexts) {
      int next_index = get<0>(next);
      int next_distance = get<1>(next);
      if (next_index < 0 || next_index >= v.size()) {
        continue;
      }

      if (v[next_index] != 0 && v[next_index] <= v[now] + next_distance) {
        continue;
      }

      v[next_index] = v[now] + next_distance;
      q.push(next_index);
    }
  }

  cout << v[k] - 1;

  return 0;
}