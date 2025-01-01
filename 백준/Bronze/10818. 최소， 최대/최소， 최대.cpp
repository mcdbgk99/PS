#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  int min_num = INT32_MAX;
  int max_num = INT32_MIN;

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;

    min_num = min(min_num, x);
    max_num = max(max_num, x);
  }

  cout << min_num << " " << max_num;

  return 0;
}