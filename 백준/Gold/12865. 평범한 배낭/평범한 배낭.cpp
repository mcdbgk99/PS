#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  vector<vector<int>> dp(2, vector<int>(k + 1, 0));

  for (int i = 1; i <= n; ++i) {
    int weight, value;
    cin >> weight >> value;

    for (int j = 0; j <= k; ++j) {
      if (weight <= j) {
        dp[1][j] = max(dp[0][j], dp[0][j - weight] + value);
      } else {
        dp[1][j] = dp[0][j];
      }
    }

    dp[0] = dp[1];
  }

  cout << *max_element(dp[1].begin(), dp[1].end());

  return 0;
}