#include <bits/stdc++.h>
using namespace std;

vector<int> v(10001, 0);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++v[x];
  }

  for (int i = 1; i <= 10000; ++i) {
    for (int j = 0; j < v[i]; ++j) {
      cout << i << "\n";
    }
  }

  return 0;
}