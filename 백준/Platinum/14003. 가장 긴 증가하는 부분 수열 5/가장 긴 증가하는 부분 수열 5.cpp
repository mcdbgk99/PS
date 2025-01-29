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

  vector<int> lis;
  vector<int> index(n);

  for (int i = 0; i < n; ++i) {
    if (lis.empty() || v[i] > lis.back()) {
      lis.push_back(v[i]);
      index[i] = lis.size() - 1;
    } else {
      auto it = lower_bound(lis.begin(), lis.end(), v[i]);
      *it = v[i];
      index[i] = it - lis.begin();
    }
  }

  vector<int> result;
  int len = lis.size() - 1;

  for (int i = n - 1; i >= 0; --i) {
    if (index[i] == len) {
      result.push_back(v[i]);
      --len;
    }
  }

  cout << lis.size() << "\n";
  reverse(result.begin(), result.end());
  for (int i : result) {
    cout << i << " ";
  }

  return 0;
}