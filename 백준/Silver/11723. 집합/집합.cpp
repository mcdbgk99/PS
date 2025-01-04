#include <bits/stdc++.h>
using namespace std;

unordered_set<int> v;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int m;
  cin >> m;

  for (int i = 0; i < m; ++i) {
    string str;
    cin >> str;

    switch (str[1]) {
      case 'd': {
        int x;
        cin >> x;
        v.insert(x);
      } break;

      case 'e': {
        int x;
        cin >> x;
        v.erase(x);
      } break;

      case 'h': {
        int x;
        cin >> x;
        cout << (v.find(x) != v.end() ? 1 : 0) << "\n";
      } break;

      case 'o': {
        int x;
        cin >> x;
        if (!v.insert(x).second) {
          v.erase(x);
        }
      } break;

      case 'l': {
        for (int x = 1; x <= 20; ++x) {
          v.insert(x);
        }
      } break;

      case 'm': {
        v.clear();
      } break;
    }
  }

  return 0;
}