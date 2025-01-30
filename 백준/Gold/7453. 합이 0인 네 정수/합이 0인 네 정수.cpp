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

  unordered_map<int64_t, int> sum_ab;
  sum_ab.reserve(n * n);

  for (int i : a) {
    for (int j : b) {
      ++sum_ab[i + j];
    }
  }

  int64_t result = 0;

  for (int i : c) {
    for (int j : d) {
      auto it = sum_ab.find(-(i + j));
      if (it != sum_ab.end()) {
        result += it->second;
      }
    }
  }

  cout << result;

  return 0;
}