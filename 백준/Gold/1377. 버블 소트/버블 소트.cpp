#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<tuple<int, int>> v(n);

  for (int i = 0; i < n; ++i) {
    cin >> get<0>(v[i]);
    get<1>(v[i]) = i;
  }

  sort(v.begin(), v.end());
  int result = 0;

  for (int i = 0; i < n; ++i) {
    result = max(result, get<1>(v[i]) - i);
  }

  cout << result + 1;

  return 0;
}