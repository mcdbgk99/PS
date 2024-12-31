#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int a, b;
    cin >> a >> b;
    cout << a + b;
    if (i != t - 1) {
      cout << "\n";
    }
  }

  return 0;
}