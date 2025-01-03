#include <bits/stdc++.h>
using namespace std;

stack<int> s;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    string str;
    cin >> str;

    switch (str[0]) {
      case 'p': {
        if (str[1] == 'u') {
          int x;
          cin >> x;
          s.push(x);
        } else {
          if (s.empty()) {
            cout << "-1\n";
          } else {
            cout << s.top() << "\n";
            s.pop();
          }
        }
      } break;

      case 's': {
        cout << s.size() << "\n";
      } break;

      case 'e': {
        cout << (s.empty() ? 1 : 0) << "\n";
      } break;

      case 't': {
        cout << (s.empty() ? -1 : s.top()) << "\n";
      } break;
    }
  }

  return 0;
}