#include <bits/stdc++.h>
using namespace std;

constexpr size_t kBoardSize = 14 * 14;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  auto dfs = [&n](int start_x) {
    int result = 0;
    deque<tuple<int, bitset<kBoardSize>>> dq;

    bitset<kBoardSize> bs;
    bs[start_x] = 1;

    int left = start_x - 1;
    int right = start_x + 1;
    for (int new_y = 1; new_y < n; ++new_y) {
      if (left >= 0) {
        bs[left + new_y * n] = 1;
        --left;
      }

      bs[start_x + new_y * n] = 1;

      if (right < n) {
        bs[right + new_y * n] = 1;
        ++right;
      }
    }

    dq.push_back({1, bs});

    while (!dq.empty()) {
      auto [now_y, now_board] = dq.back();
      dq.pop_back();

      if (now_y == n) {
        ++result;
        continue;
      }

      for (int queen = 0; queen < n; ++queen) {
        if (now_board[queen + now_y * n]) {
          continue;
        }

        bitset<kBoardSize> new_board = now_board;
        new_board[queen + now_y * n] = 1;

        left = queen - 1;
        right = queen + 1;
        for (int new_y = now_y + 1; new_y < n; ++new_y) {
          if (left >= 0) {
            new_board[left + new_y * n] = 1;
            --left;
          }

          new_board[queen + new_y * n] = 1;

          if (right < n) {
            new_board[right + new_y * n] = 1;
            ++right;
          }
        }

        dq.push_back({now_y + 1, new_board});
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