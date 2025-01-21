#include <bits/stdc++.h>
using namespace std;

constexpr int kMod = 1000000007;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n;
  cin >> n;

  if (n == 0) {
    cout << 0;
    return 0;
  }

  bool found = false;
  bitset<64> bs(n);
  int64_t a = 0;
  int64_t b = 1;

  for (int i = 63; i >= 0; --i) {
    if (!found && !bs[i]) {
      continue;
    }

    int64_t even = a * ((2 * b - a + kMod) % kMod) % kMod;
    int64_t odd = (a * a % kMod + b * b % kMod) % kMod;

    if (bs[i]) {
      a = odd;
      b = (even + odd) % kMod;
    } else {
      a = even;
      b = odd;
    }

    found = true;
  }

  cout << a;

  return 0;
}