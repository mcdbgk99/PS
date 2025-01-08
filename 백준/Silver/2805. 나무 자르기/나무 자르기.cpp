#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  v.resize(n);

  int highest = 0;
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    highest = max(highest, v[i]);
  }

  int result = 0;

  int left = 0;
  int right = highest;
  while (left <= right) {
    int mid = left + (right - left) / 2;

    int64_t count = 0;
    for (int i = 0; i < n; ++i) {
      count += max(v[i] - mid, 0);
    }

    if (count >= m) {
      result = max(result, mid);
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  cout << result;

  return 0;
}