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

  unordered_map<int64_t, int> s_ab;
  s_ab.reserve(n * n);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ++s_ab[a[i] + b[j]];
    }
  }

  int64_t result = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      auto it = s_ab.find(0 - (c[i] + d[j]));
      if (it != s_ab.end()) {
        result += it->second;
      }
    }
  }

  cout << result;

  return 0;
}