#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, r, c;
  cin >> n >> r >> c;
  n = pow(2, n);

  int result = 0;
  while (n > 1) {
    n /= 2;

    int area = 0;

    if (r / n > 0) {
      r %= n;
      area += 2;
    }

    if (c / n > 0) {
      c %= n;
      area += 1;
    }

    result += n * n * area;
  }

  cout << result;

  return 0;
}