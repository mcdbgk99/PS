#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int64_t x, y;
    cin >> x >> y;

    int64_t d = abs(x - y);
    int64_t sqrt_d = static_cast<int64_t>(sqrt(d));
    int64_t sqr_d = sqrt_d * sqrt_d;
    int64_t result = 0;

    if (d <= sqr_d) {
      result = sqrt_d * 2 - 1;
    } else if (d <= sqr_d + sqrt_d) {
      result = sqrt_d * 2;
    } else {
      result = sqrt_d * 2 + 1;
    }

    cout << result << "\n";
  }

  return 0;
}