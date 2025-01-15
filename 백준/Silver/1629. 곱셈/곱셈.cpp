#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t a, b, c;
  cin >> a >> b >> c;

  int64_t temp = 1;

  while (b > 0) {
    if ((b & 0x1) != 0) {
      temp *= a;
      temp %= c;
    }

    a *= a;
    a %= c;
    b >>= 1;
  }

  cout << temp;

  return 0;
}