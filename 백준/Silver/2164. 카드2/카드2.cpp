#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  uint32_t n;
  cin >> n;

  if ((n & (n - 1)) != 0) {
    uint32_t a = 1 << 31;
    for (int i = 0; i < 31; ++i) {
      if ((a & n) != 0) {
        n &= ~a;
        n <<= 1;
        break;
      }
      a >>= 1;
    }
  }

  cout << n;

  return 0;
}