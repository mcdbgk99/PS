#include <bits/stdc++.h>
using namespace std;

constexpr int64_t kMod = 1000000007;

int64_t ModExp(int64_t b, int64_t e) {
  int64_t result = 1 % kMod;
  b %= kMod;

  while (e > 0) {
    if (e & 1) {
      result *= b;
      result %= kMod;
    }

    b *= b;
    b %= kMod;
    e >>= 1;
  }

  return result;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int64_t> fact(n + 1), fact_inv(n + 1);
  fact[0] = 1;
  for (int i = 1; i <= n; ++i) {
    fact[i] = (fact[i - 1] * i) % kMod;
  }

  fact_inv[n] = ModExp(fact[n], kMod - 2);
  for (int i = n; i >= 1; --i) {
    fact_inv[i - 1] = (fact_inv[i] * i) % kMod;
  }

  auto comb = [&fact, &fact_inv](int n, int k) -> int64_t {
    if (k < 0 || k > n) {
      return 0;
    }

    return (((fact[n] * fact_inv[k]) % kMod) * fact_inv[n - k]) % kMod;
  };

  int max_power = n + 1;
  int64_t inv_two = ModExp(2, kMod - 2);
  vector<int64_t> power(max_power + 1), power_inv(max_power + 1);

  power[0] = 1;
  for (int i = 1; i <= max_power; ++i) {
    power[i] = (power[i - 1] * 2) % kMod;
  }

  power_inv[0] = 1;
  for (int i = 1; i <= max_power; ++i) {
    power_inv[i] = (power_inv[i - 1] * inv_two) % kMod;
  }

  vector<int64_t> dp(n + 1, 0);
  dp[0] = 1;

  for (int m = 1; m <= n; ++m) {
    int64_t sum = 0;
    int64_t f = power[m - 1];
    for (int k = 1; k <= m; ++k) {
      int64_t t = f;
      t = (t * comb(m, k)) % kMod;
      t = (t * dp[m - k]) % kMod;
      t = (t * ((k % 2 == 1) ? 1 : (kMod - 1))) % kMod;
      sum = (sum + t) % kMod;

      if (k < m) {
        int exp_diff = m - k * 2 - 1;
        f = (f * (exp_diff >= 0 ? power[exp_diff] : power_inv[-exp_diff])) %
            kMod;
      }
    }

    dp[m] = sum;
  }

  cout << dp[n] % kMod;

  return 0;
}