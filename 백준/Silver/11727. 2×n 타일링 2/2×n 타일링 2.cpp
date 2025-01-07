#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  v.resize(n + 1);
  v[0] = 1;
  v[1] = 1;

  for (int i = 2; i <= n; ++i) {
    v[i] = v[i - 2] * 2 + v[i - 1];
    v[i] %= 10007;
  }

  cout << v[n];

  return 0;
}