#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int result = 0;
  int64_t factorial = 1;
  for (int i = 2; i <= n; ++i) {
    factorial *= i;
    factorial %= 1000000;
    while (factorial % 10 == 0) {
      ++result;
      factorial /= 10;
    }
  }

  cout << result;

  return 0;
}