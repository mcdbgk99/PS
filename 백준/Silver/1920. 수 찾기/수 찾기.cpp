#include <bits/stdc++.h>
using namespace std;

unordered_set<int> s;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    s.insert(x);
  }

  int m;
  cin >> m;

  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    if (s.find(x) != s.end()) {
      cout << "1\n";
    } else {
      cout << "0\n";
    }
  }

  return 0;
}