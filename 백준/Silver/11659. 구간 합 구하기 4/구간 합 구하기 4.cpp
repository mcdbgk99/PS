#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;

  v.resize(n + 1);

  for (int i = 1; i <= n; ++i) {
    int n;
    cin >> n;
    v[i] = v[i - 1] + n;
  }

  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    cout << v[b] - v[a - 1] << "\n";
  }

  return 0;
}