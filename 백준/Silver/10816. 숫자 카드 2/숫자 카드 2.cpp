#include <bits/stdc++.h>
using namespace std;

vector<int> v(20000000 + 2, 0);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    ++v[x + 10000000];
  }

  int m;
  cin >> m;

  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    cout << v[x + 10000000] << " ";
  }

  return 0;
}