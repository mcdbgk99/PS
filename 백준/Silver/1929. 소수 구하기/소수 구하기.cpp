#include <bits/stdc++.h>
using namespace std;

vector<bool> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int m, n;
  cin >> m >> n;

  v.resize(n + 1, true);
  v[1] = false;

  for (int i = 2; i < v.size(); ++i) {
    if (!v[i]) {
      continue;
    }

    int temp = i * 2;
    while (temp < v.size()) {
      v[temp] = false;
      temp += i;
    }
  }

  for (int i = m; i <= n; ++i) {
    if (v[i]) {
      cout << i << "\n";
    }
  }

  return 0;
}