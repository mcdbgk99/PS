#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  v.resize(n);

  int result = 0;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i + 1; ++j) {
      int x;
      cin >> x;

      int add = 0;
      if (i != 0) {
        for (int k = max(0, j - 1); k <= min(j, i - 1); ++k) {
          add = max(add, v[i - 1][k]);
        }
      }
      v[i].push_back(x + add);

      if (i == n - 1) {
        result = max(result, x + add);
      }
    }
  }

  cout << result;

  return 0;
}