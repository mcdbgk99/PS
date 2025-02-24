#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> a(n), b(n), diff(n);
  i64 sum = 0;

  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i];
    sum += a[i] + b[i];
    diff[i] = a[i] - b[i];
  }

  sort(diff.begin(), diff.end());
  vector<i64> psum(n + 1, 0);

  for (int i = 0; i < n; ++i) {
    psum[i + 1] = psum[i] + diff[i];
  }

  i64 sum_diff = psum[n], pa = 0, pb = 0;
  int q;
  cin >> q;

  while (q--) {
    char c;
    int x;

    cin >> c >> x;

    if (c == 'A') {
      pa += x;
    } else {
      pb += x;
    }

    i64 y = pa - pb;
    auto it = lower_bound(diff.begin(), diff.end(), -y) - diff.begin();
    cout << (sum + n * (pa + pb) + (sum_diff - psum[it] * 2) +
             (n - it * 2) * y) /
                2
         << "\n";
  }

  return 0;
}