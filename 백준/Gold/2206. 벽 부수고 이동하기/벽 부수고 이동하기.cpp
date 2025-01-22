#include <bits/stdc++.h>
using namespace std;

struct Node {
  short y;
  short x;
  bool breached;
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  vector<char> v(n * m);

  for (int i = 0; i < n; ++i) {
    string str;
    cin >> str;
    memcpy(&v[i * m], str.data(), m);
  }

  deque<Node> dq;
  array<int, 4> pattern_y = {-1, 1, 0, 0};
  array<int, 4> pattern_x = {0, 0, -1, 1};
  vector<int> visited(n * m * 2, -1);

  visited[0] = 1;
  dq.push_back({0, 0, false});

  while (!dq.empty()) {
    Node now = dq.front();
    int now_index = (now.y * m + now.x) * 2 + now.breached;
    dq.pop_front();

    for (int i = 0; i < 4; ++i) {
      int new_y = now.y + pattern_y[i];
      int new_x = now.x + pattern_x[i];

      if (new_y < 0 || new_y >= n || new_x < 0 || new_x >= m) {
        continue;
      }

      bool need_breach = v[new_y * m + new_x] == '1';
      bool new_breached = now.breached;

      if (need_breach) {
        if (now.breached) {
          continue;
        }
        new_breached = true;
      }

      int new_index = (new_y * m + new_x) * 2 + new_breached;

      if (visited[new_index] != -1) {
        continue;
      }

      visited[new_index] = visited[now_index] + 1;
      dq.push_back(
          {static_cast<short>(new_y), static_cast<short>(new_x), new_breached});
    }
  }

  int dest_index = ((n - 1) * m + (m - 1)) * 2;
  cout << static_cast<int>(
      min<uint32_t>(visited[dest_index], visited[dest_index + 1]));

  return 0;
}