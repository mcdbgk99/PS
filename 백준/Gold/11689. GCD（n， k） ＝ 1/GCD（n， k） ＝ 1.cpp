// https://mathworld.wolfram.com/TotientFunction.html

#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n;
  cin >> n;

  int64_t result = n;

  for (int64_t p = 2; p * p <= n; ++p) {
    if (n % p == 0) {
      while (n % p == 0) {
        n /= p;
      }
      result -= result / p;
    }
  }

  if (n > 1) {
    result -= result / n;
  }

  cout << result;

  return 0;
}