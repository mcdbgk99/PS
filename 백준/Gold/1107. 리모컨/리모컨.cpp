#include <bits/stdc++.h>
using namespace std;

bitset<10> banned;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    banned.set(x);
  }

  int result = abs(100 - n);

  for (int i = 0; i < 10000000; ++i) {
    int temp = i;
    bool skip = false;
    int digits = 0;
    do {
      ++digits;

      if (banned[temp % 10]) {
        skip = true;
        break;
      }

      temp /= 10;
    } while (temp != 0);

    if (skip) {
      continue;
    }

    if (result > abs(i - n) + digits) {
      result = abs(i - n) + digits;
    }
  }

  cout << result;

  return 0;
}