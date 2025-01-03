#include <bits/stdc++.h>
using namespace std;

queue<int> q;

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
          q.push(x);
        } else {
          if (q.empty()) {
            cout << "-1\n";
          } else {
            cout << q.front() << "\n";
            q.pop();
          }
        }
      } break;

      case 's': {
        cout << q.size() << "\n";
      } break;

      case 'e': {
        cout << (q.empty() ? 1 : 0) << "\n";
      } break;

      case 'f': {
        cout << (q.empty() ? -1 : q.front()) << "\n";
      } break;

      case 'b': {
        cout << (q.empty() ? -1 : q.back()) << "\n";
      } break;
    }
  }

  return 0;
}