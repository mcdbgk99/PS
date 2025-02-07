#include <bits/stdc++.h>
using namespace std;

constexpr int kMod = 10007;
constexpr int kRankMax = 13;
constexpr int kMax = kRankMax * 4;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<vector<int>> comb(kMax + 1, vector<int>(kMax + 1, 0));
  for (int i = 0; i <= kMax; ++i) {
    comb[i][0] = 1;
    comb[i][i] = 1;
    for (int j = 1; j < i; ++j) {
      comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % kMod;
    }
  }

  vector<vector<int>> dp(kRankMax + 1, vector<int>(n + 1, 0));
  dp[0][0] = 1;
  for (int i = 1; i <= kRankMax; ++i) {
    for (int j = 0; j <= n; ++j) {
      for (int k = 0; k < 4; ++k) {
        if (j - k < 0) {
          break;
        }
        dp[i][j] = (dp[i][j] + dp[i - 1][j - k] * comb[4][k]) % kMod;
      }
    }
  }

  int result = comb[kMax][n] - dp[kRankMax][n];
  result %= kMod;
  if (result < 0) {
    result += kMod;
  }

  cout << result;

  return 0;
}