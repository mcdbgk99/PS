#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  v.resize(n + 1);
  v[0] = 0;

  for (int i = 1; i <= n; ++i) {
    cin >> v[i];
  }

  sort(v.begin(), v.end());

  for (int i = 1; i <= n; ++i) {
    v[i] += v[i - 1];
  }

  cout << accumulate(v.begin(), v.end(), 0);

  return 0;
}