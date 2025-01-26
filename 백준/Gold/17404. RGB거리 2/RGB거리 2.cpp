#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<int>> v(n, vector<int>(3));
  for (int i = 0; i < n; ++i) {
    cin >> v[i][0] >> v[i][1] >> v[i][2];
  }

  auto calc_min_cost = [&v, n](int start_color) {
    vector<vector<int>> dp(n, vector<int>(3, INT32_MAX));
    dp[0][start_color] = v[0][start_color];

    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < 3; ++j) {
        int prev = INT32_MAX;

        for (int k = 0; k < 3; ++k) {
          if (j == k) {
            continue;
          }

          prev = min(prev, dp[i - 1][k]);
        }

        if (prev != INT32_MAX) {
          dp[i][j] = prev + v[i][j];
        }
      }
    }

    int result = INT32_MAX;
    for (int i = 0; i < 3; ++i) {
      if (i == start_color) {
        continue;
      }

      result = min(result, dp[n - 1][i]);
    }

    return result;
  };

  cout << min({calc_min_cost(0), calc_min_cost(1), calc_min_cost(2)});

  return 0;
}