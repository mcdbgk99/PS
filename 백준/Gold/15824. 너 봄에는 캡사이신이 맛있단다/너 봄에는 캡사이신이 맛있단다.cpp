#include <bits/stdc++.h>
using namespace std;

constexpr int64_t kMod = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int64_t> v(n);

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  vector<int64_t> pow_table(n + 1, 0);
  pow_table[0] = 1;
  for (int i = 1; i <= n; ++i) {
    pow_table[i] = (pow_table[i - 1] << 1) % kMod;
  }

  int64_t result = 0;
  for (int i = 0; i < n; ++i) {
    int64_t add = (pow_table[i] - pow_table[n - 1 - i] + kMod) % kMod;
    result = (result + ((v[i] % kMod) * add) % kMod) % kMod;
  }

  cout << result;

  return 0;
}