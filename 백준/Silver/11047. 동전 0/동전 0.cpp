#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;

  v.resize(n);

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }

  int result = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (k == 0) {
      break;
    }

    if (k / v[i] > 0) {
      result += k / v[i];
      k -= k / v[i] * v[i];
    }
  }

  cout << result;

  return 0;
}