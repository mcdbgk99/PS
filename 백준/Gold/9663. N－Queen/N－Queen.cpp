#include <bits/stdc++.h>
using namespace std;

deque<tuple<int, vector<bitset<15>>>> dq;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int result = 0;
  dq.push_back({0, vector<bitset<15>>(n)});

  while (!dq.empty()) {
    auto [now_y, now_board] = dq.back();
    dq.pop_back();

    if (now_y == n) {
      ++result;
      continue;
    }

    for (int queen = 0; queen < n; ++queen) {
      if (now_board[queen][now_y]) {
        continue;
      }

      vector<bitset<15>> new_board = now_board;
      new_board[queen][now_y] = 1;

      int left = queen - 1;
      int right = queen + 1;
      for (int new_y = now_y + 1; new_y < n; ++new_y) {
        if (left >= 0) {
          new_board[left][new_y] = 1;
          --left;
        }

        new_board[queen][new_y] = 1;

        if (right < n) {
          new_board[right][new_y] = 1;
          ++right;
        }
      }

      dq.push_back({now_y + 1, new_board});
    }
  }

  cout << result;

  return 0;
}