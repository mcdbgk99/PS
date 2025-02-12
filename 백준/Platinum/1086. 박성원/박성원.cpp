#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<string> v(n);

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  int k;
  cin >> k;

  vector<int> normal_mod(n), ten_mod(n);

  for (int i = 0; i < n; ++i) {
    int x = 0;
    for (char c : v[i]) {
      x = (x * 10 + (c - '0')) % k;
    }
    normal_mod[i] = x;

    x = 1;
    for (int j = 0; j < v[i].size(); ++j) {
      x = (x * 10) % k;
    }
    ten_mod[i] = x;
  }

  int dp_max = 1 << n;
  vector<vector<int64_t>> dp(dp_max, vector<int64_t>(k, 0));
  dp[0][0] = 1;

  for (int m = 0; m < dp_max; ++m) {
    for (int i = 0; i < k; ++i) {
      if (dp[m][i] == 0) {
        continue;
      }

      for (int j = 0; j < n; ++j) {
        if (m & (1 << j)) {
          continue;
        }
        dp[m | (1 << j)][(i * ten_mod[j] + normal_mod[j]) % k] += dp[m][i];
      }
    }
  }

  int64_t valid = dp[dp_max - 1][0];
  int64_t factorial = 1;

  for (int i = 2; i <= n; ++i) {
    factorial *= i;
  }

  if (valid == 0) {
    cout << "0/1" << "\n";
  } else {
    int64_t g = gcd(valid, factorial);
    cout << (valid / g) << "/" << (factorial / g) << "\n";
  }

  return 0;
}