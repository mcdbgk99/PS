#include <bits/stdc++.h>
using namespace std;

constexpr auto kMakeCostTable() {
  array<array<int, 5>, 5> arr{};

  for (int a = 0; a < 5; ++a) {
    for (int b = 0; b < 5; ++b) {
      if (a == b) {
        arr[a][b] = 1;
      } else if (a == 0) {
        arr[a][b] = 2;
      } else if ((a + b) & 0x1) {
        arr[a][b] = 3;
      } else {
        arr[a][b] = 4;
      }
    }
  }

  return arr;
};
constexpr auto kCostTable = kMakeCostTable();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  array<array<int, 5>, 5> now_dp, new_dp;
  for (int i = 0; i < 5; ++i) {
    now_dp[i].fill(INT32_MAX);
  }
  now_dp[0][0] = 0;

  int x;
  while (cin >> x && x != 0) {
    for (int i = 0; i < 5; ++i) {
      new_dp[i].fill(INT32_MAX);
    }

    for (int left = 0; left < 5; ++left) {
      for (int right = 0; right < 5; ++right) {
        if (now_dp[left][right] == INT32_MAX) {
          continue;
        }

        if (left != x) {
          int cost = kCostTable[right][x];
          if (new_dp[left][x] > now_dp[left][right] + cost) {
            new_dp[left][x] = now_dp[left][right] + cost;
          }
        }

        if (right != x) {
          int cost = kCostTable[left][x];
          if (new_dp[x][right] > now_dp[left][right] + cost) {
            new_dp[x][right] = now_dp[left][right] + cost;
          }
        }
      }
    }

    swap(now_dp, new_dp);
  }

  cout << *min_element(&now_dp[0][0], &now_dp[0][0] + 25);

  return 0;
}