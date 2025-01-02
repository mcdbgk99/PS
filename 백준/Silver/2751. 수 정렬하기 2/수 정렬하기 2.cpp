#include <bits/stdc++.h>
using namespace std;

vector<bool> v(2000000 + 2, 0);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    v[x + 1000000] = true;
  }

  for (int i = 0; i < v.size(); ++i) {
    if (v[i]) {
      cout << i - 1000000 << "\n";
    }
  }

  return 0;
}