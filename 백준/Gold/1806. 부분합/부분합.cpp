#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, s;
  cin >> n >> s;

  vector<int16_t> v(n);

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  int result = INT32_MAX;
  int sum = v[0];
  int left = 0;
  int right = 0;

  while (left < n && right < n) {
    if (sum < s) {
      ++right;
      sum += v[right];
    } else {
      result = min(result, right - left);
      sum -= v[left];
      ++left;
    }
  }

  if (result != INT32_MAX) {
    cout << result + 1;
  } else {
    cout << 0;
  }

  return 0;
}