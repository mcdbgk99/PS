#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int> v(n);

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  array<int, 3> best = {INT32_MAX, -1, -1};
  int left = 0;
  int right = n - 1;

  while (left < right) {
    int sum = v[left] + v[right];

    if (abs(sum) < best[0]) {
      best = {abs(sum), left, right};
    }

    if (sum > 0) {
      --right;
    } else if (sum < 0) {
      ++left;
    } else {
      break;
    }
  }

  cout << v[best[1]] << " " << v[best[2]];

  return 0;
}