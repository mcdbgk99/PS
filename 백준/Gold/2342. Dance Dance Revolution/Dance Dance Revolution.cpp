#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> v;
  v.reserve(100000);

  int x;
  while (cin >> x && x != 0) {
    v.push_back(x);
  }

  if (v.empty()) {
    cout << '0';
    return 0;
  }

  auto calculate_cost = [](int a, int b) {
    if (a == b) {
      return 1;
    }

    if (a == 0) {
      return 2;
    }

    if ((a + b) & 0x1) {
      return 3;
    }

    return 4;
  };

  array<array<int, 5>, 5> now_dp;
  array<array<int, 5>, 5> new_dp;
  for (int i = 0; i < 5; ++i) {
    now_dp[i].fill(INT32_MAX);
  }
  now_dp[0][0] = 0;

  for (int i : v) {
    for (int i = 0; i < 5; ++i) {
      new_dp[i].fill(INT32_MAX);
    }

    for (int left = 0; left < 5; ++left) {
      for (int right = 0; right < 5; ++right) {
        if (now_dp[left][right] == INT32_MAX) {
          continue;
        }

        if (left != i) {
          int cost = calculate_cost(right, i);
          if (new_dp[left][i] > now_dp[left][right] + cost) {
            new_dp[left][i] = now_dp[left][right] + cost;
          }
        }

        if (right != i) {
          int cost = calculate_cost(left, i);
          if (new_dp[i][right] > now_dp[left][right] + cost) {
            new_dp[i][right] = now_dp[left][right] + cost;
          }
        }
      }
    }

    swap(now_dp, new_dp);
  }

  int result = INT32_MAX;
  for (int i = 0; i < 5; ++i) {
    for (int j = 0; j < 5; ++j) {
      result = min(result, now_dp[i][j]);
    }
  }

  cout << result;

  return 0;
}