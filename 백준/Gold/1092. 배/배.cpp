#include <bits/stdc++.h>
using namespace std;

vector<int> crane;
vector<int> crane_work;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  crane.resize(n);
  crane_work.resize(n, 0);

  for (int i = 0; i < n; ++i) {
    cin >> crane[i];
  }

  sort(crane.begin(), crane.end());

  int m;
  cin >> m;

  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    auto it = lower_bound(crane.begin(), crane.end(), x);
    if (it == crane.end()) {
      cout << -1;
      return 0;
    }
    ++crane_work[it - crane.begin()];
  }

  int left = m / n;
  int right = m;

  while (left < right) {
    int mid = left + (right - left) / 2;

    bool solved = true;
    vector<int> temp = crane_work;
    int diff = 0;
    for (int i = 0; i < n; ++i) {
      int sum = temp[i] + diff;

      if (sum > mid) {
        diff = sum - mid;
        sum = mid;
      } else {
        diff = 0;
      }

      temp[i] = sum;

      if (i != n - 1) {
        temp[i + 1] += diff;
        diff = 0;
      } else {
        if (diff > 0) {
          solved = false;
        }
      }
    }

    if (solved) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }

  cout << left;

  return 0;
}