#include <bits/stdc++.h>
using namespace std;

vector<int> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  v.resize(n + 1, 0);

  for (int i = 2; i < v.size(); ++i) {
    v[i] = v[i - 1] + 1;

    if (i % 2 == 0) {
      v[i] = min(v[i], v[i / 2] + 1);
    }

    if (i % 3 == 0) {
      v[i] = min(v[i], v[i / 3] + 1);
    }
  }

  cout << v[n];

  return 0;
}