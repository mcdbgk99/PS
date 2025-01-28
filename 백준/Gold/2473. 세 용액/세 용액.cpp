#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int64_t n;
  cin >> n;

  vector<int64_t> v(n);

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  int64_t min_sum = INT64_MAX;
  array<int64_t, 3> result = {-1, -1, -1};

  for (int i = 0; i < n - 2; ++i) {
    int left = i + 1;
    int right = n - 1;

    while (left < right) {
      int64_t sum = v[i] + v[left] + v[right];

      if (abs(sum) < min_sum) {
        min_sum = abs(sum);
        result = {v[i], v[left], v[right]};
      }

      if (sum > 0) {
        --right;
      } else {
        ++left;
      }
    }
  }

  cout << result[0] << " " << result[1] << " " << result[2];

  return 0;
}