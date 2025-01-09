#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  v.resize(t);

  for (int i = 0; i < t; ++i) {
    int m, n, x, y;
    cin >> m >> n >> x >> y;

    int result = -1;
    int a = x, b = y;

    while (a <= lcm(m, n) && b <= lcm(m, n)) {
      if (a == b) {
        result = a;
        break;
      }

      if (a < b) {
        a += m;
      } else {
        b += n;
      }
    }

    cout << result << "\n";
  }

  return 0;
}