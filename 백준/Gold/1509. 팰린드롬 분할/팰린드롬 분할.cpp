#include <bits/stdc++.h>
using namespace std;

constexpr uint64_t kMod = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
  uniform_int_distribution<> dist(0x10203040, 0x60708090);
  uint64_t hash_base = dist(gen);

  string str;
  cin >> str;
  int n = str.size();

  vector<uint64_t> hash_prefix(n + 1, 0);
  vector<uint64_t> hash_suffix(n + 1, 0);
  vector<uint64_t> hash_power(n + 1, 1);

  for (int i = 1; i <= n; ++i) {
    hash_power[i] = (hash_power[i - 1] * hash_base) % kMod;
    hash_prefix[i] = (hash_prefix[i - 1] * hash_base + str[i - 1]) % kMod;
    hash_suffix[i] = (hash_suffix[i - 1] * hash_base + str[n - i]) % kMod;
  }

  auto is_palindrome = [n, &hash_power, &hash_prefix, &hash_suffix](
                           int s_forward, int e_forward) {
    int s_backward = n - e_forward + 1;
    int e_backward = n - s_forward + 1;
    int len = e_forward - s_forward + 1;

    uint64_t hash_forward =
        (kMod + hash_prefix[e_forward] -
         hash_prefix[s_forward - 1] * hash_power[len] % kMod) %
        kMod;

    uint64_t hash_backward =
        (kMod + hash_suffix[e_backward] -
         hash_suffix[s_backward - 1] * hash_power[len] % kMod) %
        kMod;

    return hash_forward == hash_backward;
  };

  vector<int> dp(n + 1, INT32_MAX);
  dp[0] = 0;

  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      if (is_palindrome(j, i)) {
        if (dp[j - 1] != INT32_MAX) {
          dp[i] = min(dp[i], dp[j - 1] + 1);
        }
      }
    }
  }

  cout << dp[n];

  return 0;
}