#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> m;
queue<int> q;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t a, b;
  cin >> a >> b;

  m[b] = 1;
  q.push(b);

  while (!q.empty()) {
    int now = q.front();
    q.pop();

    int64_t mul = now / 2;
    if (now % 2 == 0 && mul > 0 && (m[mul] == 0 || m[mul] > m[now])) {
      m[mul] = m[now] + 1;
      q.push(mul);
    }

    int64_t add = now / 10;
    if (now % 10 == 1 && add > 0 && (m[add] == 0 || m[add] > m[now])) {
      m[add] = m[now] + 1;
      q.push(add);
    }
  }

  cout << (m[a] != 0 ? m[a] : -1);

  return 0;
}