#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
vector<vector<int>> result;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;
    v.resize(n + 1, vector<int>(2));
    result.resize(n + 1, vector<int>(3));

    for (int y = 0; y < 2; ++y) {
      for (int x = 1; x <= n; ++x) {
        cin >> v[x][y];
      }
    }

    for (int x = 1; x <= n; ++x) {
      result[x][0] = max(result[x - 1][1], result[x - 1][2]);
      result[x][1] = max(result[x - 1][0], result[x - 1][2]) + v[x][0];
      result[x][2] = max(result[x - 1][0], result[x - 1][1]) + v[x][1];
    }

    cout << max({result[n][0], result[n][1], result[n][2]}) << "\n";
  }

  return 0;
}