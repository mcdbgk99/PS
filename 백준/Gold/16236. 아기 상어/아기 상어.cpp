#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<int>> v(n, vector<int>(n));
  array<int, 4> baby_shark = {0, 0, 2, 0};

  for (int y = 0; y < n; ++y) {
    for (int x = 0; x < n; ++x) {
      cin >> v[x][y];

      if (v[x][y] == 9) {
        baby_shark[0] = x;
        baby_shark[1] = y;
        v[x][y] = 0;
      }
    }
  }

  constexpr array<int, 4> pattern_x = {-1, 1, 0, 0};
  constexpr array<int, 4> pattern_y = {0, 0, -1, 1};
  int result = 0;

  while (true) {
    deque<tuple<int, int, int>> dq;
    vector<bitset<20>> visited(n, bitset<20>());
    vector<tuple<int, int, int>> target;

    visited[baby_shark[0]][baby_shark[1]] = 1;
    dq.push_back({baby_shark[0], baby_shark[1], 0});

    while (!dq.empty()) {
      auto [now_x, now_y, now_dist] = dq.front();
      dq.pop_front();

      if (v[now_x][now_y] > 0 && v[now_x][now_y] < baby_shark[2]) {
        target.push_back({now_x, now_y, now_dist});
        continue;
      }

      for (int i = 0; i < 4; ++i) {
        int new_x = now_x + pattern_x[i];
        int new_y = now_y + pattern_y[i];

        if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= n) {
          continue;
        }

        if (visited[new_x][new_y]) {
          continue;
        }

        if (v[new_x][new_y] > baby_shark[2]) {
          continue;
        }

        visited[new_x][new_y] = 1;
        dq.push_back({new_x, new_y, now_dist + 1});
      }
    }

    if (target.empty()) {
      break;
    }

    sort(target.begin(), target.end(),
         [](tuple<int, int, int>& left, tuple<int, int, int>& right) {
           if (get<2>(left) != get<2>(right)) {
             return get<2>(left) < get<2>(right);
           }

           if (get<1>(left) != get<1>(right)) {
             return get<1>(left) < get<1>(right);
           }

           return get<0>(left) < get<0>(right);
         });

    baby_shark[0] = get<0>(target.front());
    baby_shark[1] = get<1>(target.front());
    result += get<2>(target.front());
    ++baby_shark[3];
    v[get<0>(target.front())][get<1>(target.front())] = 0;

    if (baby_shark[2] == baby_shark[3]) {
      ++baby_shark[2];
      baby_shark[3] = 0;
    }
  }

  cout << result;

  return 0;
}