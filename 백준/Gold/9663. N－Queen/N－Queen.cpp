#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  auto dfs = [&n](int start_x) {
    int result = 0;
    deque<tuple<int, int, int, int>> dq;

    dq.push_back(
        {1, 1 << (start_x), 1 << (0 - start_x + n - 1), 1 << (0 + start_x)});

    while (!dq.empty()) {
      auto [now_y, mid, left, right] = dq.back();
      dq.pop_back();

      if (now_y == n) {
        ++result;
        continue;
      }

      for (int queen = 0; queen < n; ++queen) {
        if ((mid & (1 << (queen))) != 0 ||
            (left & (1 << (now_y - queen + n - 1))) != 0 ||
            (right & (1 << (now_y + queen))) != 0) {
          continue;
        }

        dq.push_back({now_y + 1, mid | (1 << queen),
                      left | (1 << (now_y - queen + n - 1)),
                      right | (1 << (now_y + queen))});
      }
    }

    return result;
  };

  int result = 0;

  for (int i = 0; i < n / 2; ++i) {
    result += dfs(i);
  }

  result *= 2;

  if (n % 2 != 0) {
    result += dfs(n / 2);
  }

  cout << result;

  return 0;
}