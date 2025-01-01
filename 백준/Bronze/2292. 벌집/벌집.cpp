#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  if (n == 1) {
    cout << 1;
    return 0;
  }

  int a = (n - 2) / 6;
  int b = 1;
  while (a >= 0) {
    a -= b;
    ++b;
  }

  cout << b;

  return 0;
}