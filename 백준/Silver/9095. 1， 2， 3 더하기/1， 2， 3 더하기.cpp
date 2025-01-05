#include <bits/stdc++.h>
using namespace std;

vector<int> v(10 + 1);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  v[1] = 1;
  v[2] = 2;
  v[3] = 4;
  for (int i = 4; i < v.size(); ++i) {
    v[i] = v[i - 3] + v[i - 2] + v[i - 1];
  }

  for (int i = 0; i < t; ++i) {
    int x;
    cin >> x;
    cout << v[x] << "\n";
  }

  return 0;
}