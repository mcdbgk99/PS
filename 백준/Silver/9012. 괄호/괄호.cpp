#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  string str;

  for (int i = 0; i < n; ++i) {
    str = "";
    cin >> str;

    bool valid = true;
    stack<char> s;
    for (char c : str) {
      switch (c) {
        case '(': {
          s.push('(');
        } break;

        case ')': {
          if (s.empty() || s.top() != '(') {
            valid = false;
            break;
          }
          s.pop();
        } break;

        case '[': {
          s.push('[');
        } break;

        case ']': {
          if (s.empty() || s.top() != '[') {
            valid = false;
            break;
          }
          s.pop();
        } break;
      }

      if (!valid) {
        break;
      }
    }

    cout << (valid && s.empty() ? "YES" : "NO") << "\n";
  }

  return 0;
}