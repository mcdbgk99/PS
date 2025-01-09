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

    vector<int> nexts = {now + 1, now - 1, now * 2};
    for (int next : nexts) {
      if (next < 0 || next >= v.size()) {
        continue;
      }

      if (v[next] != 0 && v[next] <= v[now] + 1) {
        continue;
      }

      v[next] = v[now] + 1;
      q.push(next);
    }
  }

  cout << v[k] - 1;

  return 0;
}