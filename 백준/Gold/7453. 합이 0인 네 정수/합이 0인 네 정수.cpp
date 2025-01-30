#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int16_t n;
  cin >> n;

  vector<int> a(n), b(n), c(n), d(n);

  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  }

  auto start = chrono::high_resolution_clock::now();

  vector<int> sum_cd;
  sum_cd.reserve(n * n);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      sum_cd.push_back(c[i] + d[j]);
    }
  }

  sort(sum_cd.begin(), sum_cd.end());

  int64_t result = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int ab = a[i] + b[j];
      auto [lower, upper] = equal_range(sum_cd.begin(), sum_cd.end(), -ab);
      result += upper - lower;
    }
  }

  cout << result;

  return 0;
}