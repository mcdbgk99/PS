#include <bits/stdc++.h>
using namespace std;

vector<int> v;
vector<vector<int>> dp(2);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  v.resize(n);
  dp[0].resize(n);
  dp[1].resize(n);

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  dp[0][0] = v[0];
  dp[1][0] = v[0];
  dp[0][1] = v[1];
  dp[1][1] = dp[0][0] + v[1];
  for (int i = 2; i < n; ++i) {
    dp[0][i] = max(dp[0][i - 2], dp[1][i - 2]) + v[i];
    dp[1][i] = dp[0][i - 1] + v[i];
  }

  cout << max(dp[0][n - 1], dp[1][n - 1]);

  return 0;
}