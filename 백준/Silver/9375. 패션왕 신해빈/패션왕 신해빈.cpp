#include <bits/stdc++.h>
using namespace std;

map<string, int> m;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  for (int i = 0; i < t; ++i) {
    int n;
    cin >> n;

    for (int j = 0; j < n; ++j) {
      string name, type;
      cin >> name >> type;
      if (!m.insert({type, 1}).second) {
        ++m[type];
      }
    }

    int result = 1;
    for (auto& p : m) {
      result *= p.second + 1;
    }

    m.clear();
    cout << result - 1 << "\n";
  }

  return 0;
}