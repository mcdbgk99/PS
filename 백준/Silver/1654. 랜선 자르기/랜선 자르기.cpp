#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int k, n;
  cin >> k >> n;

  v.resize(k);

  int longest = 0;
  for (int i = 0; i < k; ++i) {
    cin >> v[i];
    longest = max(longest, v[i]);
  }

  int64_t left = 1;
  int64_t right = longest;
  int64_t result = 0;

  while (left <= right) {
    int64_t mid = left + (right - left) / 2;

    int64_t count = 0;
    for (int i = 0; i < k; ++i) {
      count += v[i] / mid;
    }

    if (count >= n) {
      result = max(result, mid);
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  cout << result;

  return 0;
}