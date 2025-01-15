#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  v.resize(n + 1, vector<int>(3, 0));

  for (int i = 1; i <= n; ++i) {
    int a, b, c;
    cin >> a >> b >> c;

    v[i][0] = min(v[i - 1][1], v[i - 1][2]) + a;
    v[i][1] = min(v[i - 1][0], v[i - 1][2]) + b;
    v[i][2] = min(v[i - 1][0], v[i - 1][1]) + c;
  }

  cout << min({v[n][0], v[n][1], v[n][2]});

  return 0;
}