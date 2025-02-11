#include <bits/stdc++.h>
using namespace std;

constexpr uint64_t kMod = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
  uniform_int_distribution<uint64_t> dist(0x10203040, 0x50607080);
  uint64_t hash_base = dist(gen);

  string t, p;
  getline(cin, t);
  getline(cin, p);
  int n = t.size(), m = p.size();

  vector<uint64_t> hash_prefix(n + 2, 0), hash_power(n + 2, 1);

  for (int i = 1; i <= n; ++i) {
    hash_power[i] = (hash_power[i - 1] * hash_base) % kMod;
    hash_prefix[i] = (hash_prefix[i - 1] * hash_base + t[i - 1]) % kMod;
  }

  uint64_t hash_p = 0;

  for (int i = 1; i <= m; ++i) {
    hash_p = (hash_p * hash_base + p[i - 1]) % kMod;
  }

  vector<int> result;

  for (int i = 1; i <= n - m + 1; ++i) {
    uint64_t hash = (kMod + hash_prefix[i + m - 1] -
                     hash_prefix[i - 1] * hash_power[m] % kMod) %
                    kMod;
    if (hash == hash_p) {
      result.push_back(i);
    }
  }

  cout << result.size() << "\n";
  for (auto i : result) {
    cout << i << " ";
  }

  return 0;
}