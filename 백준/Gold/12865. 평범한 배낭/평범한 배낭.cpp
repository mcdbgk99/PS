#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
  int result = 0;

  for (int i = 1; i <= n; ++i) {
    int weight, value;
    cin >> weight >> value;

    for (int j = 0; j <= k; ++j) {
      if (weight <= j) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight] + value);
        result = max(result, dp[i][j]);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }

  cout << result;

  return 0;
}