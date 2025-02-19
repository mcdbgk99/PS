#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  i64 n, k;
  cin >> n >> k;

  i64 left = 0, right = n * n;

  while (left < right) {
    i64 mid = left + (right - left) / 2;
    i64 count = 0;

    for (i64 i = 1; i <= n; ++i) {
      count += min(n, mid / i);

      if (count >= k) {
        break;
      }
    }

    if (count < k) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }

  cout << left;

  return 0;
}