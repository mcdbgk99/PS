#include <bits/stdc++.h>
using namespace std;

constexpr int64_t kMod = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n;
  cin >> n;

  string s;
  cin >> s;
  s = " " + s;

  vector<vector<int64_t>> dp(n + 2, vector<int64_t>(n + 2, 0));

  for (int i = 1; i <= n; ++i) {
    dp[i][i] = 1;
  }

  for (int i = 2; i <= n; ++i) {
    for (int j = 1; j <= n - i + 1; ++j) {
      int k = j + i - 1;

      if (s[j] == s[k]) {
        dp[j][k] = (dp[j + 1][k] + dp[j][k - 1] + 1) % kMod;
      } else {
        dp[j][k] =
            (dp[j + 1][k] + dp[j][k - 1] - dp[j + 1][k - 1] + kMod) % kMod;
      }
    }
  }

  string sub;
  sub.resize(n + 1);

  for (int i = 1; i <= n; ++i) {
    sub[i] = s[n - i + 1];
  }

  vector<vector<int64_t>> sub_dp(n + 1, vector<int64_t>(n + 1, 0));

  for (int i = 0; i <= n; ++i) {
    sub_dp[i][0] = 1;
    sub_dp[0][i] = 1;
  }

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (s[i] == sub[j]) {
        sub_dp[i][j] = (sub_dp[i - 1][j] + sub_dp[i][j - 1]) % kMod;
      } else {
        sub_dp[i][j] = (sub_dp[i - 1][j] + sub_dp[i][j - 1] -
                        sub_dp[i - 1][j - 1] + kMod) %
                       kMod;
      }
    }
  }

  vector<int64_t> cnt(n + 1, 0);

  for (int i = 1; i <= n; ++i) {
    int64_t sum = 0;

    int odd_x = i - 1;
    int odd_y = n - i;
    sum = sub_dp[odd_x][(odd_y < 0 ? 0 : odd_y)];

    for (int j = i + 1; j <= n; ++j) {
      if (s[j] == s[i]) {
        int even_x = i - 1;
        int even_y = n - j;
        int64_t in = 0;
        if (i + 1 <= j - 1) {
          in = dp[i + 1][j - 1];
        }
        in = (in + 1) % kMod;
        sum = (sum + (sub_dp[even_x][(even_y < 0 ? 0 : even_y)] * in) % kMod) %
              kMod;
      }
    }

    for (int j = 1; j < i; ++j) {
      if (s[j] == s[i]) {
        int even_x = j - 1;
        int even_y = n - i;
        int64_t in = 0;
        if (j + 1 <= i - 1) {
          in = dp[j + 1][i - 1];
        }
        in = (in + 1) % kMod;
        sum = (sum + (sub_dp[even_x][(even_y < 0 ? 0 : even_y)] * in) % kMod) %
              kMod;
      }
    }

    cnt[i] = sum % kMod;
  }

  int64_t result = 0;

  for (int64_t i = 1; i <= n; ++i) {
    int64_t power = (i * cnt[i]) % kMod;
    result ^= power;
  }

  cout << result << "\n";

  return 0;
}