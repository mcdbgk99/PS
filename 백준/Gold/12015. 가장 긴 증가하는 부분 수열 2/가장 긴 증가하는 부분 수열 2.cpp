#include <bits/stdc++.h>
using namespace std;

vector<int> v(1);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n >> v[0];

  for (int i = 0; i < n - 1; ++i) {
    int x;
    cin >> x;

    if (x > v[v.size() - 1]) {
      v.push_back(x);
    } else {
      auto it = lower_bound(v.begin(), v.end(), x);
      *it = x;
    }
  }

  cout << v.size();

  return 0;
}