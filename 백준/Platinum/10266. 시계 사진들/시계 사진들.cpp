#include <bits/stdc++.h>
using namespace std;

constexpr int64_t kMod = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
  uniform_int_distribution<uint64_t> dist(0x10203040, 0x50607080);
  int64_t hash_base = dist(gen);

  int n;
  cin >> n;

  vector<int> a(n), b(n);

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }

  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  vector<int> diff_a(n), diff_b(n);

  for (int i = 0; i < n - 1; ++i) {
    diff_a[i] = a[i + 1] - a[i];
    diff_b[i] = b[i + 1] - b[i];
  }

  diff_a[n - 1] = 360000 - a[n - 1] + a[0];
  diff_b[n - 1] = 360000 - b[n - 1] + b[0];

  vector<int> text(n * 2);
  for (int i = 0; i < n; ++i) {
    text[i] = diff_b[i];
    text[i + n] = diff_b[i];
  }

  int64_t hash_pattern = 0, hash_current = 0, hash_power = 1;

  for (int i = 0; i < n; ++i) {
    if (i < n - 1) {
      hash_power = (hash_power * hash_base) % kMod;
    }
    hash_pattern = (hash_pattern * hash_base + diff_a[i]) % kMod;
    hash_current = (hash_current * hash_base + text[i]) % kMod;
  }

  for (int i = 1; i <= n; ++i) {
    hash_current =
        (hash_current + kMod - (text[i - 1] * hash_power) % kMod) % kMod;
    hash_current = (hash_current * hash_base + text[i + n - 1]) % kMod;

    if (hash_current == hash_pattern) {
      cout << "possible";
      return 0;
    }
  }

  cout << "impossible";

  return 0;
}