#include <bits/stdc++.h>
using namespace std;

vector<int64_t> v(100 + 1, 1);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  v[4] = 2;
  v[5] = 2;
  for (int i = 6; i < v.size(); ++i) {
    v[i] = v[i - 5] + v[i - 1];
  }

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;
    cout << v[n] << "\n";
  }

  return 0;
}