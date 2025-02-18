#include <bits/stdc++.h>
using namespace std;

constexpr int64_t kInf = numeric_limits<int64_t>::max() / 2;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n, l, r;
  cin >> n >> l >> r;

  vector<int64_t> a(n);
  int64_t sum = 0;

  for (int64_t i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }

  if (n == 1) {
    cout << (sum >= l && sum <= r ? 0 : -1);
    return 0;
  }

  if (sum < n * l || sum > n * r) {
    cout << -1;
    return 0;
  }

  int64_t w = r - l;

  vector<int64_t> psum(n + 1, 0);
  for (int64_t i = 0; i < n; ++i) {
    psum[i + 1] = psum[i] + a[i];
  }

  vector<vector<int64_t>> dp(n * w + 1, vector<int64_t>(w + 1, kInf));
  dp[0][0] = 0;

  for (int64_t i = 0; i < n; ++i) {
    int64_t max_now = w * i, max_next = w * (i + 1);
    vector<vector<int64_t>> dp_next(max_next + 1, vector<int64_t>(w + 1, kInf));

    for (int64_t j = 0; j <= max_now; ++j) {
      for (int64_t k = 0; k <= w; ++k) {
        if (dp[j][k] == kInf) {
          continue;
        }

        for (int64_t x = k; x <= w; ++x) {
          int64_t new_sub = j + x;

          if (new_sub > max_next) {
            break;
          }

          int64_t cost = dp[j][k];

          if (i + 1 < n) {
            cost += abs(psum[i + 1] - (l * (i + 1) + new_sub));
          }

          dp_next[new_sub][x] = min(dp_next[new_sub][x], cost);
        }
      }
    }
    dp = dp_next;
  }

  int64_t result = kInf;
  for (int64_t v = 0; v <= w; v++) {
    result = min(result, dp[sum - l * n][v]);
  }
  cout << result;

  return 0;
}