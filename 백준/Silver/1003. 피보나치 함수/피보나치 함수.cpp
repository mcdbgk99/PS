#include <bits/stdc++.h>
using namespace std;

vector<int> v(40 + 1);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  v[0] = 1;
  v[1] = 1;
  for (int i = 2; i < v.size(); ++i) {
    v[i] = v[i - 2] + v[i - 1];
  }

  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;
    if (n == 0) {
      cout << "1 0\n";
    } else if (n == 1) {
      cout << "0 1\n";
    } else {
      cout << v[n - 2] << " " << v[n - 1] << "\n";
    }
  }

  return 0;
}