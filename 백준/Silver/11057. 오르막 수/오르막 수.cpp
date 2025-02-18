#include <bits/stdc++.h>
using namespace std;

constexpr int kMod = 10007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<int>> dp(n, vector<int>(10, 0));

  for (int i = 0; i < 10; ++i) {
    dp[0][i] = 1;
  }

  for (int i = 1; i < n; ++i) {
    for (int j = 0; j < 10; ++j) {
      if (j != 0) {
        dp[i][j] = (dp[i][j - 1] + dp[i - 1][j]) % kMod;
      } else {
        dp[i][j] = dp[i - 1][0];
      }
    }
  }

  int result = 0;

  for (int j = 0; j < 10; ++j) {
    result = (result + dp[n - 1][j]) % kMod;
  }

  cout << result;

  return 0;
}