#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string str;

  while (true) {
    str = "";
    getline(cin, str);

    if (str[0] == '.') {
      break;
    }

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

    cout << (valid && s.empty() ? "yes" : "no") << "\n";
  }

  return 0;
}