#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int r, c;
  cin >> r >> c;

  vector<string> v(r);

  for (int i = 0; i < r; ++i) {
    cin >> v[i];
  }

  int result = 0;

  constexpr array<int, 4> pattern_y = {-1, 1, 0, 0};
  constexpr array<int, 4> pattern_x = {0, 0, -1, 1};
  deque<tuple<int, int, bitset<26>>> dq;
  bitset<26> bs;
  bs[v[0][0] - 'A'] = 1;
  dq.push_back({0, 0, bs});

  while (!dq.empty()) {
    auto [now_y, now_x, mask] = dq.back();
    dq.pop_back();

    result = max<int>(result, mask.count());

    for (int i = 0; i < 4; ++i) {
      int new_y = now_y + pattern_y[i];
      int new_x = now_x + pattern_x[i];

      if (new_y < 0 || new_y >= r || new_x < 0 || new_x >= c) {
        continue;
      }

      if (mask[v[new_y][new_x] - 'A']) {
        continue;
      }

      mask[v[new_y][new_x] - 'A'] = 1;
      dq.push_back({new_y, new_x, mask});
      mask[v[new_y][new_x] - 'A'] = 0;
    }
  }

  cout << result;

  return 0;
}