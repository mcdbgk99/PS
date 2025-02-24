#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int x;
  cin >> x;

  for (int y = x + 1; y <= 9999; ++y) {
    int sum = y / 100 + y % 100;

    if (sum * sum == y) {
      cout << y;
      return 0;
    }
  }

  cout << "-1";

  return 0;
}